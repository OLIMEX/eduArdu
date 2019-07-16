/**********************************************************************
Demo example for Olimex library "LED_Matrix"
Tested with Arduino 1.8.8 on eduArdu
Date: 2018/12/12

Description:

**********************************************************************/

#include "LED_Matrix_L.h"

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

LED_MatrixL Matrix(LED_LATCH,LED_DATA,LED_CLOCK);

void setup()
{
  Serial.begin (115200);
}

void loop()
{
	Matrix::SetPiexl(1,1);
	
}
