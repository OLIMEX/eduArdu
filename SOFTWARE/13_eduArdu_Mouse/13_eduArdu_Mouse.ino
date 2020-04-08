/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo sketch using the default Arduino library "Mouse" based on their
example JoystickMouseControl. Using the joystick you move the cursor
and when you press the button you trigger left click.
**********************************************************************/

#include "Mouse.h"
#include <Olimex_Joystick.h>

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 2;      // switch to turn on and off mouse control
const int ledPin = 5;         // Mouse control LED
Olimex_Joystick Joy (A0, A1);

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value

boolean mouseIsActive = false;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

void setup() {
  pinMode(switchPin, INPUT);       // the switch pin
  pinMode(ledPin, OUTPUT);         // the LED pin
  // take control of the mouse:
  Mouse.begin();
}

void loop() {
  // read the switch:
  int switchState = digitalRead(switchPin);
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
      // turn on LED to indicate mouse state:
      digitalWrite(ledPin, mouseIsActive);
    }
  }
  // save switch state for next comparison:
  lastSwitchState = switchState;

  // read and scale the two axes:
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);
  Serial.println (xReading);
  Serial.println (yReading);

  // if the mouse control state is active, move the mouse:
  if (mouseIsActive) {
    Mouse.move(xReading, yReading, 0);
  }

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  if (Joy.But()) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(responseDelay);
}

/*
  reads an axis (0 or 1 for x or y) and scales the analog input range to a range
  from 0 to <range>
*/

int readAxis(int thisAxis)
{
  // read the analog input:
  int reading;
  if (thisAxis == A1)
    reading = 1023 - analogRead(thisAxis);
  else
    reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the rest position threshold, use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}
