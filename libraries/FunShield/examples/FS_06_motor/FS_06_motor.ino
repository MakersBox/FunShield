/*
  Demo sketch for using MOTOR header on FunShield
  MakersBox.blogspot.com
  648.ken@gmail.com

  The FunShield has an NPN transistor gate connected to pin D3. Suppling a signal to the
  transistor allows current to flow through it. This allows us to supply more current
  to a device (like a motor) than the digital pin can supply alone (only 40 mA). The
  current limit to the device is dependent on the transitor, usually 500 mA, or enough
  to power a small hobby motor. Be careful, as the transistor can get hot! 
  See http://arduino.cc/en/Tutorial/PWM to learn how PWM controls speed.
  
    motor(pmw_value); // can be a value between 0 (OFF) and 255 (100% PWM).

  Further exploration:
    - Use trim() to control motor speed.
    - Use LEDs to indicate motor speed (map 0-255 to 0-7).
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
FunShield fs;            // Instanciate FunShield instance


// variable declarations
int speed;
int stallSpeed = 100;  // skip low PWM values since motor stalls
int delayTime = 10;    // control how fast motor speed changes


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.println("FS_06_motor.ino");
}


void loop(){
  // speed up (skip low numbers since motor stalls)
  for (speed = stallSpeed; speed < 255; speed++){
    motor(speed);
    Serial.print("speed=");
    Serial.println(speed);
    delay(delayTime);
  }
  
  // slow down
  for (speed = 255; speed >= stallSpeed; speed--){
    motor(speed);
    Serial.print("speed=");
    Serial.println(speed);
    delay(delayTime);
  }  
  
  // off for a moment
  speed = 0;
  motor(speed);
  Serial.print("speed=");
  Serial.println(speed);
  delay(2000);
}
