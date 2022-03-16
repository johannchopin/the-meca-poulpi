#pragma once

#include <Arduino.h>
#include <algorithm>
#include "constants.h"
#include "states.h"

class SecondaryButton
{
public:
    void declineReminderState(States* states);
};
