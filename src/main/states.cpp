#include "states.h"

States::States() {
  this->winkEye = 0;
  this->waterReminderIsActive = true;
  this->sportReminderIsActive = true;
  this->meditationReminderIsActive = true;
  this->taskReminderIsactive = true;

  this->gaugeLevel = 0.0F;
  this->waterGoal = DEFAULT_WATER_GOAL_IN_ML;
  this->waterGlassSizeInMl = DEFAULT_WATER_IN_GLASS_IN_ML;

  int waterGlassSizeInMl;
  float gaugeLevel;

  // Sport
  int sportMusic = Music::DOOM;
  this->sportExercices = {"Définis tes propres exercices!"};

  // Tasks
  this->tasks = {"Définis tes propres tâches!"};
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

void States::incrementWater() {
  this->gaugeLevel += 1;
}
