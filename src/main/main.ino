#include <string>
#include "song.h"
#include "pitches.h"
#include "constants.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"
#include "buzzer.h"
#include "song.h"
#include "gauge.h"
#include "ble.h"
#include "servomotor.h"
#include "eyes.h"

#include "songs.h"

const int BUZZER_PIN = 4;
const int WATER_BUTTON_PIN = 6;
const int BUTTON_PIN = 7;
const int GAUGE_PIN = 8;
const int MOTOR_PIN = 10;
const int EYES_PIN = 6;

Ble *ble;
States *states;
Button *stateSwitchButton;
Screen *screen;
WaterButton *waterButton;
Buzzer *buzzer;
Gauge *gauge;
Servomotor *motor;
Eyes *eyes;

PoulpiState state;

void onStateChange()
{
  state = states->getCurrent();
  if (state == PoulpiState::SPORT)
  {
    motor->startTentaculeAnimation();
  }
  else
  {
    motor->stopTentaculeAnimation();
  }
}

void stateController()
{
  bool stateHasChanged = (state != states->getCurrent());
  if (stateHasChanged)
  {
    onStateChange();
  }
}

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
  motor = new Servomotor(MOTOR_PIN);
  eyes = new Eyes(EYES_PIN);

  states->setState(PoulpiState::SLEEPY);

  state = states->getCurrent();

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(states->getCurrent());
  buzzer->setup();
  gauge->setup();
  motor->setup();
  eyes->setup();

  ble->setup(); // should be after all other component setup

  stateSwitchButton->onClick(std::bind(&Buzzer::playTone, buzzer, song));
  waterButton->onClick(std::bind(&States::incrementWater, states));
  // waterButton->onClick(std::bind(&Buzzer::playTone, buzzer, cantinaband, DEFAULT_TEMPO));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop(states->getCurrent());
  buzzer->loop();
  gauge->loop(states->gaugeLevel);
  ble->loop(states);
  motor->loop();
  eyes->loop(states->getCurrent());

  stateController();
}
