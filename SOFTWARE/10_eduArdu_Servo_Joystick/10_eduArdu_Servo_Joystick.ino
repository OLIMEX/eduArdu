/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo sketch using the default Arduino library "Servo".
Servo 1 and 2 are set in a position depending on the the value of the
respective joystick axis: X for Servo 1; Y for Servo 2.
**********************************************************************/

#include <Servo.h>
#include <Olimex_Joystick.h>

Servo Servo1, Servo2;
Olimex_Joystick Joy(A0, A1); // X, Y

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
