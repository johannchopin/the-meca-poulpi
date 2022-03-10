#pragma once
#include "constants.h"

const int STATE_AMOUNT = 7;

class States
{
public:
  States();
  const PoulpiState states[STATE_AMOUNT] = {
    SLEEPY,
    MEDITATION,
    DO_MEDITATION,
    SPORT,
    DO_SPORT,
    WATER,
    TASKS,
  };
  const *statesName[STATE_AMOUNT] = {"endormie", "en méditation", "médite", "en sport", "fait du sport", "mode eau", "tâches"};
  const char *getStateName(PoulpiState state);
  const PoulpiState getCurrent();
  void goToNext();
  int getStatesAmount();
  void setState(PoulpiState const state);
  void loop();

  float gaugeLevel; 
  int winkEye;

private:
  PoulpiState current = PoulpiState::SLEEPY;
  unsigned long lastStateChangeDebounceTime = 0;
  unsigned long debounceStateChangeDelay = 3000; // in ms
};
