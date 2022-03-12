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
#include "servomotor.h"
#include "eyes.h"
#include "potentiometer.h"

const int POTENTIOMETER_PIN = 0;
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
Potentiometer *potentiometer;

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
  potentiometer = new Potentiometer(POTENTIOMETER_PIN);

  states->setState(PoulpiState::SLEEPY);

  state = states->getCurrent();

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(states);
  buzzer->setup();
  gauge->setup();
  motor->setup();
  eyes->setup();
  potentiometer->setup();

  ble->setup(); // should be after all other component setup

  // int *melody = new int[8]{NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
  // int *durations = new int[8]{4, 8, 8, 4, 4, 4, 4, 4};
  // Song *song = new Song(melody, durations, 8);

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
  waterButton->onClick(std::bind(&States::incrementWater, states));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop(states);
  buzzer->loop();
  gauge->loop(states->gaugeLevel);
  ble->loop(states);
  motor->loop();
  eyes->loop(states->getCurrent());
  potentiometer->loop(states);

  stateController();
}
