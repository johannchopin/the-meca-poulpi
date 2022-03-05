#include <Wire.h>
#include "screen.h"
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void Screen::setup()
{
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("hello, world!");
}

void Screen::loop(char *state)
{
  lcd.setCursor(0, 1);
  lcd.print(state);
}
