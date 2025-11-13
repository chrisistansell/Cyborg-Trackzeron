Where we are now, as we approach 2026. 

Azeron Discord: Modifications Section.  I've invested a lot of time in the projects since this creation.  I enjoy working with the community to make their controller better.  Please take some time to visit there and make use of what you can find there.
Etsy Storefront:  [Coaleyed Gaming: Etsy Storefront](https://www.etsy.com/shop/CoaleyedGaming?ref=dashboard-header)
 
 - Standalone Trackball is available on this platform as static bearings and BTU driven motion.
 - Common modifications of pull and flick keys are available as well as my modded rails for the controller.
 - Up and coming items include several planned mods for Cyborg 2 controllers as well as the Keyzen.
 - In the case of special requests (through discord) I have made a mod for the trackball to convert the Cyro.
 - At some point the next big plan is to sacrfice the index and middle towers to work on a finger driven trackball, hopefully I can revive the 55mm huge trackball in this journey.
    
Since there is a lot of open source here, this project has been set to complete by me.  I've even went through the code in 2025 to clean it up and catch the formating up with all the QMK changes.


This Readme is coutesy of MK's main Trackzeron GitHub project.  A special thanks to his inspiration.  This will forever be linked to his OG mod of the Azeron Classic as a fork.

Reference site for any of my 3D designs for the Azeron controller (and some Keycrhon stuff) can be found here: [Thingiverse|Coaleyed](https://www.thingiverse.com/coaleyed/designs)

Please note that due to angles of the sensor in the design, you will need to use software such as [rawaccel](https://github.com/a1xd/rawaccel) or your on scripts to set the rotation between 10-15%.  Otherwise you will get a down pitch to the left on mouse movement.

# TRACKzeron: Adding trackball functionality to the [Azeron Keypad](https://www.azeron.eu/)

This repository contains source code and prebuilt firmware files for a modified Azeron keypad.

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Assembled%20Images/image5.jpeg)

Side profile design.

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Assembled%20Images/image4.jpeg)

Angled profile.

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Assembled%20Images/image3.jpeg)

## Only for Classic, Compact, and Cyborg models with TEENSY++ 2.0 mainboards

**This does not work with the current Cyborg/Cyborg compact models with the black proprietary microcontroller.** It is for Azeron devices that use the Teensy++ 2.0 (green) mainboard. The Teensy++ 2.0 was discontinued in 2021, and Azeron started producing models with their proprietary ARM/STM32-based (black) mainboard in late-2022. Before making this modification make sure you have ordered a board with a Teensy++ 2.0 PCB.  This is not directly available on their website and you will have to special request it.  A Teensy++ 2.0 board can be purchased secondary market, you will probably want to purchase a terminal block with screw mounts to make it more connection friendly.

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
- Teensy++ 2.0 Green Board AT90USB1286 - You might be able to find these on Aliexpress.  They will not have the terminal blocks so you will need to buy those seperately and will have to solder them on.  I was able to get everything to work.
	- It's end of support but still finding a few places like this that have the microcontroller [AliExpress Teensy 2.0++](https://www.aliexpress.us/item/2255800849800105.html?gatewayAdapt=glo2usa). 
	- I used 4 of these since I can't find a 20 pin version: [Screw Terminal Block Connectors](https://a.co/d/1D0JK94)
