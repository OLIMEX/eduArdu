#include <string.h>
#include "LED_Matrix.h"
#include "font.h"
#include "Joystick.h"

// Joystick pins
#define JOYSTICK_X  A0
#define JOYSTICK_Y  A1
#define JOYSTICK_BUTTON 31

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

LED_Matrix Matrix(LED_LATCH,LED_DATA,LED_CLOCK);
Joystick Joy(JOYSTICK_X, JOYSTICK_Y);

unsigned char Text[STRING_MAX_CHAR] = "Olimex eduArdu LED matrix example!";
char Terminal_Output[256];

void setup()
{
  Serial.begin (115200);
  Matrix.DisplayText (Text, 0);  // the second parameter means we reset the offset so we show the text from the beginning
}

void loop()
{
  static unsigned long Time=0, PrevTime=0;
  
  Time = millis();
  if (Time-PrevTime > 110)
  {
    PrevTime = Time;
    if (Joy.X () < 20)
      Matrix.SlideRight (1); // slide 1 position to the right
    if (Joy.X () > 80)
      Matrix.SlideLeft (1);  // slide 1 position to the left

    if (Joy.Y () < 20)
      Matrix.ChangeBrightness (-10);
    if (Joy.Y () > 80)
      Matrix.ChangeBrightness (10);

    Serial.println ("-----------------------------------------------------");
    sprintf (Terminal_Output, "Joystick: X = %d%%; Y = %d%%; Button: %d", (int)Joy.X(), (int)Joy.Y(), Joy.But());
    Serial.println (Terminal_Output);
  }
  Matrix.UpdateText ();
}
