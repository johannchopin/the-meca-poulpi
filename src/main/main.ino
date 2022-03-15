#include <string>
#include "pitches.h"
#include "constants.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"
#include "buzzer.h"
#include "gauge.h"
#include "ble.h"
#include "servomotor.h"
#include "eyes.h"
#include "potentiometer.h"

#include "songs.h"

const int POTENTIOMETER_PIN = 0;
const int BUZZER_PIN = 4;
const int WATER_BUTTON_PIN = 6;
const int BUTTON_PIN = 7;
const int GAUGE_PIN = 9; // D8
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

void songsController()
{
  buzzer->stopTone();

  if (state == PoulpiState::SPORT)
  {
    Serial.println("SPORT");
    buzzer->playTone(takeOnMe, TAKE_ON_ME_TEMPO);
  }

  if (state == PoulpiState::TASKS)
  {
    Serial.println("TASKS");
    buzzer->playTone(cantinaband, CANTINABAND_TEMPO);
  }

  if (state == PoulpiState::SLEEPY)
  {
    Serial.println("SLEEPY");
  }

  if (state == PoulpiState::MEDITATION)
  {
    Serial.println("MEDITATION");
    buzzer->playTone(lullaby, LULLABY_TEMPO);
  }

  if (state == PoulpiState::DO_SPORT)
  {
    Serial.println("DO_SPORT");
    buzzer->playTone(babyelephantwalkSong, BABYELEPHANTWALK_TEMPO);
  }
}

void motorController()
{
  if (state == PoulpiState::SPORT)
  {
    motor->startTentaculeAnimation();
  }
  else
  {
    motor->stopTentaculeAnimation();
  }
}

void onStateChange()
{
  motorController();
  songsController();
}

void stateController()
{
  bool stateHasChanged = (state != states->getCurrent());
  if (stateHasChanged)
  {
    state = states->getCurrent();
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
  // ble->setup(); // should be after all other component setup

  // stateSwitchButton->onClick(std::bind(&Buzzer::playTone, buzzer, lullaby, DEFAULT_TEMPO));
  waterButton->onClick(std::bind(&WaterButton::drinkOneGlass, waterButton, states));
  // waterButton->onClick(std::bind(&Buzzer::playTone, buzzer, cantinaband, DEFAULT_TEMPO));
}

void loop()
{
  stateController();

  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop(states);
  buzzer->loop();
  gauge->loop(states->waterGoal, states->waterDrunkAmountInMl);
  // ble->loop(states);
  // motor->loop();
  eyes->loop(states->getCurrent());
  potentiometer->loop(states);
}
