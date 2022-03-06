#include "constants.h"

class States
{
public:
  States();
  const PoulpiState states[7] = {
    SLEEPY,
    MEDITATION,
    DO_MEDITATION,
    SPORT,
    DO_SPORT,
    WATER,
    TASKS,
  };
  const PoulpiState getCurrent();
  void goToNext();
  int getStatesAmount();
  void setState(PoulpiState const state);
  void loop();

private:
  PoulpiState current = PoulpiState::SLEEPY;
  unsigned long lastStateChangeDebounceTime = 0;
  unsigned long debounceStateChangeDelay = 3000; // in ms
};
