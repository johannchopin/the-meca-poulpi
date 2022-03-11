#pragma once

#include <Arduino.h>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "states.h"

class Potentiometer : public InoComponent, public InoComponentWithSinglePin
{
  public:
    Potentiometer(int pin) : InoComponentWithSinglePin(pin){};
    void setup();
    void loop(States* states);
};