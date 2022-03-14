#include "localUtils.h"

String* LocalUtils::split(String phrase, String delimiter){
  String* acc = new String[ITEMS_IN_LIST];
  int count = 0;
  int pos = 0;
  String token;
  while ((pos = phrase.indexOf(delimiter)) != -1) {
      token = phrase.substring(0, pos);
      acc[count] = token;
      phrase.remove(0, pos);
      count++;
  }
  acc[count] = phrase;
  return acc;
}

int LocalUtils::countItemsInArray(String* array) {
  int n=0;
  String p;
  while (p!= '\0') {
    n++;
    p = array[n];
  }
  return n;
}

// free RAM check for debugging. SRAM for ATmega328p = 2048Kb.
int availableMemory()
{
  // Use 1024 with ATmega168
  int size = 2048;
  byte *buf;
  while ((buf = (byte *)malloc(--size)) == NULL)
    ;
  free(buf);
  return size;
}
