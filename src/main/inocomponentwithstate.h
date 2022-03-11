#include "states.h"

#pragma once

class InoComponentWithState
{
protected:
  PoulpiState currentState;
  virtual void onStateChange();
};
