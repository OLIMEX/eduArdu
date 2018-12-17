#include "Joystick.h"
#include "Buzzer.h"

Buzzer Buzz (6);

void setup()
{
  pinMode (31, INPUT);  // button
  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (13, INPUT);
  pinMode (14, INPUT);
  pinMode (15, INPUT);
  pinMode (16, INPUT);
}

void loop()
{
  if (!digitalRead (9)) {
     Buzz.Beep(1000);
     delay(300);
     Buzz.Mute();
  }
  
  if (!digitalRead (10)) {
     Buzz.Beep(1500);
     delay(300);
     Buzz.Mute();
  }
  
  if (!digitalRead (13)) {
     Buzz.Beep(2000);
     delay(300);
     Buzz.Mute();
  }
    
  if (!digitalRead (14)) {
     Buzz.Beep(2500);
     delay(300);
     Buzz.Mute();
  }
  
  if (!digitalRead (15)) {
     Buzz.Beep(3000);
     delay(300);
     Buzz.Mute();
  }
    
  if (!digitalRead (16)) {
     Buzz.Beep(3500);
     delay(300);
     Buzz.Mute();
  }
}
