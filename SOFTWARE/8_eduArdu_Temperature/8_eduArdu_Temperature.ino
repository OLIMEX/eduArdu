/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo that shows temperature on the LED matrix (sliding the text).
On the terminal you can monitor the raw data and the temperature.
**********************************************************************/

#include <string.h>
#include <TCN75.h>
#include <LED_Matrix.h>

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
  PrevTime = Time;
  float Temp = T.Temperature ();
  
  Serial.print("Current temperature = ");
  Serial.println (Temp);
  Serial.print("Raw data = 0x");
  Serial.println (T.RawData (), HEX);
  sprintf (Buff, "%dC ", (int)Temp);
    
  Matrix.DisplayText ((unsigned char*)Buff);
  for(int i=0;i<strlen(Buff)*8;)
  {
    Time=millis();
    if(Time - PrevTime >100){
       Matrix.SlideLeft (1);
       i++;
       PrevTime = Time;
      } 
      
      Matrix.UpdateText ();
     
  }
}
