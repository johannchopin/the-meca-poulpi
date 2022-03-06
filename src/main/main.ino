#include <string>
#include "pitches.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"

const int BUTTON_PIN = 7;

States *states;
Button *stateSwitchButton;
Screen *screen;
WaterButton *waterButton;

void setup()
{
  Serial.begin(9600);

  states = new States();
  stateSwitchButton = new Button(BUTTON_PIN);
  screen = new Screen();
  waterButton = new WaterButton(6, 5);

  states->setState("sleepy");

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(const_cast<char *>(states->getCurrent()));

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
  waterButton->onClick(std::bind(&States::goToNext, states));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop(const_cast<char *>(states->getCurrent()));
}
