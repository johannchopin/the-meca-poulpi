#include "button.h"
#include <Arduino.h>
#include <functional>

namespace std
{
  void __throw_bad_function_call()
  {
    while (1);
  }
}

void Button::onClick(std::function<void()> callbackPtr)
{
  this->callbackPtr = callbackPtr;
}

void Button::setup()
{
  pinMode(this->pin, INPUT);
}

void Button::loop()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(this->pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != this->lastButtonState)
  {
    // reset the debouncing timer
    this->lastDebounceTime = millis();
  }

  if ((millis() - this->lastDebounceTime) > this->debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != this->buttonState)
    {
      this->buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (this->buttonState == HIGH)
      {
        this->callbackPtr();
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  this->lastButtonState = reading;
}
