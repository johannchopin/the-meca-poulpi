#include "secondarybutton.h"

void SecondaryButton::declineReminderState(States *states)
{
    PoulpiState currentState = states->getCurrent();

    if (currentState == PoulpiState::MEDITATION_REMINDER || currentState == PoulpiState::TASK_REMINDER || currentState == PoulpiState::SPORT_REMINDER || currentState == PoulpiState::WATER_REMINDER)
    {
        states->setCurrent(PoulpiState::SLEEPY);
    }
}
