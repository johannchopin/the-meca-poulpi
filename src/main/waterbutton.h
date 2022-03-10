#include <Arduino.h>
#include <functional>
#include "button.h"

class WaterButton : public Button
{
public:
  WaterButton(){};
  WaterButton(int pin, int ledPin) : Button(pin)
  {
    this->ledPin = ledPin;
  }
  int ledPin;
  void setup();
};