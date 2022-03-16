#pragma once
#include <Arduino.h>
#include <algorithm>
#include "constants.h"

const int STATE_AMOUNT = 8;
const int REMINDER_AMOUNT = 4;

class States
{
public:
  States();

  const PoulpiState states[STATE_AMOUNT] = {
      MEDITATION_REMINDER,
      SPORT_REMINDER,
      WATER_REMINDER,
      TASK_REMINDER,
      SLEEPY,
      DOING_MEDITATION,
      DOING_SPORT,
      DRINKING_WATER,
  };

  const PoulpiState getCurrent();
  void setCurrent(PoulpiState const state);
  void goToNext();
  int getStatesAmount();
  int getRemindersAmount();
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
