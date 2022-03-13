#include "gauge.h"

void Gauge::setup()
{
  pinMode(this->pin, OUTPUT);
  this->bar = new Grove_LED_Bar((int)this->pin, this->pin + 1, false);
}

void Gauge::loop(float gaugeLevel)
{
  this->bar->setLevel(gaugeLevel);
}
