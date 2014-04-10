/*
  Demo sketch for using Wii Nunchuk with FunShield
  MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield uses allows you to use the I2C bus to talk
  to sensors. The Wii Nunchuk is an amazing sensor. Using the library
  https://github.com/GabrielBianconi/ArduinoNunchuk
  you can access the following values:
    analogX    accelX    zButton
    analogY    accelY    cButton
               accelZ

  Further exploration:
    - Use the button to control Pong game and joystick
      to control speed?
    - Use accelerometer data to measure and rate your driving.
*/

#include <Wire.h>
#include <ArduinoNunchuk.h>
ArduinoNunchuk nunchuk = ArduinoNunchuk();

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
FunShield fs;            // Instanciate FunShield instance


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.println("FS_08_WiiChuck.ino");
  nunchuk.init();
}


void loop(){

  nunchuk.update();    // update values from chuk

  // map x-joystick values (~30 to 200) to LED values 
  int ledX = map(nunchuk.analogX, 38, 212, -1, 7);
  
  // print values so we can see
  Serial.print("chuckX = ");
  Serial.println(nunchuk.analogX, DEC);

  // display LEDs
  for (int led=0; led < 8; led++){
    if (led <= ledX){
      LED(led, HIGH);
    }
    else{
      LED(led, LOW);
    }
   delay(10); // slow loop down a bit
  }
}
