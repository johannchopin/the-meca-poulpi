#include <string>
#include "constants.h"
#include "pitches.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"
#include "buzzer.h"
#include "song.h"
#include "gauge.h"
#include "ble.h"

const int BUZZER_PIN = 4;
const int WATER_BUTTON_PIN = 6;
const int BUTTON_PIN = 7;
const int GAUGE_PIN = 8;

Ble *ble;
States *states;
Button *stateSwitchButton;
Screen *screen;
WaterButton *waterButton;
Buzzer *buzzer;
Gauge *gauge;

void setup()
{
  Serial.begin(9600);

  ble = new Ble();
  states = new States();
  stateSwitchButton = new Button(BUTTON_PIN);
  screen = new Screen();
  waterButton = new WaterButton(WATER_BUTTON_PIN, WATER_BUTTON_PIN - 1);
  buzzer = new Buzzer(BUZZER_PIN);
  gauge = new Gauge(GAUGE_PIN);

  states->setState(PoulpiState::SLEEPY);

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(states->getCurrent());
  buzzer->setup();
  gauge->setup();

  ble->setup(); // should be after all other component setup

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
  waterButton->onClick(std::bind(&States::incrementWater, states));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop((states->getCurrent()));
  buzzer->loop();
  gauge->loop(states->gaugeLevel);
  ble->loop(states);
}
