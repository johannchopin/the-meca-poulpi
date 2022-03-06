#include <Arduino.h>
#include "waterbutton.h"

void WaterButton::setup()
{
  pinMode(this->pin, INPUT);
  pinMode(this->ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}
