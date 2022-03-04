#include <Arduino.h>

class Button {
  public:
    Button() {};
    Button(int pin) {
      this->pin = pin;
    };
    void onClick();
    void loop();

  private:
    int pin = 0;
    int ledState = HIGH;
    int buttonState;
    int lastButtonState = LOW;
    unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
    unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers
};
