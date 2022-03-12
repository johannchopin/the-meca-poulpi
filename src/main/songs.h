#include "song.h"
#include "pitches.h"

#pragma once

int *melody = new int[8]{NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int *durations = new int[8]{4, 8, 8, 4, 4, 4, 4, 4};
Song *song = new Song(melody, durations, 8);
