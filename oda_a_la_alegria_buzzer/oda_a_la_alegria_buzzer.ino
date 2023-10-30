/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"
int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_FS5, 0, NOTE_E5, NOTE_E5,
};
int noteDurations[] = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2
};

int buzzer=9;

void setup() {
  // put your setup code here, to run once:
  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
