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
      "Etirement stretching des pectoraux"};
  this->sportExercicesAmount = 3;

  // Tasks
  this->tasks = new String[ITEMS_IN_LIST]{
      "Faire la vaisselle",
      "Passer la serpillère",
      "Nourrir le chat"};
  this->tasksAmount = 3;
}

const PoulpiState States::getCurrent()
{
  return states[current];
}

void States::setCurrent(PoulpiState state)
{
  current = state;
}

int States::getStatesAmount()
{
  return STATE_AMOUNT;
}

int States::getRemindersAmount()
{
  return REMINDER_AMOUNT;
}

void States::goToNextReminder()
{
  // bool candidateFound = false;
  // int candidate;
  // for (int i = 1; i < getRemindersAmount() + 1; i++)
  // {
  //   candidate = (PoulpiState)((lastReminderState + i) % getRemindersAmount());
  //   if (isReminderActive[i % getRemindersAmount()])
  //   {
  //     candidateFound = true;
  //     break;
  //   }
  // }
  // current = candidateFound ? (PoulpiState)candidate : PoulpiState::SLEEPY;
  current = (PoulpiState)((lastReminderState + 1) % getRemindersAmount());
  lastReminderState = current;
}

void States::resetTimer()
{
  lastStateChangeDebounceTime = millis();
}

boolean States::isCurrentStateAReminder()
{
  return current == PoulpiState::TASK_REMINDER ||
         current == PoulpiState::SPORT_REMINDER ||
         current == PoulpiState::WATER_REMINDER ||
         current == PoulpiState::MEDITATION_REMINDER;
}

boolean States::isAwaitingUserFeedback()
{
  return isCurrentStateAReminder() ||
         current == PoulpiState::DOING_MEDITATION ||
         current == PoulpiState::DOING_SPORT;
}

void States::loop()
{
  if (current == PoulpiState::WELCOME)
  {
    bool leftWelcomeState = (millis() - lastStateChangeDebounceTime) > debounceStateWelcomeChangeDelay;
    if (leftWelcomeState)
    {
      setCurrent(PoulpiState::SLEEPY);
      resetTimer();
    }
  }
  else
  {
    bool shouldStateGoNext = !isAwaitingUserFeedback() && (millis() - lastStateChangeDebounceTime) > debounceStateChangeDelay;

    // custom behavior for driking water where the poulpi is happy for a certain amount of seconds before going to sleep again
    if (current == PoulpiState::DRINKING_WATER && (millis() - lastStateChangeDebounceTime) > FIVE_SECONDS)
    {
      setCurrent(PoulpiState::SLEEPY);
      lastStateChangeDebounceTime = millis();
    }
    else if (shouldStateGoNext)
    {
      goToNextReminder();
      resetTimer();
    }
  }
}
