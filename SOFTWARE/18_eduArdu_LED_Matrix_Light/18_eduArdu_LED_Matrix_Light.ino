/**********************************************************************
Demo example for Olimex library "LED_Matrix_L"
Tested with Arduino 1.8.8 on eduArdu
Date: 2018/12/12

Description:

**********************************************************************/

#include <LED_Matrix_L.h>

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

LED_Matrix_L Matrix(LED_LATCH,LED_DATA,LED_CLOCK);

void setup()
{
  Serial.begin (115200);
}

void loop()
{
	for (int j= 0;j<8;j++)
	{
	  Matrix.Line(0,0,7,j);
    for( int i = 0;i<20;i++) 
    {
      Matrix.UpdateMatrix();
    }
    Matrix.Clear();
    Matrix.UpdateMatrix();
	}
  for (int j= 7;j>=0;j--)
  {
    Matrix.Line(0,0,j,7);
    for( int i = 0;i<20;i++) 
    {
      Matrix.UpdateMatrix();
    }
    Matrix.Clear();
    Matrix.UpdateMatrix();
  }
  for (int j= 0;j<8;j++)
  {
    Matrix.Line(0,7,j,0);
    for( int i = 0;i<20;i++) 
    {
      Matrix.UpdateMatrix();
    }
    Matrix.Clear();
    Matrix.UpdateMatrix();
  }
  for (int j= 7;j>=0;j--)
  {
    Matrix.Line(7,7,0,j);
    for( int i = 0;i<20;i++) 
    {
      Matrix.UpdateMatrix();
    }
    Matrix.Clear();
    Matrix.UpdateMatrix();
  }
}
