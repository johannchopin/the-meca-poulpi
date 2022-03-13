#pragma once
#include "Arduino.h"

#define ITEMS_IN_LIST 30
#define CARRIAGE_RETURN "\n"

const int DEFAULT_WATER_IN_GLASS_IN_ML = 200;
const int DEFAULT_WATER_GOAL_IN_ML = 2000;

const int MIN_WATER_LEVEL = 0;
const int WATER_LEVEL_STEP_AMOUNT = 40;
const int WATER_AMOUNT_PER_STEP_IN_ML = 25;

typedef enum {
  MEDITATION,
  DO_MEDITATION,
  SPORT,
  DO_SPORT,
  WATER,
  TASKS,
  SLEEPY,
} PoulpiState;

typedef enum {
  TAKE_ON_ME,
  BABY_ELEPHANT_WALK,
  BRAHAMS_LULLABY,
  CANTINABAND,
  GREENSLEVES,
  MII_CHANNEL_MUSIC
} Music;

typedef enum {
  OFF = 0,
  ON = 1,
} Switch;
