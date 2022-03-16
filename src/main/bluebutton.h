#include <Arduino.h>
#include <functional>
#include "button.h"
#include "states.h"

class BlueButton : public Button
{
public:
  BlueButton(){};
  BlueButton(int pin, int ledPin) : Button(pin)
  {
    this->ledPin = ledPin;
  }
  int ledPin;
  void setup();

  void onClickHandler(States *states);

private:
  void drinkOneGlass(States *states);
};
