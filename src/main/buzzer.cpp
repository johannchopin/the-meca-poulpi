#include <Arduino.h>
#include "buzzer.h"
#include "pitches.h"
#include "song.h"

void Buzzer::playTone(Song *song)
{
  this->song = song;
  this->setDurationsTimestamp();
  this->isPlaying = true;
}

void Buzzer::setup()
{
  pinMode(this->pin, INPUT);
}

void Buzzer::setDurationsTimestamp()
{
  int current = millis();

  for (int durationIndex = 0; durationIndex < this->song->length; durationIndex++)
  {
    int noteDuration = 1000 / this->song->durations[durationIndex];
    current += noteDuration;
    this->song->durations[durationIndex] = current;
  }
}

void Buzzer::playSong()
{
  int noteToPlay;
  int current = millis();

  for (int noteIndex = 0; noteIndex < this->song->length; noteIndex++)
  {
    bool noteShouldBePlayed = this->song->durations[noteIndex] >= current;
    if (noteShouldBePlayed)
    {
      noteToPlay = this->song->melody[noteIndex];
      if (noteIndex == this->song->length)
      {
        Serial.println("no play");
        isPlaying = false;
        noTone(this->pin);
      }

      break;
    }
  }

  if (noteToPlay != this->currentNote)
  {
    Serial.println(noteToPlay);
    this->currentNote = noteToPlay;
    tone(this->pin, this->currentNote, 1000);
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
