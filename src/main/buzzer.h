#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "song.h"

class Buzzer : public InoComponent, public InoComponentWithSinglePin
{
public:
  Buzzer(){};
  Buzzer(int pin) : InoComponentWithSinglePin(pin) {}
  void playTone(Song *song);
  void stopTone();
  void setup();
  void loop();
  bool isPlaying = false;
  Song *song;
private:
  void playSong();
  void setDurationsTimestamp();
  void playNote(int note);
  int *durationsTimestamp;
  unsigned long startSongTime = 0;
  int currentNote;
};
