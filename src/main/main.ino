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
  screen->setup();

  stateSwitchButton->onClick(std::bind(&States::setState, states, "do_meditation"));
}

void loop()
{
  stateSwitchButton->loop();
  screen->loop(const_cast<char*> (states->getCurrent()));
}
