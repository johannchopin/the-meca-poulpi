#pragma once
#include "Arduino.h"
#include "songs.h"

#define ITEMS_IN_LIST 30
#define CARRIAGE_RETURN "\n"
#define DEVICE_NAME_ON_BLE "Poulpi C"

const int DEFAULT_WATER_IN_GLASS_IN_ML = 200;
const int DEFAULT_WATER_GOAL_IN_ML = 2000;

const int MIN_WATER_LEVEL = 0;
const int WATER_LEVEL_STEP_AMOUNT = 40;
const int WATER_AMOUNT_PER_STEP_IN_ML = 25;

const int FIVE_SECONDS = 5000;

// REMINDERS go first
typedef enum
{
  MEDITATION_REMINDER,
  SPORT_REMINDER,
  WATER_REMINDER,
  TASK_REMINDER,
  WELCOME,
  SLEEPY,
  DOING_MEDITATION,
  DRINKING_WATER,
  DOING_SPORT,
} PoulpiState;

typedef enum
{
  TAKE_ON_ME,
  BABY_ELEPHANT_WALK,
  BRAHAMS_LULLABY,
  CANTINABAND
} Music;

extern Song *musics[4];

extern int musicDurations[4];

typedef enum
{
  WATER_REMINDER_ON = 'A',
  WATER_REMINDER_OFF = 'a',
  SPORT_REMINDER_ON = 'B',
  SPORT_REMINDER_OFF = 'b',
  MEDITATION_REMINDER_ON = 'C',
  MEDITATION_REMINDER_OFF = 'c',
  TASK_REMINDER_ON = 'D',
  TASK_REMINDER_OFF = 'd'
} SwitchReminders;
