#pragma once

class Song
{
public:
  int *melody;
  int *durations;
  int length;
  Song(int *melody, int *durations, int length)
  {
    this->melody = melody;
    this->durations = durations;
    this->length = length;
  }
};