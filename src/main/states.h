#pragma once
#include <Arduino.h>
#include <algorithm>
#include "constants.h"

const int STATE_AMOUNT = 8;

class States
{
public:
  States();

  const PoulpiState states[STATE_AMOUNT] = {
      SLEEPY,
      MEDITATION_REMINDER,
      DOING_MEDITATION,
      SPORT_REMINDER,
      DOING_SPORT,
      DRINKING_WATER,
      WATER_REMINDER,
      TASK_REMINDER,
  };

  const PoulpiState getCurrent();
  void setCurrent(PoulpiState const state);
  void goToNext();
  int getStatesAmount();
  void loop();

  int winkEye;
  bool deviceConnectedOnce;

  // Reminders
  bool waterReminderIsActive;
  bool sportReminderIsActive;
  bool meditationReminderIsActive;
  bool taskReminderIsActive;

  // Water
  void drinkOneGlass();
  unsigned int waterGoal;
  int waterGlassSizeInMl;
  int waterGlassDrunk;
  int waterDrunkAmountInMl;

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
  unsigned long debounceStateChangeDelay = 10000; // in ms
};
