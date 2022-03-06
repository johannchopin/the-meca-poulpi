#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"

class Buzzer : public InoComponent, public InoComponentWithSinglePin
{
public:
  Buzzer(){};
  Buzzer(int pin) : InoComponentWithSinglePin(pin) {}
  void playTone();
  void setup();
  void loop();
};
