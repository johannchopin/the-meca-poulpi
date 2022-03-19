#pragma once

#include "constants.h"
#include "Arduino.h"

class LocalUtils
{
public:
  static String *split(String phrase, String delimiter);
  static int countItemsInArray(String *array);

  // determine on which column the water amount should start
  // to be printed on the screen
  static int mlValueStartColOnScreen(int waterMl);
};

int availableMemory();
