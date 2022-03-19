#include "potentiometer.h"

void Potentiometer::setup()
{
  pinMode(this->pin, OUTPUT);
}

void Potentiometer::loop(States *states)
{
  int current = millis();
  bool isTimeToReadValue = (current - this->lastDebounceTime) > this->debounceDelay;
  if (isTimeToReadValue)
  {
    int value = analogRead(this->pin); // value between 0 and 1023

    // Reverse the potentiometer: low is high and high is low
    // Map the value to different steps (25ml, 50ml, ...) to make it more confortable
    int waterLevelSteps = WATER_LEVEL_STEP_AMOUNT - map(value, MIN_POTENTIOMETER_VALUE, MAX_POTENTIOMETER_VALUE, MIN_WATER_LEVEL, WATER_LEVEL_STEP_AMOUNT);
    int waterGlassSizeInMlCandidate = waterLevelSteps * WATER_AMOUNT_PER_STEP_IN_ML;
    if (states->waterGlassSizeInMl != waterGlassSizeInMlCandidate)
    {
      states->waterGlassSizeInMl = waterGlassSizeInMlCandidate;
    }

    this->lastDebounceTime = current;
  }
}
