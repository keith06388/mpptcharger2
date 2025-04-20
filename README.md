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
* PCBA assembled by JLCPCB
* Primary components:
*   BQ25622e - mppt solar battery charging chip
*   ATTINY1616 - arduino compatable microcontroller

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

## Assembly
Testing of the performance was completed by building a custom panel, however, this module could be used to replace the charge module on a panel such as the lixada solar panel available on amazon

Installation steps for Lixada panel:
* Carefully remove solar to USB module from panel using a razor blade to cut adhesive under module and a soldering iron to desolder leads from panel
* Scrape any remaining adhesive off and clean with alcohol
* Solder new assembled pcb with housing and leads to panel
* Use epoxy to glue housing to panel



