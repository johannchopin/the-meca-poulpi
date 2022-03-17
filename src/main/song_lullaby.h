#pragma once

#include "song.h"
#include "pitches.h"
#include <stdint.h>

#define LULLABY_SOUND_LENGTH 54
#define LULLABY_TEMPO 1500

// BRAM'S LULLABY
extern short int *lullabyMelody;
extern uint8_t *lullabyDuration;
extern Song *lullaby;
