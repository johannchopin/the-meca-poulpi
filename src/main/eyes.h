#include <Arduino.h>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"

#pragma once

class Eyes : public InoComponent
{
public:
  Eyes(){};
  Eyes(int pinEyeLeft, int pinEyeRight){
    this->pinEyeLeft = pinEyeLeft;
    this->pinEyeRight = pinEyeRight;
  };
  void loop();
  void setup();
  int pinEyeLeft;
  int pinEyeRight;
};
