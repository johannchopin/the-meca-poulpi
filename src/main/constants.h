#pragma once

typedef enum {
  MEDITATION,
  DO_MEDITATION,
  SPORT,
  DO_SPORT,
  WATER,
  TASKS,
  SLEEPY,
} PoulpiState;

const unsigned int DEFAULT_WATER_TO_DRINK_IN_ML = 2000;
const int DEFAULT_WATER_IN_GLASS_IN_ML = 200;
const int MIN_WATER_LEVEL = 0;
const int WATER_LEVEL_STEP_AMOUNT = 40;
const int WATER_AMOUNT_IN_STEP_IN_ML = 25;
