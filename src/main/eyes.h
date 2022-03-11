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
  void setHslColor(float hue, float saturation, float lightness);

private:
  ChainableLED *leds;
  void onStateChange();
  void handleSportAnimation();
  void handleMeditationAnimation();
  int debounceTime = 0;

  // sport animation
  int sportLightSwitchDelay = 100;
  Color *sportColors[SPORT_COLORS_AMOUNT] = {new Color(255, 0, 0), new Color(0, 255, 0), new Color(0, 0, 255)};
  int currentSportColorIndex = 0;
  
  // meditation animation
  float meditationEyeOpacity = 0.5;
  int meditationAnimationDelay = 15;
  bool meditationEyeShouldFadeUp = true;
};
