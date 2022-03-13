#include "../song.h"
#include "../pitches.h"

#define MIICHANNEL_SOUND_LENGTH 28
#define MIICHANNEL_TEMPO 1000

// MII CHANNEL MELODY
int *miichanelMelody = new int[MIICHANNEL_SOUND_LENGTH]{
    NOTE_FS4,
    REST,
    NOTE_A4,
    NOTE_CS5,
    REST,
    NOTE_A4,
    REST,
    NOTE_FS4,
    NOTE_D4,
    NOTE_D4,
    NOTE_D4,
    REST,
    REST,
    REST,
    NOTE_CS4,
    NOTE_D4,
    NOTE_FS4,
    NOTE_A4,
    NOTE_CS5,
    REST,
    NOTE_A4,
    REST,
    NOTE_F4,
    NOTE_E5,
    NOTE_DS5,
    NOTE_D5,
    REST,
    REST
};
int *miichanelDurations = new int[MIICHANNEL_SOUND_LENGTH]{
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    4,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    8,
    4,
    8,
    8,
    8,
    4
};
Song *miichanelSong = new Song(miichanelMelody, miichanelDurations, MIICHANNEL_SOUND_LENGTH);
