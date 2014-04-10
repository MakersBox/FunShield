/*
  Demo sketch for using ANALOG INPUT on FunShield
  http://www.MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield has the following analog inputs:
    trim();   // returns a 10-bit reading from the poteniometer   
    light();  // returns a 10-bit reading from the photo cell (dark is lower)
    analog(); // returns a 10-bit reading from "ANL" header
              // (same as touch sensor)
    temp();   // returns temperature as a float in celcius
  
  Further exploration:
    - Use the map() function to relate the 10-bit number to a 0 - 767
      value for the RGB() function or 0 - 7 for the LED() function.
      (see http://arduino.cc/en/reference/map )
      
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
FunShield fs;            // Instanciate FunShield instance


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.println("FS_04_Sensors.ino");
}


void loop(){ 
  // get readings
  int trimVal = trim();
  int lightVal = light();
  int tempVal = temp();
  
  // print them out
  Serial.print("trim ");
  Serial.print(trimVal);
  Serial.print("  light ");
  Serial.print(lightVal);
  Serial.print("  temp ");
  Serial.print(tempVal);
  Serial.print("C  analog ");
  Serial.println(analog());
  
  delay(250); // slow the loop down
}