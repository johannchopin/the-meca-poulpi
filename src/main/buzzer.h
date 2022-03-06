#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "song.h"

class Buzzer : public InoComponent, public InoComponentWithSinglePin
{
public:
  Buzzer(){};
  Buzzer(int pin) : InoComponentWithSinglePin(pin) {}
  void playTone(Song *song);
  void setup();
  void loop();
};