- [PMW3360 Motion Sensor](https://www.tindie.com/products/citizenjoe/pmw3360-motion-sensor/)
- [Trackzeron v4](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/3D%20Print%20Models/Trackzeron%20v4%20-%20PTEG.stl) This is the model for the top half of the trackball holder.
- [Trackzeron Base v4](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/3D%20Print%20Models/Trackzeron%20Base%20v4%20-%20PTEG.stl) This is the model for the bottom half of the trackball holder.

### Trackball Options
- 34mm Tackball: This could be a variety of trackballs on the market that fit the Logitech M570.  I personally tested color variant trackballs made by Perixx.  [Perixx PERIPRO-303 GBK 1.34"](https://www.amazon.com/dp/B08DD6GQRV?psc=1&ref=ppx_yo2ov_dt_b_product_details/)
	- I recently purchased a Protarc EM04 Wired Trackball and robbed it of it's 34mm purple trackball.

### Bearings
- Depending on your print choices, you will want to use either three (3) [3mm ceramic bearing balls](https://a.co/d/1juzp4G) or three (3) [3.5mm ceramic bearing balls](https://a.co/d/fikWqXD)
	- The most accurate trackball design is the lava lamp version.  I'd recommend this 3D print.  It uses 3mm bearings.

### Cabling (Optional if desoldering)
- [28 AWG wire](https://www.amazon.com/dp/B089Cq1C8L) You can reuse the wires going to the thumbstick if you like, you will likely need solder wick.  I recommend getting your own wire so you can revert your controller if needed.  Also good to have the wire so you can ground to the block rather than the teensy.
	- You could also use a terminal block with screw mounts to make connectivity easier. [8-pin 2.54mm Pitch PCB Terminal Block](https://www.amazon.com/dp/B098QLRFMF?ref=ppx_yo2ov_dt_b_product_details&th=1)
	- Using this will make it so you are unable to attach the shroud to the back to hide the sensor if you are using the simple v1/v2 3D print.
	- This will be hidden inside the "box" if you use v3 or v4 3D print.

### Hardware 
- 1 [M2.5 280pc Button Head Hex Screws](https://www.amazon.com/gp/product/B09CPDVYB7/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
	- To keep things simple, I'd suggest this set.  A lot cheaper than buying individual stuff and will have everything you need to do this project.
 	- Note that this comes with M2.5 hex nuts that you can use for the project. The next comment is optional if you buy this set.	
- Read above first! 2 [M2.5 thin hex nuts](https://www.mcmaster.com/products/hex-nuts/low-strength-steel-thin-hex-nuts-8/}) For the updated model.
	- I generally try to get everything from one place, but this was the only place I could find thin versions of the hex nuts.
- Optional [M2.5 square nuts](https://www.mcmaster.com/products/square-nuts/thread-size~m2-5/)
	- You don't need these, but could come in handy for projects you need to use M2.5 screws in customizations. 

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
- Strip and tin 7-9 inches of 28 AWG hookup wire. Make sure you add 2-3 inches to the black wire to reach the grounding block.  You will need 6 wires.
- Solder wires to the PMW3360 sensor pins (The other two are not used):
	- GD 
	- SS    
	- SC
	- MO
	- MI    
	- VI

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Pinouts/PMW3360%20-%20Teensy.png)

### Rewire the Azeron (Cyborg/Cyborg Compact)

- Remove the Azeron palmrest to reveal the Teensy Board

![Stock Wiring Diagram](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Stock%20Wiring%20Diagram.png)

- Disconnect all connections to the Teensy Board

![After Removing Connections](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/After%20Removing%20Connections.png)

- Reconnect the pinky and ring finger switches as follows:
	- Pinky finger:
		- High Pull/blue wire: B6
		- Pull/magenta wire: B5
		- Push/orange wire: B4
		- Flick/red wire: E7
 		- High Flick/green wire: E6 
   		- Side Flick/yellow: F0
	- Ring finger:
 		- High Pull/blue wire: F1
   		- Pull/magenta wire: F2
		- Push/orange wire: F3
		- Flick/red wire: F4
  		- High Flick/green wire: F5
	- Middle finger:
		- High Pull/blue wire: B7
		- Pull/magenta wire: D0
		- Push/orange wire: D1
		- Flick/red wire: D2
		- High Flick/green wire: D3  
	- Index finger:
		- High Pull/blue wire: D4
		- Pull/magenta wire: D5
		- Push/orange wire: E0
		- Flick/red wire: E1
		- High Flick/green wire: C0
		- Side Flick/yellow: C1
	- Thumb:
 		- Thumb side flick/yellow wire: C2
	- Profile switch:
 		- Profile 2/magenta wire: F6
   		- Profile 1/orange wire: F7
	- LED:	
 		- LED 2/green wire: C5
  		- LED 1/blue wire: C6

### Grounding your hardware:
- GND 1(Pin 1 Right side) - Top View Mounted - Azeron Ground Block (this already exists default from Azeron)
- GND 2(Pin 31 Left side) - Top View Mounted - (Optional) This pin is unused but might be required if you have issues with sleep performance on your computer.
	- If sleep issues are encountered, a piece of cable needs to be added from this pin to the ground block.
	- Due to limited connectons and only having 1 open slot on the terminal block that was freed up by removing the thumbstick, you can twist the optical sensor (mouse) ground cable (GND) and this (pin 31) GND together/Azeron then place it in the open ground terminal slot.

### Connect the PMW3360 Sensor:
-   Connect the sensor to the Teensy board as follows:
	- GD: GND (please read Grounding your hardware section above)
   	- SS: B0
   	- SC: B1
   	- MO: B2
   	- MI: B3
   	- VI: +5V

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Pinouts/PMW3360%20-%20Teensy.png)

![Final Wiring](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Final%20Wiring.png)

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Pinouts/Finger%20Image%20%26%20Pinout.png)

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Pinouts/Screenshot%202024-05-12%20191039.png)
 
I used my own wiring for the optical sensor to the teensy board.  So I substituted the purple (magenta/pink) wire for a white wire because of the color spectrum in my wire kit.  I had USB connectivity issues where it would disconnect and reconnect when I used a ground wire from optical sensor to the teensy board.  I ended up moving the ground wire from the optical sensor to the grounding block in the palm rest.  

![](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Assembled%20Images/image2.jpeg)

- Using firm force (can be assisted with outside pressure i.e., small channel-locks) push (3) 3mm bearings into slots.
- Attach the sensor to the trackball assembly. 
- Fit the trackball assembly to the Azeron thumb rail.   
- Reattach the palmrest
- Place ball in cup.
- Load firmware HEX file using the [QMK Toolbox](https://github.com/qmk/qmk_toolbox) by choosing AT90USB1286 for the MCU then pointi to the cyborg_trackzeron_via.hex file then pressing the reset button on the underside of the controller.  If you check auto flash it will apply the .hex once you press the DFU button.  If you do not click it, then you will need to click the flash button in the QMK toolbox application.
	- Make sure that you have downloaded the drivers for QMK toolbox to work correctly! 
- Take a look at keymaps in [VIA](https://www.caniusevia.com/), make any changes that you would like using the via.json file in the root directry of QMK > Cyborg Trackzeron.  Take the time to make a second profile tied to the profile switch on the palm rest of your Cyborg.  FN key activates an additional layer on your keypad if you would like to map that somewhere in your layout on your controllers for additional controls.
- Tweak your cursor accuracy using [rawaccel](https://github.com/a1xd/rawaccel).

![Recommended Generic Settings for Your Trackball](https://github.com/chrisistansell/Cyborg-Trackzeron/blob/main/Pinouts/Rawaccel%20Generic%20Recommendation.png)

- Enjoy trackball keypad!
