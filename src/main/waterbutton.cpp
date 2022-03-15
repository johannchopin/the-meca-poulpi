#include <Arduino.h>
#include "waterbutton.h"

void WaterButton::setup()
{
  Button::setup();
  pinMode(this->ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void WaterButton::drinkOneGlass(States* states) {
  states->waterDrunkAmountInMl += states->waterGlassSizeInMl;
  states->waterGlassDrunk += 1;
}
