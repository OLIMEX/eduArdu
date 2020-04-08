/**********************************************************************
Demo example for Olimex library "LED_Matrix"
Tested with Arduino 1.8.8 on eduArdu
Date: 2018/12/12

Description:

**********************************************************************/

#include "LED_Matrix_L.h"
#include <NewPing.h>  // go to Sketch --> Include Library --> Manage Libraries --> NewPing (test with 1.9.1v)
#include <Joystick.h>

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

#define US_TX 8
#define US_RX 4
#define MAX_DISTANCE   200 // max distance in cm

Joystick Joy (A0, A1);
NewPing Sonar(US_TX, US_RX, MAX_DISTANCE);
LED_Matrix_L Matrix(LED_LATCH,LED_DATA,LED_CLOCK);

int Sample;
int Button = 1;
int isOn = 0;
int Duration;

void setup()
{
  Serial.begin (115200);
  delay(100);
}

void loop()
{
  while (Joy.But () && Button)
  {
    Button = 0;
    isOn = !isOn;
  }
  if (!Joy.But ())
    Button = 1;
  Sample = Sonar.ping_cm ();
  Serial.print(Sample);
  Serial.println(" cm");
  
  if (isOn)
  {
    Matrix.Clear();
    int maxLine = -1;
    if (Sample < 80 && Sample > 0)
    {
      maxLine = 1;
    }
    if (Sample < 70 && Sample > 0)
    {
      maxLine = 2;
    }
    if (Sample < 60 && Sample > 0)
    {
      maxLine = 3;
    }
    if (Sample < 50 && Sample > 0)
    {
      maxLine = 4;
    }
    if (Sample < 40 && Sample > 0)
    {
      maxLine = 5;
    }
    if (Sample < 30 && Sample > 0)
    {
      maxLine = 6;
    }
    if (Sample < 20 && Sample > 0)
    {
      maxLine = 7;
    }
    if (Sample < 10 && Sample > 0)
    {
      maxLine = 8;
    }
    if (maxLine > 0)
    {
      //Matrix.Line(0,0,7,0);
      Matrix.DrawRectangle(0,0,maxLine,8, true);
      Matrix.UpdateMatrix();
    }
    for( int i = 0;i<20;i++) 
    {
      Matrix.UpdateMatrix();
      delay(10);
    }
    Matrix.Clear();
      delay(10);
    Matrix.UpdateMatrix();
      delay(10);
  }
  else 
  {
    Matrix.Clear();
    Matrix.UpdateMatrix();
  }
  delay(200 - Duration);
}
