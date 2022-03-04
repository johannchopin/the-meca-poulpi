#include <string>
#include "pitches.h"
#include "states.h"
#include "button.h"

const int buttonPin = 7; // the number of the pushbutton pin

States states;
Button stateSwitchButton;

void onButtonClicked()
{
  Serial.println("click");
}

void goNextState()
{
  states.goToNext();
}

void setup()
{
  Serial.begin(9600);

  states = States();
  stateSwitchButton = Button(buttonPin);
  stateSwitchButton.setup();

  stateSwitchButton.onClick(goNextState);
}

void loop()
{
  stateSwitchButton.loop();
  Serial.println(states.getCurrent());
}
