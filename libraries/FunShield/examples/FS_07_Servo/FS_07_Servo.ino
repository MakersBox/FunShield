/*
  Demo sketch for using the Servo header on the FunShield
  MakersBox.blogspot.com
  648.ken@gmail.com

  The servo header is marked "- + SERV" and is attached to `servoPin` (D5). See the [standard servo examples](http://arduino.cc/en/reference/servo).
  
  Further exploration:
    - 
*/

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
#include <Servo.h>

#define ME 21             // this shield's I2C address
#define FRIEND 20         // connected shield's I2C address
FunShield fs(ME, FRIEND); // Instanciate FunShield instance

// variable declarations
int led = 0;              // Can be any led from 0 to 7
int delayTime = 100;     // Delay time in milliseconds

Servo myServo;


void setup() {
  Serial.begin(9600);     // Setup serial communications for troubleshooting
  Serial.print("FS_07_Servo.ino");
  myServo.attach(servoPin);
}


void loop(){
  // read potentiometer
  int t = trim();
  
  // convert 10-bit to 0 - 180 degree angle
  byte angle = map(t, 0, 1023, 0, 180);
  
  // move servo
  myServo.write(angle);
  
  // print angle
  Serial.print("angle = ");
  Serial.println(angle);  
  delay(10); // delay loop a bit

}



