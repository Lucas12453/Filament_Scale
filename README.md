# Filament Scale # 

## Overview ##   
Created to easily determine the weight and length of 3D printing filament left on a spool. It is made using 3D printed parts as well as various electronics, and is padded with silicone molds. There are 4 modes coded into the scale, 3 of which are for removing the weight of different spools, and 1 to be used as a normal scale.

## Materials and Equipment ##
- Arduino Nano  
- I2C 128x64 OLED screen  
- 10kg load cell  
- Push button  
- HX711 load cell amplifier  
- 4-pin block terminal  
- Wires  
- 5x7cm Prototype board   
- Soldering equipment   
- Silicone (Smooth-On Mold Star 15 Slow Platinum Silicone Rubber was used here)

- 8 x M2.5 12mm screws  
- 4 x M3 30mm screws  
- 2 x M4 25mm screws  
- 2 x M4 35mm screws

### Printing: ###
- PLA (polylactic acid) filament  
- 3D printer (a Prusa i3 MK3 printer was used here)

## Parts ##
### Base ###    
<img src="https://raw.githubusercontent.com/Lucas12453/filament_scale/main/Fil%20Scale%20Base.jpg" width="450">

### Lid ###  
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Fil%20Scale%20Lid.jpg" width="450">

### Display Covering ### 
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Fil%20Scale%20Display%20Covering.jpg" width="450">

### Spacer ###  
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Fil%20Scale%20Spacer.jpg" width="450">

### Plate ### 
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Fil%20Scale%20Plate.jpg" width="450">

## Assembly ##

1. Assemble the circuit:
   ![][image6]![][image7]![][image8]  
- Attach the Screen to the Arduino Nano using wires roughly the length of 10cm.

  The wires must connect the following:

  VCC (Screen) \--- 5V(Arduino Nano)

  GND (Screen) \--- GND (Arduino Nano)

  SDA (Screen) \--- A4 (Arduino Nano)

  SCL (Screen) \--- A5 (Arduino Nano)


- Attach the HX711 to the Arduino Nano using wires of various lengths. 

  The wires must connect the following:

  VCC (HX711) \--- 5V (Arduino Nano)

  SCK (HX711) \--- Digital 2 (Arduino Nano)  
  DT (HX711) \--- Digital 3 (Arduino Nano)  
  GND (HX711) \--- GND (Arduino Nano)

- Take the 4 wires of the load cell and feed them through the leftmost hole within the opening of the trapezoid shape on the top of the lid. Feeding it through completely, the load cell can now comfortably sit within that same opening *(Be wary not to crush the wires under the load cell. If they are under or over the load cell, flip the load cell in a way so the wires have enough space.)* Line the holes of the load cell with the holes on the bottom of the lid. You can now use 2 M4 25mm screws to screw the load cell in place.

   ![][image9]

- Take those 4 wires coming out the other side, and insert them into the block terminal where there are 4 openings, one for each wire *(Double check that each opening is open completely before inserting the wire.)* Close those openings by screwing the small screws on the top of the block terminal.![][image10]   
- Attach the corresponding pins to the HX711 using wires of various lengths.

  The wires must connect the following: 

  E+ \--- Red

  E- \--- Black

  A- \--- White

  A+ \--- Green
