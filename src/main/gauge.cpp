#include "gauge.h"

void Gauge::setup()
{
  pinMode(this->pin, OUTPUT);
  this->bar = new Grove_LED_Bar((int)this->pin, this->pin - 1, false);
  this->bar->begin();
  this->level = 0.0F;
  this->bar->setLevel(this->level);
}

void Gauge::loop(int waterGoal, int waterDrunkAmount)
{
  float progress = (float)waterDrunkAmount / waterGoal * 10;

  if (progress > 10.0)
  {
    progress = 10.0;
  }

  if (progress != this->level)
  {
    this->level = progress;
    this->bar->setLevel(this->level);
  }
}
