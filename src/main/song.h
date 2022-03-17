#pragma once

#include <stdint.h>

class Song
{
public:
  short int *melody;
  uint8_t *durations;
  int length;
  Song(short int *melody, uint8_t *durations, int length)
  {
    this->melody = melody;
    this->durations = durations;
    this->length = length;
  }
};