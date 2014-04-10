/*
  Demo sketch for using BUTTONs on FunShield
  MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield has two buttons connected to D7 & D8.
  The FunShield library abstracts the details and provides 
  you the following function:
  
    button(side); // returns button state (true if pressed) for given side 
                  // (LEFT = false, RIGHT = true)
  
  The shield also has a touch pad attached to pin A3 and will return true if touched:
 
   touch();       // returns true if touched (analog < 1000) 
    

  Further exploration:
    - Use button() or touch() to trigger different light patterns or sound.
    - Check button() during setup() to allow for different program
      functionalilty (i.e. button held down during reset).
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
FunShield fs;            // Instanciate FunShield instance


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.println("FunShield_Buttons.ino");
}


void loop(){
  boolean buttonL = button(LEFT);
  boolean buttonR = button(RIGHT);
  boolean touched = touch();
  
  Serial.print("L=");
  Serial.print(buttonL);
  Serial.print(" R=");
  Serial.print(buttonR);
  Serial.print(" T=");
  Serial.println(touched);
  
  if (buttonL){ // turn on left most LED if L button pushed
    LED(0, HIGH);
  }
  else{
    LED(0, LOW);
  }

  if (buttonR){ // turn on right most LED if R button pushed
    LED(7, HIGH);
  }
  else{
    LED(7, LOW);
  }  
  
  delay(100); // slow the loop down a bit
}