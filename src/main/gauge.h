#include <Arduino.h>
#include <functional>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include <Grove_LED_Bar.h>

#pragma once

class Gauge : public InoComponent, public InoComponentWithSinglePin
{
  public:
    Gauge(int pin) : InoComponentWithSinglePin(pin){};

    void setup();
    void loop(float gaugeLevel);
  
  private:
    Grove_LED_Bar *bar = NULL;

};
