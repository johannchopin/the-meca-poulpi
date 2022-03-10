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
  void startTentaculeAnimation();
  void stopTentaculeAnimation();
  int position = 16;
  int POSITION_UP = 0;
  int POSITION_DOWN = 16;

private:
  Servo motor;
  int tentaculeDebounceTime = 0;
  int tentaculeDelay = 500;
  bool isTentaculeAnimated = false;
  void toggleTentacule();
};
