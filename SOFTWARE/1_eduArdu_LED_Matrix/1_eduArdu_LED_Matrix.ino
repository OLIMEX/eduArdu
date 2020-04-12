/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Display text on the LED-matrix.
Text could be slided using the joystick using
the left/right side of the X axis.
You can increase/decrease brightness using
up/down side of the Y axis.
On the terminal you can monitor the data from the joystick.
**********************************************************************/

#include <string.h>
#include <Olimex_LED_Matrix.h>
#include <font.h>
#include <Olimex_Joystick.h>

// Joystick pins
#define JOYSTICK_X  A0
#define JOYSTICK_Y  A1
#define JOYSTICK_BUTTON 31

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

Olimex_LED_Matrix Matrix(LED_LATCH,LED_DATA,LED_CLOCK);
Olimex_Joystick Joy(JOYSTICK_X, JOYSTICK_Y);

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
      Matrix.SlideLeft (1); // slide TEXT 1 position to the left
    if (Joy.X () > 80)
      Matrix.SlideRight (1);  // slide TEXT 1 position to the right

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
