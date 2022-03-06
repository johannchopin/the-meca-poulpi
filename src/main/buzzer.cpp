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
  int noteToPlay;
  int noteDuration;
  int bestNoteCandidateStartTime = millis();

  for (int noteIndex = 0; noteIndex < this->song->length; noteIndex++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    noteDuration = 1000 / this->song->durations[noteIndex];
    if ((this->startSongTime + noteDuration) > bestNoteCandidateStartTime)
    {
      noteToPlay = this->song->melody[noteIndex];
      if (noteIndex == this->song->length)
      {
        Serial.println("no play");
        isPlaying = false;
        noTone(this->pin);
      }
    }
    else
    {
      bestNoteCandidateStartTime += noteDuration;
    }

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    // int pauseBetweenNotes = noteDuration * 1.30;
    // delay(pauseBetweenNotes);
    // stop the tone playing:
  }

  if (noteToPlay != this->currentNote)
  {
    Serial.println(noteToPlay);
    Serial.println(noteDuration);
    this->currentNote = noteToPlay;
    tone(this->pin, this->currentNote, noteDuration);
  }
}

void Buzzer::loop()
{
  if (isPlaying)
  {
    this->startSongTime = millis();
    this->playSong();
  }
}
