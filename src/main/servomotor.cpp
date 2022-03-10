#include "servomotor.h"

void Servomotor::setup()
{
  this->motor.attach(this->pin);
}

void Servomotor::loop()
{
  for (this->position = 0; this->position <= 180; this->position += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    this->motor.write(this->position); // tell servo to go to this->positionition in variable 'this->position'
    delay(15);                         // waits 15ms for the servo to reach the this->positionition
  }
  for (this->position = 180; this->position >= 0; this->position -= 1)
  {                                    // goes from 180 degrees to 0 degrees
    this->motor.write(this->position); // tell servo to go to this->positionition in variable 'this->position'
    delay(15);                         // waits 15ms for the servo to reach the this->positionition
  }
}