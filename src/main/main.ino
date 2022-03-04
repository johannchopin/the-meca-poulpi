#include <string>
#include "pitches.h"
#include "states.h"
#include "button.h"

const int buttonPin = 7; // the number of the pushbutton pin

States states;
Button stateSwitchButton;

void setup()
{
  Serial.begin(9600);

  states = States();
  pinMode(buttonPin, INPUT);
  stateSwitchButton = Button(buttonPin);

}

// Task no.1: blink LED with 1 second delay.
void loop()
{
  stateSwitchButton.loop();
}