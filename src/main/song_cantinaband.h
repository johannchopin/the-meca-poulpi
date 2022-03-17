#include "song.h"
#include "pitches.h"
#include <stdint.h>

#define CANTINA_SOUND_LENGTH 64
#define CANTINABAND_TEMPO 950

// Cantina band
extern short int *melodyCantina;
extern uint8_t *durationsCantina;
extern Song *cantinaband;
