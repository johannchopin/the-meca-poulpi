#include <Arduino.h>
#include "waterbutton.h"

void WaterButton::setup()
{
  Button::setup();
  pinMode(this->ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}
