/*
  Demo sketch for using I2C with a pair of FunShields
  MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield has two mirrored I2C connection on the right side of the board.
  This allows it to communicate to other devices using the Wire library.
  Each device must have an unique 7-bit address number.
  Each of the following functions work by prefacing arguments with an address
  of the connected FunShield:
  
    LED(address, led, state);
    RGB(address, color);
    speaker(address, frequency, duration);
	motor(speed);
    
  The base LED() fuction will also send an led > 7 to the opposite boards led from
  highest to lowest (i.e. 15 - led).
    
  You can also access sensor and button values from the other board:
    light(address);  // returns light value from other board
    touch(address);
    trim(address);
    button(address, side);

  Further exploration:
    - Make a pong game using both board! 
    - Make a count-down timer.
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>

#define ME 21             // this shield's I2C address
#define FRIEND 20         // connected shield's I2C address

FunShield fs(ME, FRIEND); // This initializes board and pins

// variable declarations
int led = 0;              // Can be any led from 0 to 7
int delayTime = 100;     // Delay time in milliseconds


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.print("I AM I2C# ");
  Serial.print(ME);
  Serial.println(" (acting as slave)");
}


void loop(){
  // I do nothing except respond to I2C commands and request!
}



