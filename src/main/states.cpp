#include "states.h"

States::States()
{
  this->winkEye = 0;
  this->deviceConnectedOnce = false;

  // Reminders
  this->waterReminderIsActive = true;
  this->sportReminderIsActive = true;
  this->meditationReminderIsActive = true;
  this->taskReminderIsActive = true;

  // Water
  this->waterGlassDrunk = 0;
  this->waterGoal = DEFAULT_WATER_GOAL_IN_ML;
  this->waterGlassSizeInMl = DEFAULT_WATER_IN_GLASS_IN_ML;
  this->waterDrunkAmountInMl = 0;

  // Sport
  this->sportMusic = Music::TAKE_ON_ME;
  this->sportExercices = new String[ITEMS_IN_LIST]{
    "Etirement la pince debout",
    "Etirement extension de la hanche",
    "Etirement stretching des pectoraux"
  };
  this->sportExercicesAmount = 3; 

  // Tasks
  this->tasks = new String[ITEMS_IN_LIST]{
    "Faire la vaisselle",
    "Passer la serpillère",
    "Nourrir le chat"
  };
  this->tasksAmount = 3; 
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
  return STATE_AMOUNT;
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
