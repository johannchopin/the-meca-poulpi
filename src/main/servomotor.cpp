#include "servomotor.h"

void Servomotor::setup()
{
  this->motor.attach(this->pin);
  this->motor.write(this->position);
}

void Servomotor::startTentaculeAnimation()
{
  this->isTentaculeAnimated = true;
}

void Servomotor::stopTentaculeAnimation()
{
  this->position = this->POSITION_DOWN;
  this->motor.write(this->position);
  this->isTentaculeAnimated = false;
}

void Servomotor::toggleTentacule()
{
  int deg;

  if (this->position == this->POSITION_DOWN)
  {
    Serial.println("servo_motor UP");
    deg = this->POSITION_UP;
  }
  else
  {
    Serial.println("servo_motor DOWN");
    deg = this->POSITION_DOWN;
  }

  this->position = deg;
  this->motor.write(this->position);
}

void Servomotor::loop()
{
  if (this->isTentaculeAnimated)
  {
    int current = millis();
    bool shouldTentaculePositionBeToggled = (current - this->tentaculeDebounceTime) > this->tentaculeDelay;

    if (shouldTentaculePositionBeToggled)
    {
      this->toggleTentacule();
      this->tentaculeDebounceTime = current;
    }
  }
}