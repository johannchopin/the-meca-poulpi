#include <string>
#include "constants.h"
#include "pitches.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"
#include "buzzer.h"
#include "gauge.h"

const int BUTTON_PIN = 7;
const int BUZZER_PIN = 4;
const int GAUGE_PIN = 8;

States *states;
Button *stateSwitchButton;
Screen *screen;
WaterButton *waterButton;
Buzzer *buzzer;
Gauge *gauge;

void setup()
{
  Serial.begin(9600);

  states = new States();
  stateSwitchButton = new Button(BUTTON_PIN);
  screen = new Screen();
  waterButton = new WaterButton(6, 5);
  buzzer = new Buzzer(BUZZER_PIN);
  gauge = new Gauge(GAUGE_PIN);

  states->setState(PoulpiState::SLEEPY);

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(states->getCurrent());
  buzzer->setup();
  gauge->setup();

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
  // waterButton->onClick(std::bind(&States::goToNext, states));
  waterButton->onClick(std::bind(&Buzzer::playTone, buzzer));
  // TODO: waterButton->onClick : increase GaugeLevel
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop((states->getCurrent()));
  buzzer->setup();
  gauge->loop(states->gaugeLevel);
}
