#include "button.h"
#include <Arduino.h>
#include <functional>

void Gauge::setup()
{
  pinMode(this->pin, OUTPUT);
}

void Gauge::loop()
{
    
}

void Gauge::increaseLevel() {
    level(level + 1)
}

void Gauge::decreaseLevel() {
    level(level - 1)
}