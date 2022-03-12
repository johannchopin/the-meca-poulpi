#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "constants.h"
#include "rgb_lcd.h"
#include "states.h"

//#define NB_POULPISTATES 8
//#define NB_DESCRIPTORSPERSTATE 3

class Screen
{
public:
  Screen();
  void loop(States* states);
  void setup(States* states);
  void colorBackground();
  int pin;
 
private:
  PoulpiState currentState;
  int nbDescriptorsPerState;
  String* displayStrings;
  String** randomDescriptions;
  rgb_lcd* lcd;
  int waterGlassSizeInMlDisplayed;

  void onStateChange();
  void updateLocalStateFromStates(States* states);
  String getRandomDescriptions(String* descriptions, int size);
  void displayMessage(String message);
};
