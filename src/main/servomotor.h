#include <Arduino.h>
#include <Servo.h>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"


#pragma once

class Servomotor : public InoComponent, public InoComponentWithSinglePin
{
public:
  Servomotor(){};
  Servomotor(int pin) : InoComponentWithSinglePin(pin) {}
  void setup();
  void loop();
  int position;
private:
  Servo motor;
};
