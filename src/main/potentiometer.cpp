#include "potentiometer.h"

void Potentiometer::setup() {
  pinMode(this->pin, OUTPUT);
}

void Potentiometer::loop(States* states) {
  int value = analogRead(this->pin); // value between 0 and 1023

  if (states->waterGlassSizeInMl != value) {
    states->waterGlassSizeInMl = value;
  }
}
