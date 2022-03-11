#include <Arduino.h>
#include <ChainableLED.h>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "inocomponentwithstate.h"

#pragma once

class Eyes : public InoComponent,
             public InoComponentWithSinglePin,
             public InoComponentWithState
{
public:
  Eyes(){};
  Eyes(int pin) : InoComponentWithSinglePin(pin){};
  void loop(PoulpiState state);
  void setup();
  void setRgbColor(int r, int g, int b);

private:
  ChainableLED *leds;
  void onStateChange();
};
