#include <Tiny4kOLED.h>
#include "spleen.h"
#include "batt.h"
#include <PMIC_BQ25622.h>


uint8_t i = 0;
uint8_t lvl = 0;
uint8_t bar = 0;
uint8_t n = 0;
uint8_t m = 0;
uint16_t vindpm = 5000;
uint16_t vs = 0;
uint16_t vb = 0;
uint16_t v0 = 0;
int16_t ic = 0;
uint16_t p = 0;
int dp = 0;
int dv = 0;
uint16_t p0 = 0;
int16_t il = 3200;
bool oledon = 0;
PMIC_BQ25622 bq25622;


void setup() {
  //Turn off screen
  digitalWrite(PIN_PA4,LOW);
  delay(50);
  //Initialize I2C
  Wire.begin();
  Wire.setClock(100000);
  bq25622.begin();
  //Turn on screen and initialize
  digitalWrite(PIN_PA4,HIGH);
  oled.begin(72, 40, sizeof(tiny4koled_init_72x40br), tiny4koled_init_72x40br);
  oled.off();
  oledon = 0;
  oled.clear();
  //Initialize BQ25622e
  bq25622.reset(); //reset all registers to default
  bq25622.setWATCHDOG(0);
  bq25622.setEN_EXTLIM(false); //disable hardware ilim pin
  bq25622.setCONV_RATE(true); //set continous adc 1s read
  bq25622.setADC_SAMPLE(1); //read adc in one shot (default)
  bq25622.setCONV_START(true); //read adc in one shot (default)
  bq25622.setQ1_FULLON(1); //Q1 low impedance
  bq25622.setQ4_FULLON(1); //Q4 low impedance
  bq25622.setTS_IGNORE(true);
  bq25622.setVPMID_ADC_DIS(true);
  bq25622.setTDIE_ADC_DIS(true);
  bq25622.setTS_ADC_DIS(true);
  bq25622.setVSYS_ADC_DIS(true);
  bq25622.setIBUS_ADC_DIS(true);
  bq25622.setVBUS_ADC_DIS(false);
  bq25622.setVBAT_ADC_DIS(false);
  bq25622.setIBAT_ADC_DIS(false);
  bq25622.setITERM(100);
  bq25622.setVREG(4200);
  bq25622.setVINDPM(vindpm);
  bq25622.setCONV_FREQ(2);
  bq25622.setCONV_STRN(3);
  bq25622.setEN_CHG(1);
  bq25622.setICHG(3040);
}

void loop() {
  for (n = 0; n < 4; n++) {
    for (m = 0; m < 4; m++) {
      // Start ADC conversion
      bq25622.setCONV_START(true);
      delay(36);

      // Read voltage & current values
      vs = bq25622.getVBUSV();  
      vb = bq25622.getBATV();
      ic = bq25622.getIBAT();  

      // Turn off OLED if power too low
      if ((vs < 4500) && (oledon == 1)) {
        oled.off();
        oledon = 0;
      }
      else if ((vs >= 5000) && (oledon == 0)) {
        oled.on();
        oledon = 1;
        oled.clear();
      }

      // Compute power (P = V * I)
      p = vb * (ic / 1000.0);  // Convert mA to A
      dp = p - p0;
      p0 = p;
      dv = vindpm - v0;
      v0 = vindpm;

      // Apply Perturb and Observe MPPT algorithm
      if (abs(dp) > 100 || abs(dv) > 100) {  
        if (dp > 0) {
          vindpm += (dv < 0) ? -40 : 40;
          // if (il < 3200) {
          //   il += 100;
          //   bq25622.setIINDPM(il);
          // } 
        } else {
          vindpm += (dv < 0) ? 40 : -40;
          // if (il < 3200) {
          //   il += 100;
          //   bq25622.setIINDPM(il);
          // } 
        }
      } else {
        if (p >= 100 && dv > 0) {
          vindpm += 40;
          // if (il < 3200) {
          //   il += 100;
          //   bq25622.setIINDPM(il);
          // } 
        } else if (p < 100) {
          vindpm = 5000;
          // il = 100;
          // bq25622.setIINDPM(il);
        }
      }

      // Ensure vindpm stays within safe limits
      if (vindpm < 5000) vindpm = 5000;
      //if (vindpm > vs - 50) vindpm = vs - 50;

      // Apply the new voltage limit
      if (vindpm != v0) {
        bq25622.setVINDPM(vindpm);
        delay(30);
      }
    }

    // Update battery charge level display
    int level = meter(vb, ic);
    if (ic > 20) bar = level - i;
    else if (ic <= 0 && vb < 3300) bar = 0;
    else bar = level;

    // Update OLED display
    updateoled(p, bar, vs, vb);

    m = 0;
  }
  n = 0;
  i = (i == 0) ? 1 : 0;  // Toggle `i` between 0 and 1 to flash charging icon, while charging
}

//Print output to screen
void updateoled(uint16_t u, uint8_t x, uint16_t y, uint16_t z){
  oled.setFont(FONTspleen);
  oled.setCursor(0,0); 
  //For > 10W, only use 1 decimal place to fit screen
  if (p >= 10000) {
    oled.print(u/1000.0,1);
  }
  else {
    oled.print(u/1000.0,2);
  }
  oled.setCursor(42,0); 
  oled.print("/");
  oled.setCursor(56,0);
  oled.setFont(FONTbatt);
  oled.print(x);
  oled.setFont(FONT6X8);
  oled.setCursor(0,3);
  oled.print(y/1000.0,2);
  oled.print(" VSOL");
  oled.setCursor(0,4);
  oled.print(z/1000.0,2);
  oled.print(" VBAT");
}


//Approximate power bar calibrations for Vapcell p2150a cell
int meter(float v, float a){
  int lvl;
  if (a>2000){
    if (v<3600) lvl = 1;
    else if (v<3830) lvl = 2;
    else if (v<4050) lvl = 3;
    else if (v<4190) lvl = 4;
    else lvl = 5;
  }
  else if (a>1000){
    if (v<3600) lvl = 1;
    else if (v<3800) lvl = 2;
    else if (v<3950) lvl = 3;
    else if (v<4160) lvl = 4;
    else lvl = 5;
  }
    else if (a>500){
    if (v<3600) lvl = 1;
    else if (v<3720) lvl = 2;
    else if (v<3900) lvl = 3;
    else if (v<4120) lvl = 4;
    else lvl = 5;
  }
    else {
    if (v<3470) lvl = 1;
    else if (v<3630) lvl = 2;
    else if (v<3800) lvl = 3;
    else if (v<4000) lvl = 4;
    else lvl = 5;
  }
  return lvl;

}