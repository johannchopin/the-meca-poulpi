#pragma once

class InoComponentWithSinglePin
{
public:
  InoComponentWithSinglePin(){};
  InoComponentWithSinglePin(int pin)
  {
    this->pin = pin;
  };
  int pin;
};
