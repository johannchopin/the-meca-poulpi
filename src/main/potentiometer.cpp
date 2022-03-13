#include "potentiometer.h"

void Potentiometer::setup() {
  pinMode(this->pin, OUTPUT);
}

void Potentiometer::loop(States* states) {
  int value = analogRead(this->pin); // value between 0 and 1023

  int waterLevelSteps = map(value, MIN_POTENTIOMETER_VALUE, MAX_POTENTIOMETER_VALUE, MIN_WATER_LEVEL, WATER_LEVEL_STEP_AMOUNT);
  int waterGlassSizeInMlCandidate = waterLevelSteps * WATER_AMOUNT_PER_STEP_IN_ML;
  Serial.println(waterGlassSizeInMlCandidate);
  if (states->waterGlassSizeInMl != waterGlassSizeInMlCandidate) {
    states->waterGlassSizeInMl = waterGlassSizeInMlCandidate;
  }
}
