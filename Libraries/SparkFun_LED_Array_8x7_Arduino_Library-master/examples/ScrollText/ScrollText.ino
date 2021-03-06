/****************************************************************
ScrollText.ino
LED Array 8x7 Charlieplex
Updated for r00tz badge by Pamela Cortez
Shawn Hymel @ SparkFun Electronics
February 3, 2015
https://github.com/sparkfun/LED_Array_8x7_Charlieplex

Scrolls text across the LED array for 10 seconds.

Hardware Connections:

IMPORTANT:  The Charlieplex LED board is designed for 2.0 - 5.2V!
            Higher voltages can damage the LEDs.

 Arduino Pin | Charlieplex Board
 ------------|------------------
      9      |         A
      8      |         B
      7      |         C
      6      |         D
      5      |         E
      4      |         F
      3      |         G
      2      |         H

Resources:
Include Chaplex.h, SparkFun_LED_8x7.h
The Chaplex library can be found at: 
http://playground.arduino.cc/Code/Chaplex

Development environment specifics:
Written in Arduino 1.6.7
Tested with SparkFun RedBoard and BadgerStick (Interactive Badge)

This code is released under the [MIT License](http://opensource.org/licenses/MIT).

Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.
****************************************************************/

#include <SparkFun_LED_8x7.h>
#include <Chaplex.h>

// Global variables
static byte led_pins[] = {9, 8, 7, 6, 5, 4, 3, 2}; // Pins for LEDs

void setup() {

  // Initialize LED array
  Plex.init(led_pins);
  
  // Clear display
  Plex.clear();
  Plex.display();
}

void loop() {
  
  // Scroll text 2 times (blocking)
  Plex.scrollText("LIFELINE;)", 2, true);
  
  // Scroll text until we stop it
  Plex.scrollText("DEFCON r00tz");
  delay(10000);
  Plex.stopScrolling();
  delay(1000);
}
