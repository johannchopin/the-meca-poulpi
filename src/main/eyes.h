#include <Arduino.h>
#include <ChainableLED.h>
#include "inocomponent.h"
#include "inocomponentwithsinglepin.h"
#include "inocomponentwithstate.h"
#include "color.h"

#define SPORT_COLORS_AMOUNT 3

#pragma once

class Eyes : public InoComponent,
             public InoComponentWithSinglePin,
             public InoComponentWithState
{
public:
  Eyes(){};
  Eyes(int pin) : InoComponentWithSinglePin(pin){};
  void loop(PoulpiState state);
  void setup();
  void setRgbColor(int r, int g, int b);

private:
  ChainableLED *leds;
  void onStateChange();
  void handleSportAnimation();
  int debounceTime = 0;
  int sportLightSwitchDelay = 100;
  Color *sportColors[SPORT_COLORS_AMOUNT] = {new Color(255, 0, 0), new Color(0, 255, 0), new Color(0, 0, 255)};
  int currentSportColorIndex = 0;
};
