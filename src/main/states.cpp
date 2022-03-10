#include "states.h"
#include <Arduino.h>
#include <algorithm>

States::States() {
  this->gaugeLevel = 0.0F;
  this->waterObjective = DEFAULT_WATER_TO_DRINK_IN_ML;
  this->winkEye = 0;
}

const PoulpiState States::getCurrent()
{
  return states[current];
}

void States::setState(PoulpiState state)
{
  current = state;
}

int States::getStatesAmount()
{
  return sizeof(states) / sizeof(states[0]);
}

void States::goToNext()
{
  current = (PoulpiState)((current + 1) % getStatesAmount());
}

void States::loop()
{
  bool shouldStateGoNext = (millis() - lastStateChangeDebounceTime) > debounceStateChangeDelay;
  if (shouldStateGoNext)
  {
    goToNext();
    lastStateChangeDebounceTime = millis();
  }
}

void States::incrementWater() {
  this->gaugeLevel += 1;
}
