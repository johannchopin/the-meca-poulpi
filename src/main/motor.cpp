#include "motor.h"
#include <Arduino.h>
#include <functional>

void Motor::setup()
{
  pinMode(this->pin, INPUT);
}
