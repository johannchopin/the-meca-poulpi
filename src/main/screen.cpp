#include "screen.h"

rgb_lcd lcd;

Screen::Screen() {}

void Screen::setup(States *states)
{
  lcd.begin(16, 2);

  // init default displayStrings. *May* contain a value for a state.
  this->displayStrings = new String[STATE_AMOUNT];
  this->displayStrings[PoulpiState::WELCOME] = "Hello je m'appelPoulpi ^-^";
  this->displayStrings[PoulpiState::TASK_REMINDER] = this->getRandomDescriptions(states->tasks, states->tasksAmount);
  this->displayStrings[PoulpiState::SPORT_REMINDER] = "Faire du sport !";
  this->displayStrings[PoulpiState::MEDITATION_REMINDER] = "Meditation Time !";
  this->displayStrings[PoulpiState::DOING_SPORT] = this->getRandomDescriptions(states->sportExercices, states->sportExercicesAmount);
  this->displayStrings[PoulpiState::DOING_MEDITATION] = "Relaxxxxxxxxxxxx";
  this->displayStrings[PoulpiState::DRINKING_WATER] = "Un verre bu     Poulpi -> ^_^";

  updateLocalStateFromStates(states);
  onStateChange();
}

void Screen::loop(States *states)
{
  bool shouldScreenDisplayWaterValue = states->getCurrent() == PoulpiState::WATER_REMINDER || states->getCurrent() == PoulpiState::SLEEPY;
  bool updateWaterValue = shouldScreenDisplayWaterValue && waterGlassSizeInMlDisplayed != states->waterGlassSizeInMl;
  bool stateHasChanged = currentState != states->getCurrent() || updateWaterValue;
  if (stateHasChanged)
  {
    updateLocalStateFromStates(states);
    onStateChange();
  }
}

void Screen::onStateChange()
{
  lcd.clear();
  colorBackground();

  lcd.setCursor(0, 0);
  bool shouldStatePrintGlassSize = currentState == PoulpiState::SLEEPY || currentState == PoulpiState::WATER_REMINDER;
  if (currentState == PoulpiState::SLEEPY)
  {
    lcd.print("Zzz  Ml du verre");
    lcd.setCursor(0, 1);
    lcd.print("Zzz");
  }
  else if (currentState == PoulpiState::WATER_REMINDER)
  {
    lcd.print("Boire de l'eau");
  }
  else
  {
    this->displayMessage(this->displayStrings[this->currentState]);
  }

  if (shouldStatePrintGlassSize)
  {
    int waterGlassSizeCol = LocalUtils::mlValueStartColOnScreen(waterGlassSizeInMlDisplayed);
    lcd.setCursor(waterGlassSizeCol, 1);
    lcd.print(waterGlassSizeInMlDisplayed);
    lcd.print(" ml");
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
    colorB = 79;
    colorG = 219;
  }
  else if (currentState == PoulpiState::WELCOME)
  {
    colorR = 246;
    colorB = 0;
    colorG = 135;
  }
  else if (currentState == PoulpiState::SPORT_REMINDER || currentState == PoulpiState::DOING_SPORT)
  {
    colorR = 253;
    colorB = 229;
    colorG = 39;
  }
  else if (currentState == PoulpiState::WATER_REMINDER || currentState == PoulpiState::DRINKING_WATER)
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

  lcd.setRGB(colorR, colorG, colorB);
}

String Screen::getRandomDescriptions(String *descriptions, int size)
{
  int randomIndex = random(size);
  return descriptions[randomIndex];
}

void Screen::displayMessage(String message)
{
  if (message.length() <= 16)
  {
    lcd.print(message);
  }
  else
  {
    String firstPart = message.substring(0, 16);
    String secondPart = message.substring(16, message.length());

    lcd.print(firstPart);
    lcd.setCursor(0, 1);
    lcd.print(secondPart);
  }
}
