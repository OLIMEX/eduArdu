#include <Servo.h>
#include "Joystick.h"

Servo Servo1, Servo2;
Joystick Joy(A0, A1, 31); // X, Y, Button

void setup()
{
  Servo1.attach(9);
  Servo2.attach(10);
}

void loop()
{
  Servo1.write (Joy.X()*1.8);
  Servo2.write (Joy.Y()*1.8);
}

