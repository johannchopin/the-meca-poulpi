#include <string>
#include "pitches.h"
#include "constants.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "bluebutton.h"
#include "secondarybutton.h"
#include "buzzer.h"
#include "gauge.h"
#include "ble.h"
#include "servomotor.h"
#include "eyes.h"
#include "potentiometer.h"
#include "localUtils.h"

#include "songs.h"

const int POTENTIOMETER_PIN = 0;
const int BUZZER_PIN = 11;
const int WATER_BUTTON_PIN = 3; // D2
const int BUTTON_PIN = 8;
const int GAUGE_PIN = 5; // D4
const int MOTOR_PIN = 10;
const int EYES_PIN = 6;

Ble *ble;
States *states;
Button *stateSwitchButton;
Screen *screen;
BlueButton *blueButton;
Buzzer *buzzer;
Gauge *gauge;
Servomotor *motor;
Eyes *eyes;
Potentiometer *potentiometer;

PoulpiState state;

void songsController()
{
  buzzer->stopTone();

  if (state == PoulpiState::WELCOME)
  {
    Serial.println("WELCOME");
    buzzer->playTone(cantinaband, CANTINABAND_TEMPO);
  }
  if (state == PoulpiState::SPORT_REMINDER)
  {
    Serial.println("SPORT_REMINDER");
    buzzer->playTone(takeOnMe, TAKE_ON_ME_TEMPO);
  }

  if (state == PoulpiState::TASK_REMINDER)
  {
    Serial.println("TASK_REMINDER");
    buzzer->playTone(cantinaband, CANTINABAND_TEMPO);
  }

  if (state == PoulpiState::SLEEPY)
  {
    Serial.println("SLEEPY");
  }

  if (state == PoulpiState::DOING_MEDITATION)
  {
    Serial.println("DOING_MEDITATION");
    buzzer->playTone(lullaby, LULLABY_TEMPO);
  }

  if (state == PoulpiState::DOING_SPORT)
  {
    buzzer->playTone(
        musics[states->sportMusic],
        musicDurations[states->sportMusic]);
  }
}

void motorController()
{
  bool animate = state == PoulpiState::SPORT_REMINDER || state == PoulpiState::WELCOME;
  if (animate)
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
  Serial.println("state change");
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
  blueButton = new BlueButton(WATER_BUTTON_PIN, WATER_BUTTON_PIN - 1);
  buzzer = new Buzzer(BUZZER_PIN);
  gauge = new Gauge(GAUGE_PIN);
  motor = new Servomotor(MOTOR_PIN);
  eyes = new Eyes(EYES_PIN);
  potentiometer = new Potentiometer(POTENTIOMETER_PIN);

  states->setCurrent(PoulpiState::WELCOME);

  state = states->getCurrent();

  stateSwitchButton->setup();
  blueButton->setup();
  screen->setup(states);
  buzzer->setup();
  gauge->setup();
  motor->setup();
  eyes->setup();
  potentiometer->setup();
  ble->setup(); // should be after all other component setup

  stateSwitchButton->onClick(std::bind(&SecondaryButton::declineReminderState, SecondaryButton(), states));
  blueButton->onClick(std::bind(&BlueButton::onClickHandler, blueButton, states));

  // trigger first state update
  onStateChange();
}

void loop()
{
  stateController();

  states->loop();
  stateSwitchButton->loop();
  blueButton->loop();
  screen->loop(states);
  buzzer->loop();
  gauge->loop(states->waterGoal, states->waterDrunkAmountInMl);
  ble->loop(states);
  motor->loop();
  eyes->loop(states->getCurrent());
  potentiometer->loop(states);
}
