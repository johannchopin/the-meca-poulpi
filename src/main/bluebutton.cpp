#include "bluebutton.h"

void BlueButton::setup()
{
  Button::setup();
  pinMode(this->ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void BlueButton::onClickHandler(States *states)
{
  PoulpiState state = states->getCurrent();

  if (state == PoulpiState::MEDITATION_REMINDER)
  {
    states->setCurrent(PoulpiState::DOING_MEDITATION);
  }
  else if (state == PoulpiState::SPORT_REMINDER)
  {
    states->setCurrent(PoulpiState::DOING_SPORT);
  }
  else if (state == PoulpiState::TASK_REMINDER)
  {
    states->setCurrent(PoulpiState::SLEEPY);
  }
  else if (state == PoulpiState::WATER_REMINDER)
  {
    drinkOneGlass(states);
  }
  else if (state == PoulpiState::DOING_MEDITATION || state == PoulpiState::DOING_SPORT)
  {
    states->setCurrent(PoulpiState::SLEEPY);
  }
  else
  {
    drinkOneGlass(states);
  }

  states->resetTimer();
}

void BlueButton::drinkOneGlass(States *states)
{
  states->waterDrunkAmountInMl += states->waterGlassSizeInMl;
  states->waterGlassDrunk += 1;
  states->setCurrent(PoulpiState::DRINKING_WATER);
}
