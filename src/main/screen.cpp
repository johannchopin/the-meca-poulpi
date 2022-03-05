#include <Wire.h>
#include "screen.h"
#include "rgb_lcd.h"
#include <string.h>

rgb_lcd lcd;

void Screen::colorBackground() {
  int colorR = 15;
  int colorG = 75;
  int colorB = 185;

  if (strcmp(currentState, "meditation") == 0)
  {
    colorR = 19;
    colorB = 219;
    colorG = 79;
  } else if (strcmp(currentState, "sport") == 0)
  {
    colorR = 253;
    colorB = 229;
    colorG = 39;
  } else if (strcmp(currentState, "water") == 0)
  {
    colorR = 94;
    colorB = 173;
    colorG = 191;
  } else if (strcmp(currentState, "tasks") == 0)
  {
    colorR = 248;
    colorB = 99;
    colorG = 30;
  }

  lcd.setRGB(colorR, colorG, colorB);
}

void Screen::setup(char *state)
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
  lcd.print(currentState);
}

void Screen::loop(char *state)
{
  int stateHasChanged = strcmp(state, currentState) != 0;
  if (stateHasChanged)
  {
    currentState = state;
    onStateChange();
  }
}
