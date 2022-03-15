#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "song.h"

#pragma once

// tempo to play the music -> default 1000ms
#define DEFAULT_TEMPO 1000

class Buzzer : public InoComponent, public InoComponentWithSinglePin
{
public:
  Buzzer(){};
  Buzzer(int pin) : InoComponentWithSinglePin(pin) {}
  void playTone(Song *song, int noteDurationFactor);
  void stopTone();
  void setup();
  void loop();
  bool isPlaying = false;
  Song *song;
private:
  void playSong();
  void setDurationsTimestamp(int noteDurationFactor);
  void playNote(int note);
  int *durationsTimestamp = NULL;
  int currentNote;
};
