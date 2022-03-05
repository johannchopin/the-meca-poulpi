#include <Arduino.h>
#include <functional>

class Button {
  public:
    Button() {};
    Button(int pin) {
      this->pin = pin;
    };
    void onClick(std::function<void ()> callbackPtr);
    void loop();
    void setup();

  private:
    int pin;
    int ledState = HIGH;
    int buttonState;
    int lastButtonState = LOW;
    std::function<void ()> callbackPtr;
    unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
    unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers
};
