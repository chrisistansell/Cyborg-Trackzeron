This Readme is coutesy of MK's main Trackzeron GitHub project. I've made modifications to reflect the work I have done and had success with modifying the Azeron Cyborg.

# TRACKzeron: Adding trackball functionality to the [Azeron Keypad](https://www.azeron.eu/)

This repository contains source code and prebuilt firmware files for a modified Azeron keypad.

![](https://github.com/chrisistansell/trackzeron/blob/main/34mm%20Overview.jpeg)

Side profile with shroud covering optical sensor.

![](https://github.com/chrisistansell/trackzeron/blob/main/34mm%20Holder.jpeg)

## Only for Classic, Compact, and Cyborg models with TEENSY++ 2.0 mainboards

**This does not work with the Cyborg/Cyborg compact models.** It is for Azeron devices that use the Teensy++ 2.0 (green) mainboard. The Teensy++ 2.0 was discontinued in 2021, and Azeron started producing models with their proprietary ARM/STM32-based (black) mainboard in late-2022. Before making this modification make sure you have ordered a board with a Teensy++ 2.0 PCB.  This is not directly available on their website and you will have to special request it.  A Teensy++ 2.0 board can be purchased secondary market, you will probably want to purchase a terminal block with screw mounts to make it more connection friendly.

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

### Will this work on the Azeron Cyborg or Cyborg Compact model?
I am currently working on trying to move this to a Cyborg model using a Teensy 2.0++ board being specially installed for testing.  Will update this in the future.  ETA is to have something together by the middle of July.

### How did you add the trackball?
See the [guide](#guide).

### How does this work in the Azeron Software?
***This mod is not compatible with the official Azeron Software.*** You will need to use a different software to set your keybinds. I have used reWASD and JoyToKey.

### How do you use the Azeron Software with two keypads at once?
Using two keypads simultaneously isn’t officially supported by the Azeron software (yet? seems like they're working on that), even if they’re both stock firmware/not modified, but a workaround for two unmodified keypads is to plug in one keypad, set the keybinds, then unplug. Plug in the second keypad and set those keybinds. You won't be able to change the keybinds while they're both plugged in, but they should work in-game.

### Do you have a video where you’re playing with both keypads together?
Yes; there's a [YouTube clip](https://youtu.be/LT7abxc7oYk) of MK playing Mass Effect Andromeda,
and some of him playing Borderlands on [Twitch channel](https://twitch.tv/allphobic13).

### Can you make me one?
No.

## Guide

### Parts
- [Azeron Keypad](https://www.azeron.eu/) (Classic, Compact, or Cyborg)
- [PMW3360 Motion Sensor](https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/) (Updated link from Melaphor's instructions)
- [3D printed STL 52mm trackball holder assembly](https://www.thingiverse.com/thing:4667691)
- [3D printed 3MF 52mm trackball holder assembly](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/3D%20Print%20Files/3MF%20Files%20-%2052mm/52mm%20Trackball%20Bearing%20Hole%20Shift.3mf) I modified bearing locations to help support the trackball, especially if you are using the new Azeron stands. 
- [3D printed 3MF 34mm trackball holder and shroud assembly](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/3D%20Print%20Files/3MF%20Files%20-%2034mm/42OD-36IDmm%20Trackzeron%20Clip%20and%20Shroud.3mf)
### Trackball Options
- 52mm ball: I use the ball from an [Elecom Huge](https://elecomus.com/web/product/3271/) trackball, but I have verified that a 2 <sup>1</sup>/<sub>16</sub> inch[52.5mm] [snooker/billiard ball](https://www.johnparrottsports.com/snooker/snooker-balls/#category175) works
- 34mm Tackball: This could be a variety of trackballs on the market that fit the Logitech M570.  I personally tested color variant trackballs made by Perixx.  [Perixx PERIPRO-303 GBK 1.34"](https://www.amazon.com/dp/B08DD6GQRV?psc=1&ref=ppx_yo2ov_dt_b_product_details/)
### Bearings
- Three (3) [3mm ceramic bearing balls](https://www.amazon.com/gp/product/B07SXJWLHN/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1)]
  - Make sure you get more than 3, these are super easy to lose in the floor!
- [28 AWG wire](https://www.amazon.com/dp/B089Cq1C8L) You can reuse the wires going to the thumbstick if you like, you will likely need solder wick.  I recommend getting your own wire so you can revert your controller if needed.  Also good to have the wire so you can ground to the block rather than the teensy.
   - You could also use a terminal block with screw mounts to make connectivity easier. [8-pin 2.54mm Pitch PCB Terminal Block](https://www.amazon.com/dp/B098QLRFMF?ref=ppx_yo2ov_dt_b_product_details&th=1)
      - Using this will make it so you are unable to attach the shroud to the back to hide the sensor. 
- 2 [M2.5x15 machine screws](https://www.amazon.com/gp/product/B0756V9LF7/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) This is to secure the sensor and the shroud to the trackball mount.
- 2 [M2.5x10 machine screws](https://store.azeron.eu/index.php?route=product/product&path=62&product_id=82) This is to mount the trackball holder to the thumb rail.
- 2 [M2.5x6 machine screws](https://www.amazon.com/gp/product/B0756W6Z5L) This is to mount the PMW3360 to the trackball holder.
- 2 [M2.5 hex nuts](https://www.mcmaster.com/products/hex-nuts/low-strength-steel-thin-hex-nuts-8/}) For the updated model.
- 2 Optional [M2.5mm square nuts](https://www.etsy.com/listing/239501658/m25-square-rail-nuts?ref=yr_purchases) Cutouts are provided in the 3MF File. These can are placed behind the screw holes on the trackball optical sensor mounting area to provide firm connectivity of the shroud and the PCB to the trackball mount.  This will hold without adding these to the screw downs but if you take the shroud off a few times the M2.5 screws will start to lose their grip.

### Tools
- screwdrivers: Azeron screwdriver with hex head, philips, and small flat head screwdriver to clean plastic from the 3D prints 
- precision tweezers
- soldering iron & solder 
  - wick is optional but helpful if you have soldering issues to undo
- wire friendly scissors (i use Klein)
- wire stripper
- wire cutters

### Preparing

**NOTE:** It's important for the switches and sensor to be connected ***exactly as indicated*** or the device will not work.

- 3D print the trackball assembly.   
- Push the ceramic ball bearings into the trackball assembly.   
- Strip and tin 7-9 inches of 28 AWG hookup wire OR desolder the wires attached to the thumbstick and D-pad. Need 6 wires.
- Solder wires to the PMW3360 sensor pins (The other two are not used):
	- GD
	- SS    
	- SC
	- MO
	- MI    
	- VI 

### Rewire the Azeron (Classic/Classic Compact)

- Remove the Azeron palmrest to reveal the Teensy Board

![Azeron-unchanged](https://user-images.githubusercontent.com/16569424/107108978-5b8f1f00-680a-11eb-86c0-2a26af66000b.png)   

- Disconnect the thumbstick and D-pad from the Teensy board and grounding block.  
- Remove the thumbstick assembly from the rail.

![Azeron-removethumb](https://user-images.githubusercontent.com/16569424/107108984-706bb280-680a-11eb-9773-adbbb86909cb.png)

- Disconnect the pinky and ring finger switches from the Teensy board (**leave the ground [black] wires connected to the grounding block**)    
- Reconnect the pinky and ring finger switches as follows:
   	-   Ring finger:
	    - High flick/green wire: F7
	    - Flick/red wire: F6
	    - Push/orange wire: F5
	    - Pull/purple wire: F4
	-   Pinky finger:
	    - High flick/green wire: F3
	    - Flick/red wire: F2
	    - push/orange wire: F1
	    - pull/purple wire: F0

 
![Azeron-movepinkyring](https://user-images.githubusercontent.com/16569424/107109037-e4a65600-680a-11eb-983f-14ca71fb90f0.png)






### Rewire the Azeron (Cyborg/Cyborg Compact)

- Remove the Azeron palmrest to reveal the Teensy Board


- Disconnect the pinky and ring finger switches from the Teensy board (**leave the ground [black] wires connected to the grounding block**)    
   - The left (+5V side of your Teensy++2.0 should have no wires connected at this point)
- Reconnect the pinky and ring finger switches as follows:
   	-   Ring finger:
            - Higher flick/blue wire: F5
            - High flick/green wire: F4
	    - Flick/red wire: F3
	    - Push/orange wire: F2
	    - Pull/magenta wire: F1
	-   Pinky finger:
            - Higher flick/blue wire: E6
	    - High flick/green wire: F7
	    - Flick/red wire: B4
	    - Push/orange wire: B5
	    - Pull/magenta wire: B6
            - Side Flick/yellow: F0 

### Connect the PMW3360 Sensor:
-   Connect the sensor to the Teensy board as follows:
	- GD: GND    
	- SS: B0
	- SC: B1
	- MO: B2
	- MI: B3
	- VI: +5V

![Azeron-addsensor](https://user-images.githubusercontent.com/16569424/107109075-17e8e500-680b-11eb-8602-91806c507511.png)
![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

I used my own wiring for the optical sensor to the teensy board.  So I substituted the pink wire for a white wire because of the color spectrum in my wire kit.  I had USB connectivity issues where it would disconnect and reconnect when I used a ground wire from optical sensor to the teensy board.  I ended up moving the ground wire from the optical sensor to the grounding block in the palm rest.  

![Final Layout](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/CYBORG%20PINOUT.jpg)

- Attach the sensor to the trackball assembly. 
- Fit the trackball assembly to the Azeron thumb rail.   
- Reattach the palmrest
- Place ball in cup.
- Load firmware HEX file using the QMK Toolbox by pointing to the trackzeron_default.hex file then pressing the reset button on the underside of the controller, followed by clicking the flash button on the QMK toolbox application.
- Enjoy trackball keypad

Due to the complexity and my limit understanding, I have not been able to work the Azeron profiles into the design.  The toggle button on the palm rest of the Azeron will no longer function and the LEDs will no longer emit light.  I was able to get this to work in the Arduino software, but using this method for your firmware on the Trackzeron will lead to issues losing connectivity when your computer goes to sleep.  I'd recommend using the QMK format firmware available as a release download on this github page.
