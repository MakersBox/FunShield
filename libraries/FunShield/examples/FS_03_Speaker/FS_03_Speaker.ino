/*
  Demo sketch for using SOUND on FunShield
  http://www.MakersBox.blogspot.com
  648.ken@gmail.com
  Sketch based on http://arduino.cc/en/Tutorial/tone

  The FunShield uses piezo speaker attached to pin D11.

    speaker(frequency, duration); // frequency, 
                                  // duration in milliseconds.
				   
  Further exploration:
    - Convert some simple sheet music into notes for a song.
    - Create a song using the random() function.
    - Use button() to start or stop song.
*/

#include "pitches.h"  // containes note definitions like #define NOTE_E1  41

// sets up and initialize FunShield
#include <FunShield.h>
#include <Wire.h>        // Require for I2C communication
FunShield fs;            // Instanciate FunShield instance


// notes in the melody:
int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_C4, NOTE_A4,
  NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_A4, NOTE_C4, NOTE_A4,
  NOTE_D3, NOTE_D3, NOTE_C3, NOTE_G3, NOTE_A3, NOTE_C3, NOTE_A3 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
   16, 16, 16, 16,
   5, 5, 3, 16, 16, 16, 16,
   5, 5, 3, 11, 11, 11, 11};
   
  
void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // Duration = 1 second / note type
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2500 / noteDurations[thisNote];
    speaker(melody[thisNote], noteDuration);

    //pause for the note's duration plus 30 ms:
    delay(noteDuration + 30);
  }
}

void loop() {
  // no need to repeat the melody.
}