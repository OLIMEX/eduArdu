#include <string.h>
#include "TCN75.h"
#include "LED_Matrix.h"

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

LED_Matrix Matrix(LED_LATCH,LED_DATA,LED_CLOCK);
TCN75 T (0x48);

char Buff[8];

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  static unsigned long Time=0, PrevTime=0;
  
  Time = millis();
  if (Time-PrevTime > 100)
  {
    PrevTime = Time;
    float Temp = T.Temperature ();
    Serial.print("Current temperature = ");
    Serial.println (Temp);
    Serial.print("Raw data = 0x");
    Serial.println (T.RawData (), HEX);
    sprintf (Buff, "%dC ", (int)Temp);
    Matrix.DisplayText ((unsigned char*)Buff);
    Matrix.SlideRight (1);
  }
  Matrix.UpdateText ();
}
