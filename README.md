# Backpacking MPPT Solar Charger Version 2
Solar charger designed to charge lithium ion cells directly, bypassing USB charging circuit.  

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_105105.jpg)


## Features

Advantages of this design:
* Very high efficiecy buck converter
* Full MPPT tracking using BQ25622e chip (upgraded from BQ24650)
* Intergrated power meter, source volatage, battery voltage, and battery charge indicator
* Passthrough charging to charge device and battery simultaneously
* Integrated battery attachment for simple attachment to pack while hiking
* Automatically adjustable to different panel voltages (3.8-18V)
* Avoid 2 stage voltage drop to cells for higher total efficiency (solar -> battery vs solar -> USB -> battery)
* Magnetic battery contacts designed to avoid reverse polarity connection
* Compatability with both Nitecore NL2150RX and Vapcell P2150A
* Easy connection for software updates

## PCB
* Designed with easyeda software
*   Project link: https://u.easyeda.com/keith06388/solar-mppt-charger-v4
* PCBA assembled by JLCPCB
* Primary components:
*   BQ25622e - mppt solar battery charging chip
*   ATTINY1616 - arduino compatable microcontroller
*   3.8-18V input voltage range
*   Up to 3.0A charging current
*   10hz MMPT update rate
*   40mV MPPT voltage resolution
*   Up to 95% conversion efficiency
* Connections:
*   S+/S- Solar input
*   B+/B- Battery output
*   UPDI Programming port
*   LCD 0.42" SSD1306 display

## 3D Printed Parts
* Housing (printed with JLCPCB in nylon)
* Positve and negative battery contacts (printed with PETG)
*   Printing of the positive contact was paused to allow installation of the magnet into the housing before lip printed

## Purchased Parts
* Magents from K&J (D42AH and D62SH)
*   High temperature magnets to allow soldering without demagnetization
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
*   Small cells car be orded cut into 3 sections, but I haven't found a source for cut large cell, but they can be cut with a fiber laser or potentially a razor or dremel
*   https://www.aliexpress.us/item/3256801658021801.html
*   https://www.aliexpress.us/item/3256805555889765.html
* Laminator sheets (5mil works well, but 3mil should work too)
* 0.2mm carbon fiber sheet for back side.  This could be substituted with plastic sheet to cut cost.  https://www.aliexpress.us/item/3256805950798977.html
* Pressure sensitive adhesive to attach laminated solar cells and foam/frame and also rear carbon fiber sheet to foam/frame
* Solar busbar and flux (I used 2x 1mm x 0.2mm busbars for each connection)
* 3mm architectural foam
* Magnets from K&J (2x B631-N52 for magnetic closure)
* PETG filament for frame.  I printed the frame with 0.8mm lateral walls and approximately 0.6mm top and bottom thickness with 20% grid infill.  I made the hinge areas 100% infill using a box in prusa slicer
*   Large panel CAD (approx 13W): https://a360.co/3wPAMOi
*   Small panel CAD (approx 10W): https://a360.co/4cJ9c5N

## Assembly
Testing of the performance was completed by building a custom panel, however, this module could be used to replace the charge module on a panel such as the lixada solar panel available on amazon

Installation steps for Lixada panel:
* Carefully remove solar to USB module from panel using a razor blade to cut adhesive under module and a soldering iron to desolder leads from panel
* Scrape any remaining adhesive off and clean with alcohol
* Solder new assembled pcb with housing and leads to panel
* Use epoxy to glue housing to panel

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_105228.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104936.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104617.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104551.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_104542.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_103334.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_101226.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_094351.jpg)

![](https://github.com/keith06388/mpptcharger2/blob/main/Photos/20250328_074910.jpg)
