#include "eyes.h"

#define EYES_AMOUNT 2

void Eyes::handleSportAnimation()
{
  int current = millis();
  bool switchColor = (current - this->debounceTime) > this->sportLightSwitchDelay;

  if (switchColor)
  {
    if ((this->currentSportColorIndex + 1) >= SPORT_COLORS_AMOUNT)
    {
      this->currentSportColorIndex = 0;
    }
    else
    {
      this->currentSportColorIndex++;
    }

    Color *newColor = this->sportColors[this->currentSportColorIndex];
    this->setRgbColor(newColor->r, newColor->g, newColor->b);
    this->debounceTime = current;
  }
}

void Eyes::onStateChange()
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

  this->setRgbColor(colorR, colorG, colorB);
}

void Eyes::setRgbColor(int r, int g, int b)
{
  for (byte i = 0; i < EYES_AMOUNT; i++)
  {
    this->leds->setColorRGB(i, r, g, b);
  }
}

void Eyes::setup()
{
  this->leds = new ChainableLED(this->pin, this->pin + 1, EYES_AMOUNT);
  this->leds->init();
}

void Eyes::loop(PoulpiState state)
{
  bool stateHasChanged = (state != currentState);
  if (stateHasChanged)
  {
    this->currentState = state;
    onStateChange();
  }

  if (currentState == PoulpiState::SPORT)
  {
    this->handleSportAnimation();
  }
}