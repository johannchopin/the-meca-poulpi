#include <string>
#include "pitches.h"
#include "states.h"
#include "button.h"

const int buttonPin = 7; // the number of the pushbutton pin

States *states;
Button *stateSwitchButton;

void setup()
{
  Serial.begin(9600);

  states = new States();
  stateSwitchButton = new Button(buttonPin);

  stateSwitchButton->setup();

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
}

void loop()
{
  stateSwitchButton->loop();
  Serial.println(states->getCurrent());
}
