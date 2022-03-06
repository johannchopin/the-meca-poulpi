#include <Arduino.h>
#include "buzzer.h"
#include "pitches.h"
#include "song.h"

void Buzzer::playTone(Song *song)
{
  this->song = song;
  this->isPlaying = true;
}

void Buzzer::setup()
{
  pinMode(this->pin, INPUT);
}

void Buzzer::playSong()
{
  for (int thisNote = 0; thisNote < this->song->length; thisNote++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / this->song->durations[thisNote];

    tone(4, this->song->melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
  }

  isPlaying = false;
}

void Buzzer::loop()
{
  if (isPlaying)
  {
    this->playSong();
  }
}
