#include "screen.h"

Screen::Screen()
{
    this->lcd = new rgb_lcd();
}

void Screen::setup(States *states)
{
  this->lcd->begin(16, 2);

  // init default displayStrings
  this->displayStrings = new String[STATE_AMOUNT];
  this->displayStrings[PoulpiState::SLEEPY] = "ZzzzzzZ"; // dynamic case handled in the onStateChange
  this->displayStrings[PoulpiState::TASK_REMINDER] = this->getRandomDescriptions(states->tasks, states->tasksAmount);
  this->displayStrings[PoulpiState::WATER_REMINDER] = "Le moment de boire de l'eau";
  this->displayStrings[PoulpiState::DOING_SPORT] = this->getRandomDescriptions(states->sportExercices, states->sportExercicesAmount);
  this->displayStrings[PoulpiState::SPORT_REMINDER] = "Le moment de faire du sport";
  this->displayStrings[PoulpiState::MEDITATION_REMINDER] = "Le moment de meditation";

  updateLocalStateFromStates(states);
  onStateChange();
}

void Screen::loop(States *states)
{
  bool stateHasChanged = (currentState != states->getCurrent() || (states->getCurrent() == PoulpiState::SLEEPY && waterGlassSizeInMlDisplayed != states->waterGlassSizeInMl));
  if (stateHasChanged)
  {
    updateLocalStateFromStates(states);
    onStateChange();
  }
}

void Screen::onStateChange()
{
  lcd->clear();
  colorBackground();

  this->lcd->setCursor(0, 0);
  if(currentState == PoulpiState::SLEEPY) {
    lcd->print("Zzz  Ml du verre: ");
    lcd->setCursor(0, 1);
    lcd->print("Zzz");
    int startCol = (waterGlassSizeInMlDisplayed == 0) ? 12 : (waterGlassSizeInMlDisplayed < 100) ? 11
                                                        : (waterGlassSizeInMlDisplayed < 1000)  ? 10
                                                                                                : 9;
    lcd->setCursor(startCol, 1);
    lcd->print(waterGlassSizeInMlDisplayed);
    lcd->print(" ml");
  } else {
    this->displayMessage(this->displayStrings[this->currentState]);
  }
}

void Screen::updateLocalStateFromStates(States *states)
{
  currentState = states->getCurrent();
  waterGlassSizeInMlDisplayed = states->waterGlassSizeInMl;
}

void Screen::colorBackground()
{
  int colorR = 15;
  int colorG = 75;
  int colorB = 185;

  if (currentState == PoulpiState::MEDITATION_REMINDER || currentState == PoulpiState::DOING_MEDITATION)
  {
    colorR = 19;
    colorB = 219;
    colorG = 79;
  }
  else if (currentState == PoulpiState::SPORT_REMINDER || currentState == PoulpiState::SPORT_REMINDER)
  {
    colorR = 253;
    colorB = 229;
    colorG = 39;
  }
  else if (currentState == PoulpiState::WATER_REMINDER)
  {
    colorR = 94;
    colorB = 173;
    colorG = 191;
  }
  else if (currentState == PoulpiState::TASK_REMINDER)
  {
    colorR = 248;
    colorB = 99;
    colorG = 30;
  }

  this->lcd->setRGB(colorR, colorG, colorB);
}

String Screen::getRandomDescriptions(String* descriptions, int size)
{
  int randomIndex = random(size);
  return descriptions[randomIndex];
}

void Screen::displayMessage(String message)
{
  if (message.length() <= 16)
  {
    this->lcd->print(message);
  } else {
    String firstPart = message.substring(0, 16);
    String secondPart = message.substring(16, message.length());

    this->lcd->print(firstPart);
    this->lcd->setCursor(0, 1);
    this->lcd->print(secondPart);
  }
}
