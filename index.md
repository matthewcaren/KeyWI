# KeyWI Building Instructions

To learn about the KeyWI see the [project website](https://ccrma.stanford.edu/~mcaren/keyWI/).

For project files and code see the [project github](https://github.com/matthewcaren/keyWI).

## Parts

- AKM320 MIDI keyboard
- PocketBeagle
- Bela Mini cape
- [KeyWI PCB](https://github.com/matthewcaren/KeyWI/blob/master/platform-files/board-schematic.fzz)
- [Modern Device MPXV board](https://moderndevice.com/product/pressure-sensor-mpxv/)
- 1/4 in vinyl tubing
- #4-40 standoffs
  - 4x 1/2 in
  - 4x 1/4 in
 - 5x 3/16x0.25in binding posts
- (If using batteries) 2x 2 AAA battery holder

The mouthpiece and key mounts are 3D-printed—STL files for printing can be found in the project Github. Depending on the settings of the 3D printer, there may be a thin layer of plastic created about halfway down the mouthpiece; be sure to remove this layer, or else no pressure will reach the sensor. Also check that the small pinhole in the side of the mouthpiece is open and allows a small amount of air to pass through.


## Enclosure

The enclosure is constructed by bolting together 9 laser-cut layers of 1/8-in material (in the original KeyWI design, we used birch plywood, but acrylic or MDF would work too). Laser-cutting files in SVG format are available here. 

After assembling the enclosure, place the key mounts flat on the inside of the enclosure; it should fit snugly. Mark the locations of the mounting holes and drill these holes into the bottom layer of the enclosure.


## Electronics

Solder:
- the Bela Mini cape to the PocketBeagle
- the MPX sensor to the breakout board
- 6-pin 0.1” female headers to the top of the MPX breakout board on both sides
- all components to the KeyWI PCB
- on the bottom: all headers, the ribbon connector for the keyboard, the 1/8-in audio out jack
- LED, resistors, pots, switches, button
- (if using batteries)
  - 2 battery holder leads to wire them in series
  - a female header to the remaining 2 leads

If you wish to use the KeyWI on battery power (rather than USB), cut P1.07 between the Bela cape and the PocketBeagle, and bend it out so that the connection is severed. Carefullly solder a wire between any VIN pin and P1.07 on the Bela. Pinouts for the Bela Mini can be found [here](https://i.imgur.com/2ek2zQc.png).


## Software

Attach the Bela Mini to a computer via USB, and navigate to [http://bela.local](http://bela.local) in a web browser. Load any of the [patches in the project Github](https://github.com/matthewcaren/KeyWI/tree/master/code) into the IDE, either by using the "Open File" button or by dropping and dragging the file into the IDE window. Then, open the "Settings" tab and find the dropdown menu labeled "Run project on boot." Select the currently open project. This should prompt the code to compile; when a message appears in the console that the project has successfully been set to run on boot, click the "Shutdown Board" button, then disconnect the board from the computer.


## Assembly

Disassemble the MIDI keyboard by removing the screws on the bottom. Unscrew the small screws holding the keys in place  (save these screws!) and remove the keys as well as the rubber strips and printed circuit board that sits underneath. Also unscrew the main circuit board (green, approximately square). The USB connector board (beige, rectangular), as well as the enclosure, knobs, and external buttons, can be discarded.

Use the binding posts to mount the two 3D-printed key mounts to the bottom layer of the enclosure, using the holes drilled earlier. Place the long printed PCB that used to sit under the keys in the MIDI keyboard onto the printed mounts—there are small pegs that should fit into small holes at the top of this PCB. Next, place the rubber strips that fit on top of this board on top such that the buttons line up with the printed circles on the board. With the screws that were previously used to mount the keys in the MIDI keyboard, attach the keys to the new key mounts. The keys should now be securely mounted in place, and when pressed, depress the corresponding button on the rubber strip.

Place the next two layers of the enclosure onto the bottom layer. With the short standoffs, attach the main board from the MIDI keyboard to the bottom layer of the enclosure using the top set of four holes in the upper left of the layer.

Place all remaining layers of the enclosure (except for the cover) onto the KeyWI. Attach about 2 inches of vinyl tubing to one input of the pressure sensor. If the tube does not stay in place, wrap a thin piece of electrical tape around the outside of the input of the sensor to secure it. Attach the pressure sensor to the bottom of the KeyWI PCB via the female headers on the breakout board. With the long standoffs, attach the KeyWI PCB to the bottom layer adjacent to the other board, making sure that the vinyl tube attached to the pressure sensor is exposed on the outside of the KeyWI. If using batteries, place the 4 AAA rechargable batteries into the holders. Place the batteries in the box in the upper right of the KeyWI, and attach the leads to the appropriate header on the KeyWI board. If not using batteries, attach a USB cable to the BeagleBone, and feed the other end of the USB cable out of the enclosure in the same opening as the audio out jack. The KeyWI can be power through USB with any standard USB power supply.

Place the cover layer onto the top of the KeyWI. Using 5 bolts, fasten the KeyWI’s enclosure together. On the bottom of each nut, we also recommend placing an adhesive rubber bumper as to not scratch the surface of any table it is resting on.

Hooray! You're done!
