#include "screen.h"

rgb_lcd lcd;

void Screen::setup(States *states)
{
  updateLocalStateFromStates(states);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  onStateChange();
}

void Screen::loop(States *states)
{
  PoulpiState currentGlobalState = states->getCurrent();
  int waterGlassSizeInMl = states->waterGlassSizeInMl;

  bool stateHasChanged = (currentState != currentGlobalState || waterGlassSizeInMlDisplayed != waterGlassSizeInMl);
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

  // TODO: display the according text of the new state
  // if (currentState == PoulpiState::SLEEPY) {
  lcd.setCursor(0, 0);
  lcd.print("Zzz  Ml du verre: ");
  lcd.setCursor(0, 1);
  lcd.print("Zzz");
  int startCol = (waterGlassSizeInMlDisplayed == 0) ? 12 : (waterGlassSizeInMlDisplayed < 100) ? 11
                                                       : (waterGlassSizeInMlDisplayed < 1000)  ? 10
                                                                                               : 9;
  lcd.setCursor(startCol, 1);
  lcd.print(waterGlassSizeInMlDisplayed);
  lcd.print(" ml");
  //} else {
  // lcd.print(currentState);
  //}
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

  if (currentState == PoulpiState::MEDITATION || currentState == PoulpiState::DO_MEDITATION)
  {
    colorR = 19;
    colorB = 219;
    colorG = 79;
  }
  else if (currentState == PoulpiState::SPORT || currentState == PoulpiState::DO_SPORT)
  {
    colorR = 253;
    colorB = 229;
    colorG = 39;
  }
  else if (currentState == PoulpiState::WATER)
  {
    colorR = 94;
    colorB = 173;
    colorG = 191;
  }
  else if (currentState == PoulpiState::TASKS)
  {
    colorR = 248;
    colorB = 99;
    colorG = 30;
  }

  lcd.setRGB(colorR, colorG, colorB);
}
