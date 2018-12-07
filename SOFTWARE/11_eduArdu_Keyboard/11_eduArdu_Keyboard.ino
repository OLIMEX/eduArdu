#include "Keyboard.h"

#define _KEY_D9   'a'
#define _KEY_D10  'b'
#define _KEY_D13  'c'
#define _KEY_D14  'd'
#define _KEY_D15  'e'
#define _KEY_D16  'f'


void setup()
{
  Serial.begin (115200);
  Keyboard.begin();

  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (13, INPUT);
  pinMode (14, INPUT);
  pinMode (15, INPUT);
  pinMode (16, INPUT);
}

void loop ()
{
  if (!digitalRead (9))
    Keyboard.press(_KEY_D9);
  else
    Keyboard.release(_KEY_D9);

  if (!digitalRead (10))
    Keyboard.press(_KEY_D10);
  else
    Keyboard.release(_KEY_D10);
    
  if (!digitalRead (13))
    Keyboard.press(_KEY_D13);
  else
    Keyboard.release(_KEY_D13);
    
  if (!digitalRead (14))
    Keyboard.press(_KEY_D14);
  else
    Keyboard.release(_KEY_D14);

  if (!digitalRead (15))
    Keyboard.press(_KEY_D15);
  else
    Keyboard.release(_KEY_D15);
    
  if (!digitalRead (16))
    Keyboard.press(_KEY_D16);
  else
    Keyboard.release(_KEY_D16);
}

