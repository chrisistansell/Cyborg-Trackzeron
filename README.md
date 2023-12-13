This Readme is coutesy of MK's main Trackzeron GitHub project. I've made modifications to reflect the work I have done and had success with modifying the Azeron Cyborg.  Please visit MK's page for instructions on configuring the Classic version of the Azeron controllers.  I do have files scattered in my directory that might be useful on the classic version because that is where my work started.
 
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
- [Azeron Keypad](https://www.azeron.eu/) (Cyborg or Cyborg Compact with Teensy++ 2.0 green board)
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

### Cabling (Optional if desoldering)
- [28 AWG wire](https://www.amazon.com/dp/B089Cq1C8L) You can reuse the wires going to the thumbstick if you like, you will likely need solder wick.  I recommend getting your own wire so you can revert your controller if needed.  Also good to have the wire so you can ground to the block rather than the teensy.
   - You could also use a terminal block with screw mounts to make connectivity easier. [8-pin 2.54mm Pitch PCB Terminal Block](https://www.amazon.com/dp/B098QLRFMF?ref=ppx_yo2ov_dt_b_product_details&th=1)
      - Using this will make it so you are unable to attach the shroud to the back to hide the sensor.

### Hardware 
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

![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

I used a white wire when running new cables since I didn't have any magenta wire to use.

### Rewire the Azeron (Cyborg/Cyborg Compact)

- Remove the Azeron palmrest to reveal the Teensy Board

![Stock Wiring Diagram](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Stock%20Wiring%20Diagram.png)

- Disconnect all connections to the Teensy Board

![After Removing Connections](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/After%20Removing%20Connections.png)

- Reconnect the pinky and ring finger switches as follows:
   	-   Pinky finger:
            - Higher flick/blue wire: E6
	    - High flick/green wire: E7
	    - Flick/red wire: B4
	    - Push/orange wire: B5
	    - Pull/magenta wire: B6
            - Side Flick/yellow: F0
	-   Ring finger:
            - Higher flick/blue wire: F5
	    - High flick/green wire: F4
	    - Flick/red wire: F3
	    - Push/orange wire: F2
	    - Pull/magenta wire: F1
	-   Middle finger:
            - Higher flick/blue wire: D3
     	    - High flick/green wire: D2
	    - Flick/red wire: D1
	    - Push/orange wire: D0
	    - Pull/magenta wire: B7 
	-   Index finger:
            - Higher flick/blue wire: D4
	    - High flick/green wire: D5
	    - Flick/red wire: E0
	    - Push/orange wire: E1
	    - Pull/magenta wire: C0
            - Side Flick/yellow: C1
	-   Thumb:
            - Thumb side flick/yellow wire: C2
	-   Profile switch:
            - Profile 2/magenta wire: C3
	    - Profile 1/orange wire: C4
	-   LED:
            - LED 2/green wire: C5
	    - LED 1/blue wire: C6

![Reconnecting Towers](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Reconnecting%20Towers.png)

### Connect the PMW3360 Sensor:
-   Connect the sensor to the Teensy board as follows:

![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

I used a white wire when running new cables since I didn't have any magenta wire to use.

   - GD: GND
   - SS: B0
   - SC: B1
   - MO: B2
   - MI: B3
   - VI: +5V

![Final Layout](https://github.com/chrisistansell/Cyborg-Trackzeron---Teensy-2.0/blob/main/Pinouts/Final%20Layout.png)
 
I used my own wiring for the optical sensor to the teensy board.  So I substituted the pink wire for a white wire because of the color spectrum in my wire kit.  I had USB connectivity issues where it would disconnect and reconnect when I used a ground wire from optical sensor to the teensy board.  I ended up moving the ground wire from the optical sensor to the grounding block in the palm rest.  

- Attach the sensor to the trackball assembly. 
- Fit the trackball assembly to the Azeron thumb rail.   
- Reattach the palmrest
- Place ball in cup.
- Load firmware HEX file using the QMK Toolbox by pointing to the trackzeron_default.hex file then pressing the reset button on the underside of the controller, followed by clicking the flash button on the QMK toolbox application.
- Enjoy trackball keypad

Due to the complexity and my limit understanding, I have not been able to work the Azeron profiles into the design.  The toggle button on the palm rest of the Azeron will no longer function and the LEDs will no longer emit light.  I was able to get this to work in the Arduino software, but using this method for your firmware on the Trackzeron will lead to issues losing connectivity when your computer goes to sleep.  I'd recommend using the QMK format firmware available as a release download on this github page.
