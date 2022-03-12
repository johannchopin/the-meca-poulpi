#pragma once
#include <Arduino.h>
#include <algorithm>
#include "constants.h"
#include "list.h"

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

  const PoulpiState getCurrent();
  void goToNext();
  int getStatesAmount();
  void setState(PoulpiState const state);
  void loop();

  int winkEye;

  // Reminders
  bool waterReminderIsActive;
  bool sportReminderIsActive;
  bool meditationReminderIsActive;
  bool taskReminderIsActive;

  // Water
  void incrementWater();
  unsigned int waterGoal;
  int waterGlassSizeInMl;
  float gaugeLevel;

  // Sport
  int sportMusic;
  list<string> sportExercices;

  // Tasks
  list<string> tasks;

private:
  PoulpiState current = PoulpiState::SLEEPY;
  unsigned long lastStateChangeDebounceTime = 0;
  unsigned long debounceStateChangeDelay = 3000; // in ms
};
