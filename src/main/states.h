#pragma once
#include <Arduino.h>
#include <algorithm>
#include "constants.h"

const int STATE_AMOUNT = 9;
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
      WELCOME,
      SLEEPY,
      DOING_MEDITATION,
      DOING_SPORT,
      DRINKING_WATER,
  };

  // index are the values of the REMINDER states in the enum
  bool isReminderActive[REMINDER_AMOUNT] = {
      true,
      true,
      true,
      true};

  const PoulpiState getCurrent();
  void setCurrent(PoulpiState const state);
  void goToNextReminder();
  void resetTimer();
  bool isCurrentStateAReminder();
  bool isAwaitingUserFeedback();
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
  PoulpiState lastReminderState = PoulpiState::SLEEPY;
  unsigned long lastStateChangeDebounceTime = millis();
  unsigned long debounceStateChangeDelay = 3000; // in ms
  unsigned long debounceStateWelcomeChangeDelay = 15500; // in ms
};
