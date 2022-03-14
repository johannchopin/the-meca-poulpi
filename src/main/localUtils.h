#pragma once

#include "constants.h"
#include "Arduino.h"

class LocalUtils {
  public:
    static String* split(String phrase, String delimiter);
    static int countItemsInArray(String* array);
};

int availableMemory();