#include <Arduino.h>
#include <functional>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"

#pragma once

class Gauge : public InoComponent, public InoComponentWithSinglePin
{
public:
  Gauge(){};
  Gauge(int pin) : InoComponentWithSinglePin(pin){};

  void loop();
  void setup();

  void increaseLevel();
  void decreaseLevel();

private:
  int level = 0;
};
