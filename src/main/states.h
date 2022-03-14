#pragma once
#include <Arduino.h>
#include <algorithm>
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
  String *sportExercices;   // should be enough
  int sportExercicesAmount; // real amount of exercies in sportExercices

  // Tasks
  String *tasks;   // should be enough
  int tasksAmount; // real amount of task in tasks

private:
  PoulpiState current = PoulpiState::SLEEPY;
  unsigned long lastStateChangeDebounceTime = 0;
  unsigned long debounceStateChangeDelay = 3000; // in ms
};
