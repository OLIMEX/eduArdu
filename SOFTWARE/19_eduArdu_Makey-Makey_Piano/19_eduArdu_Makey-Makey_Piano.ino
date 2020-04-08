/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.12
Date: 2020/02/19

Description: Capacitive sense MakeyMakey implementation
Demo sketch using the default Arduino library "Keyboard"

**********************************************************************/

#include "Keyboard.h"
#include "pins_arduino.h" // Arduino pre-1.0 needs this
#include <Olimex_Buzzer.h>
#include <Olimex_Capacitive_Pin.h>

Olimex_Buzzer Buzz (6);
Olimex_Capacitive_Pin CPin9(9), CPin10(10), CPin23(23), CPin14(14), CPin15(15), CPin16(16);

void setup()
{
  Serial.begin (115200);
  Keyboard.begin();
}

void loop ()
{
  if (CPin9.Read() > 10) 
  {
     Buzz.Beep(1000);
     delay(300);
     Buzz.Mute();
  }

  if (CPin10.Read() > 10)
  {
     Buzz.Beep(1500);
     delay(300);
     Buzz.Mute();
  }
    
  if (CPin23.Read() > 10)
  {
     Buzz.Beep(2000);
     delay(300);
     Buzz.Mute();
  }
    
  if (CPin14.Read() > 10)
  {
     Buzz.Beep(2500);
     delay(300);
     Buzz.Mute();
  }

  if (CPin15.Read() > 10)
  {
     Buzz.Beep(3000);
     delay(300);
     Buzz.Mute();
  }
    
  if (CPin16.Read() > 10)
  {
     Buzz.Beep(3500);
     delay(300);
     Buzz.Mute();
  }
   
}
