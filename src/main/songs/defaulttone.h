#include "../song.h"
#include "../pitches.h"

#define DEFAULT_SOUND_LENGTH 8

// DEFAULT MELODY
int *melody = new int[DEFAULT_SOUND_LENGTH]{NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int *durations = new int[DEFAULT_SOUND_LENGTH]{4, 8, 8, 4, 4, 4, 4, 4};
Song *song = new Song(melody, durations, DEFAULT_SOUND_LENGTH);
