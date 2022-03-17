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
#include "localUtils.h"

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
   delay(3000);
   Serial.print("Memory at start: ");
   Serial.println(availableMemory());

  ble = new Ble();
  Serial.print("After ble instanciation: ");
  Serial.println(availableMemory());
  states = new States();
  Serial.print("After states instanciation: ");
  Serial.println(availableMemory());
  stateSwitchButton = new Button(BUTTON_PIN);
  Serial.print("After stateSwitchButton instanciation: ");
  Serial.println(availableMemory());
  screen = new Screen();
  Serial.print("After screen instanciation: ");
  Serial.println(availableMemory());
  waterButton = new WaterButton(WATER_BUTTON_PIN, WATER_BUTTON_PIN - 1);
  Serial.print("After button instanciation: ");
  Serial.println(availableMemory());
  buzzer = new Buzzer(BUZZER_PIN);
  Serial.print("After buzzer instanciation: ");
  Serial.println(availableMemory());
  gauge = new Gauge(GAUGE_PIN);
  Serial.print("After gauge instanciation: ");
  Serial.println(availableMemory());
  motor = new Servomotor(MOTOR_PIN);
  Serial.print("After servomotor instanciation: ");
  Serial.println(availableMemory());
  eyes = new Eyes(EYES_PIN);
  Serial.print("After eyes instanciation: ");
  Serial.println(availableMemory());
  potentiometer = new Potentiometer(POTENTIOMETER_PIN);
  Serial.print("After potentiometer instanciation: ");
  Serial.println(availableMemory());

  states->setState(PoulpiState::SLEEPY);

  state = states->getCurrent();

  stateSwitchButton->setup();
  Serial.print("After stateSwitch setup: ");
  Serial.println(availableMemory());
  waterButton->setup();
  Serial.print("After waterButton setup: ");
  Serial.println(availableMemory());
  screen->setup(states);
  Serial.print("After screen setup: ");
  Serial.println(availableMemory());
  buzzer->setup();
  Serial.print("After buzzer setup: ");
  Serial.println(availableMemory());
  gauge->setup();
  Serial.print("After gauge setup: ");
  Serial.println(availableMemory());
  motor->setup();
  Serial.print("After motor setup: ");
  Serial.println(availableMemory());
  eyes->setup();
  Serial.print("After eyes setup: ");
  Serial.println(availableMemory());
  potentiometer->setup();
  Serial.print("After potentiometer setup: ");
  Serial.println(availableMemory());
  delay(3000);
  Serial.print("Memory before ble->setup at start: ");
  Serial.println(availableMemory());
  ble->setup(); // should be after all other component setup
  delay(3000);
  Serial.print("After setup BLE: ");
  Serial.println(availableMemory());
  // stateSwitchButton->onClick(std::bind(&Buzzer::playTone, buzzer, lullaby, DEFAULT_TEMPO));
  waterButton->onClick(std::bind(&WaterButton::drinkOneGlass, waterButton, states));
  // waterButton->onClick(std::bind(&Buzzer::playTone, buzzer, cantinaband, DEFAULT_TEMPO));
  Serial.print("Memory at the end of setup() : ");
  Serial.println(availableMemory());
}

void loop()
{
  /*
  stateController();
  Serial.println("LOOP");
  Serial.println(availableMemory());

  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop(states);
  buzzer->loop();
  gauge->loop(states->waterGoal, states->waterDrunkAmountInMl);
  // ble->loop(states);
  // motor->loop();
  eyes->loop(states->getCurrent());
  potentiometer->loop(states);*/
}
