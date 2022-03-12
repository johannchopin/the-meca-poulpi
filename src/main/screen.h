#include <Arduino.h>
#include <Wire.h>
#include <string.h>
#include "constants.h"
#include "rgb_lcd.h"
#include "states.h"

class Screen {
  public:
    Screen(){};
    void loop(States* state);
    void setup(States* state);
    void colorBackground();
    int pin;

  private:
    PoulpiState currentState;
    int waterGlassSizeInMlDisplayed;
    void onStateChange();
    void updateLocalStateFromStates(States* states);
};
