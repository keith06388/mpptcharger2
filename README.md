# Backpacking MPPT Solar Charger Version 2
Solar charger designed to charge lithium ion cells directly, bypassing USB charging circuit.  

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_105105.jpg)


## Features

Advantages of this design:
* Very high efficiency buck converter
* Full MPPT tracking using BQ25622e chip (upgraded from BQ24650)
* Integrated power meter, source voltage, battery voltage, and battery charge indicator
* Passthrough charging to charge device and battery simultaneously
* Integrated battery attachment for simple attachment to pack while hiking
* Automatically adjustable to different panel voltages (3.8-18V)
* Avoid 2 stage voltage drop to cells for higher total efficiency (solar -> battery vs solar -> USB -> battery)
* Magnetic battery contacts designed to avoid reverse polarity connection
* Compatibility with both Nitecore NL2150RX and Vapcell P2150A
* Easy connection for software updates

## PCB
* Designed with easyeda software
*   Project link: https://u.easyeda.com/keith06388/solar-mppt-charger-v4
* PCBA assembled by JLCPCB
* Primary components:
  * BQ25622e - mppt solar battery charging chip
  * ATTINY1616 - arduino compatible microcontroller
  * 3.8-18V input voltage range
  * Up to 3.0A charging current
  * 10hz MMPT update rate
  * 40mV MPPT voltage resolution
  * Up to 95% conversion efficiency
* Connections:
  * S+/S- Solar input
  * B+/B- Battery output
  * UPDI Programming port
  * LCD 0.42" SSD1306 display

## 3D Printed Parts
* Housing (printed with JLCPCB in nylon)
* Positive and negative battery contacts (printed with PETG)
*   Printing of the positive contact was paused to allow installation of the magnet into the housing before lip printed

## Purchased Parts
* Magnets from K&J (D42AH and D62SH)
  * High temperature magnets to allow soldering without demagnetization
* Sn42Bi58 solder for attaching wire to magnets at low temperature
* 20AWG silicone flexible wire (red and black)
* 0.49" SSD1306 OLED
* 28.2mmx33mmx2.4mm 50D silicone o-ring
* 1mm rubber grip tape to prevent battery from sliding
* Short piece of flat wire (used for programming after assembly)
* Custom solar panel using sunpower solar cells

* ## Custom Panel Parts
* Knurl pins (1.2mm x 20mm) https://www.amazon.com/dp/B0BC1VN8J9
* Solar cells sunpower Gen 3 (small) or Gen 5 (large)
  * Small cells can be ordered cut into 3 sections, but I haven't found a source for cut large cell, but they can be cut with a fiber laser or potentially a razor or dremel
  * https://www.aliexpress.us/item/3256801658021801.html
  * https://www.aliexpress.us/item/3256805555889765.html
* Laminator sheets (5mil works well, but 3mil should work too)
* 0.2mm carbon fiber sheet for back side.  This could be substituted with plastic sheet to cut cost.  https://www.aliexpress.us/item/3256805950798977.html
* Pressure sensitive adhesive to attach laminated solar cells and foam/frame and also rear carbon fiber sheet to foam/frame
* Solar busbar and flux (I used 2x 1mm x 0.2mm busbars for each connection)
* 3mm architectural foam
* Magnets from K&J (2x B631-N52 for magnetic closure)
* PETG filament for frame.  I printed the frame with 0.8mm lateral walls and approximately 0.6mm top and bottom thickness with 20% grid infill.  I made the hinge areas 100% infill using a box in prusa slicer
  * Large panel CAD (approx 13W): https://a360.co/3wPAMOi
  * Small panel CAD (approx 10W): https://a360.co/4cJ9c5N

## Assembly
Testing of the performance was completed by building a custom panel, however, this module could be used to replace the charge module on a panel such as the lixada solar panel available on amazon

Installation steps for Lixada panel:
* Carefully remove solar to USB module from panel using a razor blade to cut adhesive under module and a soldering iron to desolder leads from panel
* Scrape any remaining adhesive off and clean with alcohol
* Solder new assembled pcb with housing and leads to panel
* Use epoxy to glue housing to panel

## Software Install or Upgrade
* UPDI programming can be performed with a cheap CH340 board and a Schottky diode installed across the TX and RX pins (with diode facing TX pin)
* Programming requires a power supply (either benchtop or solar) and UPDI programmer with connections to ground and the UPDI programming pin
* Before programming for the first time, the "megaTinyCore" board needs to be installed in Arduino and the bootloader should be burned (see image below for bootloader and programming settings, the COM port will need to be selected for your programmer port)
![image](https://github.com/user-attachments/assets/0476ff46-d9d1-430e-9e03-7a6043f74d62)
![image](https://github.com/user-attachments/assets/cb4acfae-8f27-4e84-902c-ca35da2bdcf4) ![image](https://github.com/user-attachments/assets/3185221e-8c06-43c4-b314-42ded2426048) ![image](https://github.com/user-attachments/assets/0e5e8512-aab5-45c6-a3fd-3f1f34c49393)

* Once the bootloader is burned, the software can be installed.  The software is found in this repository and the following libraries need to be installed:
  * Tiny4KOLED - installed through Arduino library manager
  * BQ25622 - installed manually by downloading the .zip archive from github and installing by Sketch -> Include Library -> Add .Zip Library  The library is located here: https://github.com/keith06388/PMIC_BQ25622
  * With the programmer correctly connected (GND to battery or solar ground, and UPDI in contact with UPDI pin, the software can be installed using Sketch -> Upload using programmer
* Latest software notes:
  * Resolved issue with charger locking up after low voltage shutdown (but not completely dropped to 0V).  Screen now shuts off after dropping below 4.5V and turns back on above 5.0V
  * Slight increase in efficiency by forcing Mosfet 1 and 4 always in low resistance state
  * Resolved issue for OLED display when power is above 10W


![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_105228.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104936.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104617.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104551.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104542.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_103334.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_101226.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_094351.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_074910.jpg)
