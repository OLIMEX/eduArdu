/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
A simple demo that blink the builtin LED (D12) with frequency 1 Hz.
**********************************************************************/

#define LED 12

void setup ()
{
  pinMode (LED, OUTPUT);
}

void loop ()
{
  digitalWrite (LED, HIGH);
  delay (1000);
  digitalWrite (LED, LOW);
  delay (1000);
}

