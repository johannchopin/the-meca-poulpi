#include <Arduino.h>
#include <Wire.h>
#include "constants.h"
#include "screen.h"
#include "rgb_lcd.h"
#include <string.h>

rgb_lcd lcd;

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
  else if (currentState == PoulpiState::SPORT || currentState == PoulpiState::SPORT)
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

void Screen::setup(PoulpiState state)
{
  currentState = state;
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  onStateChange();
}

void Screen::onStateChange()
{
  lcd.clear();
  colorBackground();
  lcd.setCursor(0, 1);
  // TODO: display the according text of the new state
  lcd.print(currentState);
}

void Screen::loop(PoulpiState state)
{
  bool stateHasChanged = (state != currentState);
  if (stateHasChanged)
  {
    currentState = state;
    onStateChange();
  }
}
