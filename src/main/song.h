#pragma once

class Song
{
public:
  int *melody;
  int *durations;
  Song(int *melody, int *durations)
  {
    this->melody = melody;
    this->durations = durations;
  }
};