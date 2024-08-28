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
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Fil%20Scale%20Base.jpg" width="450">

### Display Covering ### 
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Fil%20Scale%20Display%20Covering.jpg" width="450">

### Lid ###  
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Fil%20Scale%20Lid.jpg" width="450">

### Plate ### 
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Fil%20Scale%20Plate.jpg" width="450">

### Spacer ###  
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Fil%20Scale%20Spacer.jpg" width="450">

## Assembly ##

1. Assemble the circuit:
   
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Overhead%20Circuit%201.jpg" width="300"> <img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Overhead%20Circuit%202.jpg" width="300"> <img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Underside%20Circuit%201.jpg" width="300">
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
- Take those 4 wires coming out the other side, and insert them into the block terminal where there are 4 openings, one for each wire *(Double check that each opening is open completely before inserting the wire.)* Close those openings by screwing the small screws on the top of the block terminal.

<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/4-Pin%20Terminal%20Block%20Close-up.jpg" width="200">
- Attach the corresponding pins to the HX711 using wires of various lengths.

  The wires must connect the following: 

  E+ \--- Red

  E- \--- Black

  A- \--- White

  A+ \--- Green
  
<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Terminal%20Block%20to%20HX711.jpg" width="200">


- Attach the button by first placing it into its slot in the base. Solder 10cm long wires to a GND pin and the digital 4 pin on the Arduino Nano. Then solder those 2 wires to 2 pins on the button that are diagonal to each other.

<img src="https://github.com/Lucas12453/filament_scale/blob/main/Images/Push%20Button%20Close-up.jpg" width="200">

- You can now place the prototype board onto its legs, lining up the holes, and with the mini usb port on the Arduino Nano coming out of the opening on the back of the base. Place 4 M2.5 12mm screws into the corner holes on the board and through the holes in the legs to keep the board stable.

2. Put the display against the opening in the front of the base. The 4 small ends of pins on the front of the screen should fit into the carved out space above the opening, and the holes on the screen should match the holes on the base. Take the display covering and line it up with the screen and the base, and use 4 M2.5 12mm screws to screw them together.   
3. Place the lid on top of the base, and use the 4 x M3 30mm screws to attach it to the base.  
4. Insert the load cell into the spacer and line up the holes, then place the plate with the flat side facing up, flatly on top of the spacer, and line those holes as well. Use the 2 M4 35mm screws to attach all of them together.   
5. Create silicone coverings:  
- Mix a total of 250g of silicone in a 500g or larger container  
- Pour out 125g of Part A silicone into a container  
- Pour out 125g of Part B silicone into the 500g or larger container  
- Pour Part B into the same container as Part A and mix thoroughly. *(Be sure to scrape and incorporate excess silicone on the sides of the container.)* Pour that mixture back into the container that housed Part B and mix in there to include the silicone that was left behind. *(Be wary of the pot life written on the container of the silicone parts, which dictates how long the silicon remains malleable and workable.)*   
- Spray the 2 molds with a light coating of mold release agent, so the removal of the silicone will be easier  
- Take the container and place it inside a vacuum chamber, and turn it on to de-gas the silicone so there are no air bubbles when it cures. When the silicon stops bubbling, take it out of the chamber and pour it into the mold  
- Pour it in a continuous, medium sized stream into the lowest point of the mold to avoid air bubbles.   
- Let the 2 molds sit overnight or for the length of the demold time written on the container of the silicone parts.  
- Carefully remove the molds and position them accordingly onto the scale.  
6. Import the filament scale code using a mini usb cable.
