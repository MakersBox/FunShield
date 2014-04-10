/*
  Demo sketch for using LEDs on FunShield
  MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield uses an 74HC595N shift register to control
  eight LEDs using only three pins on the Arduino
  (see http://arduino.cc/en/tutorial/ShiftOut ). 
  The FunShield library abstracts the details and provides 
  you the following function:
  
    LED(led, state); // led is a number between 0 and 7, 
                     // state is HIGH to turn on or LOW to turn off.

  Further exploration:
    - Use a for loop to turn all LEDs on and off one at time.
    - Use random() to pick the led and delay time.
        (see http://arduino.cc/en/Reference/Random ).
    - Display binary numbers between 0 and 255.
    - Use the analog trim() value to control number of LEDs displayed.
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>         // Require for I2C communication
FunShield fs;             // Instanciate FunShield instance

// variable declarations
int led = 0;              // Can be any led from 0 to 7
int delayTime = 1000;     // Delay time in milliseconds


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.println("FS_01_LED.ino");
}


void loop(){
  LED(led, HIGH); // turn LED on
  delay(delayTime);

  LED(led, LOW);  // turn LED off
  delay(delayTime);
}