#include "states.h"
#include <Arduino.h>

States::States() {}

const char *States::getCurrent()
{
  return states[current];
}

int States::getStatesAmount()
{
  return sizeof(states) / sizeof(states[0]);
}

void States::goToNext()
{
  bool isCurrentLast = current + 1 >= getStatesAmount();
  if (isCurrentLast)
  {
    current = 0;
  }
  else
  {
    current += 1;
  }
}
