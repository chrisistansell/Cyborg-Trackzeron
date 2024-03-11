This Readme is coutesy of MK's main Trackzeron GitHub project.  A special thanks to his inspiration.  This will forever be linked to his OG mod of the Azeron Classic as a fork.

Please note that due to angles of the sensor in the design, you will need to use software such as rawaccel or your on scripts to set the rotation between 20-25%.  Otherwise you will get a down pitch to the left on mouse movement.

# TRACKzeron: Adding trackball functionality to the [Azeron Keypad](https://www.azeron.eu/)

This repository contains source code and prebuilt firmware files for a modified Azeron keypad.

![](https://github.com/chrisistansell/trackzeron/blob/main/34mm%20Overview.jpeg)

Side profile with shroud covering optical sensor.

![](https://github.com/chrisistansell/trackzeron/blob/main/34mm%20Holder.jpeg)

## Only for Classic, Compact, and Cyborg models with TEENSY++ 2.0 mainboards

**This does not work with the Cyborg/Cyborg compact models.** It is for Azeron devices that use the Teensy++ 2.0 (green) mainboard. The Teensy++ 2.0 was discontinued in 2021, and Azeron started producing models with their proprietary ARM/STM32-based (black) mainboard in late-2022. Before making this modification make sure you have ordered a board with a Teensy++ 2.0 PCB.  This is not directly available on their website and you will have to special request it.  A Teensy++ 2.0 board can be purchased secondary market, you will probably want to purchase a terminal block with screw mounts to make it more connection friendly.

Additional testing will be performed on STM and RP2040 over the next few months.  I'll keep you guys updated.  If I can migrate to STM then we could potentially get 1000Hz polling rates.

## Notes

-   This mod has no official Azeron support.
-   I had to compile custom firmware to make the trackball work, so this modded keypad does not work with the official Azeron software.
-   This mod requires soldering. (No soldering to anything on the keypad, just the sensor module)   
-   Modifying your device always comes with risk attached. I’m sharing what worked for me and offer no guarantees.

## FAQs:

### “TRACKzeron”?
Trackball + Azeron = TRACKzeron.

### Will this work on my device with a black mainboard?
The firmware will not work. The new black mainboards have a different chip. The firmware was not designed for it. I cannot confirm whether the new mainboard can be rewired to accommodate the sensor.
-- Update 3.4.24 I'm working with Azeron to get the Azeron black microcontroller to see if I can push code to it.

### How did you add the trackball?
See the [guide](#guide).

### How does this work in the Azeron Software?
***This mod is not compatible with the official Azeron Software.*** You will need to use a different software to set your keybinds.  I have added support for VIA using the via.json file in the QMK folder.  VIAL is also an option, the files you need are all in keymap.c > VIAL.

You can optionally hard code your own keymaps and then create your own hex file.  This can be done by manipulating the the KC_xx entries found in the keymap.c folder.

### How do you use the Azeron Software with two keypads at once?
Since there is no thumbstick on this controller, the two together function like a keyboard and mouse.  You should be able to use both controllers without issues in games.

### Do you have a video where you’re playing with both keypads together?
Yes; there's a [YouTube clip](https://youtu.be/ogBYqxuF61s)  Sorry at the time I filmed this it was being done inverted by my camera.  I'll try to get an update to the video soon.

### Can you make me one?
No.  But I will gladly assist you in your build.  

## Guide

### Parts
- [Azeron Keypad](https://www.azeron.eu/) (Cyborg or Cyborg Compact with Teensy++ 2.0 green board)
- Teensy++ 2.0 Green Board AT90USB1286 - You might be able to find these on Aliexpress.  They will not have the terminal blocks so you will need to buy those seperately and will have to solder them on.
	- I plan to use 2 of these to test with since I can't find a 20 pin version: [Screw Terminal Block Connectors](https://www.amazon.com/dp/B0BLHJY5NT?ref=ppx_yo2ov_dt_b_product_details&th=1)
- [PMW3360 Motion Sensor](https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/)
- [3D printed STL 34mm trackball snap fit v3 holder](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/tree/main/3D%20Print%20Files/STL%20Files%20-%2034mm%20V3%20Snap%20Fit)

### Trackball Options
- 34mm Tackball: This could be a variety of trackballs on the market that fit the Logitech M570.  I personally tested color variant trackballs made by Perixx.  [Perixx PERIPRO-303 GBK 1.34"](https://www.amazon.com/dp/B08DD6GQRV?psc=1&ref=ppx_yo2ov_dt_b_product_details/)
	- I recently purchased a Protarc EM04 Wired Trackball and robbed it of it's 34mm purple trackball.

### Bearings
- Three (3) [3mm ceramic bearing balls](https://www.amazon.com/dp/B07SXJWLHN?smid=A1THAZDOWP300U&ref_=chk_typ_imgToDp&th=1)
	- I've recently upgraded mine on 03.11.24 to [3.5mm ceramic bearing balls](https://a.co/d/fikWqXD)

### Cabling (Optional if desoldering)
- [28 AWG wire](https://www.amazon.com/dp/B089Cq1C8L) You can reuse the wires going to the thumbstick if you like, you will likely need solder wick.  I recommend getting your own wire so you can revert your controller if needed.  Also good to have the wire so you can ground to the block rather than the teensy.
   - You could also use a terminal block with screw mounts to make connectivity easier. [8-pin 2.54mm Pitch PCB Terminal Block](https://www.amazon.com/dp/B098QLRFMF?ref=ppx_yo2ov_dt_b_product_details&th=1)
      - Using this will make it so you are unable to attach the shroud to the back to hide the sensor if you are using the simple v1/v2 3D print.
      - This will be hidden inside the "box" if you use v3 3D print.

### Hardware 
- 1 [M2.5 280pc Button Head Hex Screws](https://www.amazon.com/gp/product/B09CPDVYB7/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
	- To keep things simple, I'd suggest this set.  A lot cheaper than buying individual stuff and will have everything you need to do this project.
- 2 [M2.5 thin hex nuts](https://www.mcmaster.com/products/hex-nuts/low-strength-steel-thin-hex-nuts-8/}) For the updated model.
	- I generally try to get everything from one place, but this was the only place I could find thin versions of the hex nuts. 	

### Tools
- screwdrivers: Azeron screwdriver with hex head, philips, and small flat head screwdriver to clean plastic from the 3D prints 
- precision tweezers
- soldering iron & solder 
  - wick is optional but helpful if you have soldering issues to undo
  - I also suggest a magnifying glass lamp and a heat proof working surface
- wire friendly scissors (i use Klein)
- wire stripper
- wire cutters

### Preparing

**NOTE:** It's important for the switches and sensor to be connected ***exactly as indicated*** or the device will not work.

- 3D print the trackball assembly.   
- Push the ceramic ball bearings into the trackball assembly.   
- Strip and tin 7-9 inches of 28 AWG hookup wire OR desolder the wires attached to the thumbstick and D-pad. Need 6 wires.
- Solder wires to the PMW3360 sensor pins (The other two are not used):
	- GD (Save yourself some headaches and just run this to the Azeron Ground Block)
	- SS    
	- SC
	- MO
	- MI    
	- VI

![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

I used a white wire when running new cables since I didn't have any magenta wire to use.

### Rewire the Azeron (Cyborg/Cyborg Compact)

- Remove the Azeron palmrest to reveal the Teensy Board

![Stock Wiring Diagram](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Stock%20Wiring%20Diagram.png)

- Disconnect all connections to the Teensy Board

![After Removing Connections](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/After%20Removing%20Connections.png)

- Reconnect the pinky and ring finger switches as follows:
	- Pinky finger:
		- Higher flick/blue wire: E6
		- High flick/green wire: E7
		- Flick/red wire: B4
		- Push/orange wire: B5
		- Pull/magenta wire: B6
 		- Side Flick/yellow: F0
	- Ring finger:
 		- Higher flick/blue wire: F5
   		- High flick/green wire: F4
		- Flick/red wire: F3
		- Push/orange wire: F2
  		- Pull/magenta wire: F1
	- Middle finger:
		- Higher flick/blue wire: D3
		- High flick/green wire: D2
		- Flick/red wire: D1
		- Push/orange wire: D0
		- Pull/magenta wire: B7 
	- Index finger:
 		- Higher flick/blue wire: D4
		- High flick/green wire: D5
		- Flick/red wire: E0
		- Push/orange wire: E1
		- Pull/magenta wire: C0
		- Side Flick/yellow: C1
	- Thumb:
 		- Thumb side flick/yellow wire: C2
	- Profile switch:
 		- Profile 2/magenta wire: F6
   		- Profile 1/orange wire: F7
	- LED:
 		- LED 2/green wire: C5
  		- LED 1/blue wire: C6
    	- GND:
     		- GND 2(Left side - Top View)/Azeron Ground Block
       		- GND 1(Right side - Top View) - Twist Mouse GD and this GND together/Azeron Ground Block
         		- Having this is important otherwise you might experience computer sleep issues     
        

### Connect the PMW3360 Sensor:
-   Connect the sensor to the Teensy board as follows:

![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

I used a white wire when running new cables since I didn't have any magenta wire to use.

   - GD: GND (Twist this with GND 1 and place in Azeron Ground Block)
   - SS: B0
   - SC: B1
   - MO: B2
   - MI: B3
   - VI: +5V



![Final Wiring](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Final%20Wiring.png)


 
I used my own wiring for the optical sensor to the teensy board.  So I substituted the purple (magenta/pink) wire for a white wire because of the color spectrum in my wire kit.  I had USB connectivity issues where it would disconnect and reconnect when I used a ground wire from optical sensor to the teensy board.  I ended up moving the ground wire from the optical sensor to the grounding block in the palm rest.  

- Attach the sensor to the trackball assembly. 
- Fit the trackball assembly to the Azeron thumb rail.   
- Reattach the palmrest
- Place ball in cup.
- Load firmware HEX file using the QMK Toolbox by choosing AT90USB1286 for the MCU then pointi to the cyborg_trackzeron_via.hex file then pressing the reset button on the underside of the controller.  If you check auto flash it will apply the .hex once you press the DFU button.  If you do not click it, then you will need to click the flash button in the QMK toolbox application.
	- Make sure that you have downloaded the drivers for QMK toolbox to work correctly! 
- Take a look at keymaps in VIA, make any changes that you would like using the via.json file in the root directry of QMK > Cyborg Trackzeron.  Take the time to make a second profile tied to the profile switch on the palm rest of your Cyborg.  FN key activates an additional layer on your keypad if you would like to map that somewhere in your layout on your controllers for additional controls.
- Enjoy trackball keypad
