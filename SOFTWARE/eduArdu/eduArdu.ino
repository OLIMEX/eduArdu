#include <string.h>
#include "OliLedMatrix.h"
#include "font.h"

#define LED_BUILTIN 12
#define JOYSTICK_BUTTON 31
#define BUZZER  6

/* LED MATRIX PINS */
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

//setup pins for led Matrix
OliLedMatrix ledMatrix(LED_LATCH,LED_DATA,LED_CLOCK);
char Buff[256];
int Number = 0;
unsigned char Brightness = 128;

void LED_State (int State)
{
  digitalWrite(LED_BUILTIN, State);
}

int CAP_Touched (int Pin)
{
  return digitalRead (Pin);
}

float Joystick_X ()
{
  return analogRead(A0) * 100.0 / 1023.0;
}

float Joystick_Y ()
{
  return analogRead(A1) * 100.0 / 1023.0;
}

int Joystick_Button ()
{
  return digitalRead (JOYSTICK_BUTTON);
}

float Light_Sensor ()
{
  return analogRead(A2) * 100.0 / 1023.0;
}

void Buzzer ()
{
  if (!CAP_Touched (9))
    tone (BUZZER, 523);
  else
    noTone (BUZZER);

  if (!CAP_Touched (10))
    tone (BUZZER, 587);
  else
    noTone (BUZZER);

  if (!CAP_Touched (13))
    tone (BUZZER, 659);
  else
    noTone (BUZZER);

  if (!CAP_Touched (14))
    tone (BUZZER, 698);
  else
    noTone (BUZZER);
/*
  // multiplexed with MOD-LED CLOCK and data pins
  if (!CAP_Touched (15))
    tone (BUZZER, 784);
  else
    noTone (BUZZER);

  if (!CAP_Touched (16))
    tone (BUZZER, 880);
  else
    noTone (BUZZER);
*/
}

void setup()
{
  Serial.begin (115200);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (JOYSTICK_BUTTON, INPUT);
  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (13, INPUT);
  pinMode (14, INPUT);
  //pinMode (15, INPUT);  // multiplexed with MOD-LED CLOCK
  //pinMode (16, INPUT);  // multiplexed with MOD-LED DATA

  pinMode (A0, INPUT_PULLUP);
  pinMode (A1, INPUT_PULLUP);
  pinMode (A2, INPUT_PULLUP);
  pinMode (BUZZER, OUTPUT);
}


void Display(int Symbol, unsigned char Brightness)
{
  
  unsigned long time = millis();
  
  ledMatrix.clear();
  ledMatrix.brightness = Brightness;
  ledMatrix.drawArray (1, 0, FontLookup[Symbol-32+48], 5);
  ledMatrix.display();
}

void loop()
{
  static long int ScanTimeout = 0;
  if (!ScanTimeout--)
  {
    ScanTimeout = 60;
    if (Joystick_X () < 20)
      Number = ((Number - 1) + 10) % 10;
    if (Joystick_X () > 80)
      Number = (Number + 1) % 10;
    Serial.println ("-----------------------------------------------------");
    sprintf (Buff, "Joystick: X = %d%%; Y = %d%%; Button: %d", (int)Joystick_X(), (int)Joystick_Y(), Joystick_Button());
    Serial.println (Buff);
    sprintf (Buff, "Light sensor: %d%%", (int)Light_Sensor());
    Serial.println (Buff);
    sprintf (Buff, "D9 = %d; D10 = %d; D13 = %d; D14 = %d; D15 = %d; D16 = %d", CAP_Touched(9), CAP_Touched(10), CAP_Touched(13), CAP_Touched(14), CAP_Touched(15), CAP_Touched(16));
    Serial.println (Buff);
    if (Joystick_Button())
    {
      delay (100);
      Serial.println ("Buzzer mode activated!");
      while (Joystick_Button());
      LED_State (1);
      while (1)
      {
        if (Joystick_Button())
        {
          Serial.println ("Buzzer mode deactivated!");
          LED_State (0);
          break;
        }
        Buzzer ();
      }
    }
  }
  Display (Number, Light_Sensor()/100.0*255);
}
