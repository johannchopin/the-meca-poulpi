#include <string>
#include "pitches.h"
#include "states.h"
#include "button.h"
#include "screen.h"

const int BUTTON_PIN = 7;

States *states;
Button *stateSwitchButton;
Screen *screen;

void setup()
{
  Serial.begin(9600);

  states = new States();
  stateSwitchButton = new Button(BUTTON_PIN);
  screen = new Screen();

  stateSwitchButton->setup();
  states->setState("sleepy");
  screen->setup(const_cast<char*> (states->getCurrent()));

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  screen->loop(const_cast<char*> (states->getCurrent()));
}
