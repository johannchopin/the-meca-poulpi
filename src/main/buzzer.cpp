#include <Arduino.h>
#include "buzzer.h"
#include "pitches.h"
#include "song.h"

void Buzzer::stopTone()
{
  isPlaying = false;
  noTone(this->pin);
}

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
  int dest[this->song->length];

  for (int durationIndex = 0; durationIndex < this->song->length; durationIndex++)
  {
    int noteDuration = 1000 / this->song->durations[durationIndex];
    current += noteDuration;
    dest[durationIndex] = current;
  }

  this->durationsTimestamp = dest;
}

void Buzzer::playNote(int note)
{
  if (note != this->currentNote)
  {
    noTone(this->pin);
    this->currentNote = note;
    tone(this->pin, this->currentNote, 1000);
  }
}

void Buzzer::playSong()
{
  int current = millis();

  for (int noteIndex = 0; noteIndex < this->song->length; noteIndex++)
  {
    bool noteShouldBePlayed = this->durationsTimestamp[noteIndex] >= current;

    if (noteShouldBePlayed)
    {
      this->playNote(this->song->melody[noteIndex]);

      bool isLastNote = noteIndex + 1 == this->song->length;
      if (isLastNote)
      {
        this->stopTone();
      }

      break;
    }
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