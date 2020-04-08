/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.12
Date: 2020/04-07

Description:
Demo that shows temperature measured with MOD-IR-TEMP on the LED matrix 
(sliding the text). 
On the terminal you can monitor the raw data and the temperature.
**********************************************************************/
#include <string.h>
#include "floatToString.h"
#include <Olimex_LED_Matrix.h>
#include <Adafruit_MLX90614.h>
#include <Olimex_Buzzer.h>

Adafruit_MLX90614 modIrTemp = Adafruit_MLX90614();

// LED Matrix pins
#define LED_LATCH 11
#define LED_DATA 16
#define LED_CLOCK 15

Olimex_LED_Matrix Matrix(LED_LATCH,LED_DATA,LED_CLOCK);

Olimex_Buzzer Buzz (6);

char str[10];
float Temp;

void setup()
{
  modIrTemp.begin();  
  Serial.begin(115200);
}

void loop()
{
  static unsigned long Time=0, PrevTime=0; 
  PrevTime = Time;
  Temp = modIrTemp.readObjectTempC();

  floatToString(str, Temp, 1,2);
  strcat(str,"C ");

  if (Temp>38.0)
    for (int b =0;b<3;b++) {
      Buzz.Beep(1000);
      delay(100);
      Buzz.Mute();
      delay(100);    
    }
 
  Matrix.DisplayText ((unsigned char*)str);
  for(int i=0;i<strlen(str)*8;)
  {
    Time=millis();
    if(Time - PrevTime >60){
       Matrix.SlideLeft (1);
       i++;
       PrevTime = Time;
      } 
      
      Matrix.UpdateText ();
     
  }
}
