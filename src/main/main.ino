#include <string>
#include "constants.h"
#include "pitches.h"
#include "states.h"
#include "button.h"
#include "screen.h"
#include "waterbutton.h"
#include "buzzer.h"
#include "song.h"

const int BUTTON_PIN = 7;
const int BUZZER_PIN = 4;

States *states;
Button *stateSwitchButton;
Screen *screen;
WaterButton *waterButton;
Buzzer *buzzer;

void setup()
{
  Serial.begin(9600);

  states = new States();
  stateSwitchButton = new Button(BUTTON_PIN);
  screen = new Screen();
  waterButton = new WaterButton(6, 5);
  buzzer = new Buzzer(BUZZER_PIN);

  states->setState(PoulpiState::SLEEPY);

  stateSwitchButton->setup();
  waterButton->setup();
  screen->setup(states->getCurrent());
  buzzer->setup();

  int *melody = new int[8]{NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
  int *durations = new int[8]{4, 8, 8, 4, 4, 4, 4, 4};
  Song *song = new Song(melody, durations, 8);

  stateSwitchButton->onClick(std::bind(&States::goToNext, states));
  // waterButton->onClick(std::bind(&States::goToNext, states));
  waterButton->onClick(std::bind(&Buzzer::playTone, buzzer, song));
}

void loop()
{
  states->loop();
  stateSwitchButton->loop();
  waterButton->loop();
  screen->loop((states->getCurrent()));
  buzzer->loop();
  delay(50);
}
