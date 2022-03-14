#include "states.h"

States::States() {
  this->winkEye = 0;
  this->deviceConnectedOnce = false;

  // Reminders
  this->waterReminderIsActive = true;
  this->sportReminderIsActive = true;
  this->meditationReminderIsActive = true;
  this->taskReminderIsActive = true;

  this->waterGlassDrunk = 0;
  this->waterGoal = DEFAULT_WATER_GOAL_IN_ML;
  this->waterGlassSizeInMl = DEFAULT_WATER_IN_GLASS_IN_ML;
  this->waterDrunkAmountInMl = 0;

  // Sport
  this->sportMusic = Music::TAKE_ON_ME;
  this->sportExercices = new String[ITEMS_IN_LIST];
  this->sportExercices[0] = "Définis tes propres exercices!";
  this->sportExercicesAmount = 1; 

  // Tasks
  this->tasks = new String[ITEMS_IN_LIST];
  this->tasks[0] = "Définis tes propres exercices!";
  this->tasksAmount = 1; 
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

void States::drinkOneGlass() {
  this->waterDrunkAmountInMl += this->waterGlassSizeInMl;
  this->waterGlassDrunk += 1;
}
