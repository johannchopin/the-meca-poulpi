#include "states.h"
#include <Arduino.h>
#include <algorithm>

States::States() {}

const char *States::getCurrent()
{
  return states[current];
}

void States::setState(char const *state)
{
  int matchingIndex = 0;
  for (int i = 0; i < getStatesAmount(); i++)
  {
    if (states[i] == state)
    {
      matchingIndex = i;
    }
  }

  current = matchingIndex;
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

void States::loop()
{
  bool shouldStateGoNext = (millis() - lastStateChangeDebounceTime) > debounceStateChangeDelay;
  if (shouldStateGoNext)
  {
    goToNext();
    lastStateChangeDebounceTime = millis();
  }
}
