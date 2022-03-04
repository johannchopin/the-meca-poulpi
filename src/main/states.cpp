#include "states.h"

States::States() {}

const char* States::getCurrent() {
  return this->states[this->current];
}

int States::getStatesAmount() {
  return sizeof(this->states)/sizeof(this->states[0]);
}

void States::goToNext() {
  bool isCurrentLast = this->current + 1 >= this->getStatesAmount();
  if (isCurrentLast)
  {
    this->current = 0;
  } else
  {
    this->current += 1;
  }
}