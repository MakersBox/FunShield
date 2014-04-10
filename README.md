**The FunShield was designed and produced by:**
> Ken Olsen
> 648.ken@gmail.com
> MakersBox.blogspot.com

The FunShield is an Arduino shield that provides a variety of inputs and outputs for you quickly access. The use of library functions further simplifies the programming experience for beginners. Dedicated pin assignments also facilitate the combination of inputs and outputs in projects without conflicts.

**To use the library**, download and unzip the folder into the "library" folder of your Arduino installation, not the "library" folder of your sketchbook (this is because it uses the Wire library, and can't find it otherwise). If you downloaded from GitHub, you will also need to remove the "-master" from the folder name (Arduino doesn't like dashes in library names). Restart your Arduino IDE and "FunShield" should show up under [File] -> [Examples], down underneath "Firmata".
	
**Initializing the FunShield**

    #include <FunShield.h>
    FunShield fs;   // This gives us access to FunShield functions using "fs"

**LEDs**
The FunShield uses an 74HC595N shift register to control eight LEDs using only three pins on the Arduino.  LEDs are numbered from 0 on the left to 7 on the right (ignore PCB markings). The FunShield library abstracts the details and provides you the following function:
  
    LED(led, state); // led is a number between 0 and 7.
                     // HIGH to turn on or LOW to turn off.

**RGB LED**
The FunShield uses a common cathode RGB LED to display a spectrum of colors.
The FunShield library abstracts the details and provides you the following function:
  
    RGB(RGBcolor);   // Where RGBcolor is an array of the 
                     // three color components like
                     // byte RED[] = {255, 0, 0} or 
                     // an integer between 0 and 767 to display a
                     // color on the spectrum.

**Buttons**
The FunShield has two buttons connected to D7 & D8. The FunShield library abstracts the  details and provides  you the following function:

  button(side);      // returns button state (true if pressed) for given side (LEFT or RIGHT)
                     // LEFT = false, RIGHT = true
The shield also has a touch pad attached to pin A3 and will return true if touched: 

    touch();         // returns true if touched (analog < 1000) 

**Analog Input**
The FunShield has the following analog inputs:

    trim();   // returns a 10-bit reading from the potentiometer   
    light();  // returns a 10-bit reading from the photo cell
    analog(); // returns a 10-bit reading from "ANL" header (same as touch sensor)
    temp();   // returns temperature as a float in Celsius

**Sound**
The FunShield uses piezo speaker attached to pin D1.

    speaker(frequency, duration); // frequency in hertz, duration in milliseconds.

**Motor**
The FunShield has an NPN transistor gate connected to pin D3. Suppling a signal to the   transistor allows current to flow through it. This allows us to supply more current to a device (like a motor) than the digital pin can supply alone (only 40 mA). The current limit to the device is dependent on the transistor, usually 500 mA, or enough to power a small hobby motor. Be careful, as the transistor can get hot! 
See http://arduino.cc/en/Tutorial/PWM to learn how PWM controls speed.
    
	motor(pmw_value);         // can be a value between 0 (OFF) and 255 (100% PWM).
	
**I2C**
The FunShield has two mirrored I2C connection on the right side of the board. This allows it to communicate to other devices using the Wire library. Each device must have an unique 7-bit address number. 

    #define ME 20             // this shield's I2C address
    #define FRIEND 21         // connected shield's I2C address
    FunShield fs(ME, FRIEND); // This initializes board and pins

Each of the following functions work by prefacing arguments with an address of the connected FunShield:
  
    LED(address, led, state);
    RGB(address, color);
    speaker(address, frequency, duration);
    motor(speed);

The base LED() fuction will also send an led > 7 to the opposite boards led from highest to lowest (i.e. 15 - led).

    LED(14, HIGH);         // lights LED 1 on attached FunShield
    
You can also access sensor and button values from the other board:
    
    light(address);        // returns light value from other board
    trim(address);
    button(address, side);
	

