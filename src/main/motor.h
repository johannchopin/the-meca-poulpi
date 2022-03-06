#include <Arduino.h>
#include <functional>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"

#pragma once

class Motor : public InoComponent, public InoComponentWithSinglePin
{
public:
  Motor(){};
  Motor(int pin) : InoComponentWithSinglePin(pin){};
  void onClick(std::function<void()> callbackPtr);
  void loop();
  void setup();

private:
  bool isRotating = false;
};
