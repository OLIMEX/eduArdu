/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo sketch using the default Arduino library "Keyboard".
When D9/D10/D13/D14/D15/D16 are low they trigger
keys on the keyboard respectively: a/b/c/d/e/f
**********************************************************************/

#include "Keyboard.h"

/* Special keys
 *  KEY_LEFT_CTRL   KEY_LEFT_SHIFT   KEY_LEFT_ALT   KEY_LEFT_GUI   
 *  KEY_RIGHT_CTRL  KEY_RIGHT_SHIFT  KEY_RIGHT_ALT  KEY_RIGHT_GUI
 *  KEY_UP_ARROW    KEY_DOWN_ARROW   KEY_LEFT_ARROW KEY_RIGHT_ARROW
 *  KEY_BACKSPACE   KEY_TAB          KEY_RETURN     KEY_ESC
 *  KEY_INSERT      KEY_DELETE       KEY_PAGE_UP    KEY_PAGE_DOWN   
 *  KEY_HOME        KEY_END          KEY_CAPS_LOCK  
 *  KEY_F1 ...KEY_F24
 */

#define _KEY_D9   'a'
#define _KEY_D10  'b'
#define _KEY_D23  'c'
#define _KEY_D14  'd'
#define _KEY_D15  'e'
#define _KEY_D16  'f'


void setup()
{
  Serial.begin (115200);
  Keyboard.begin();

  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (23, INPUT);
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
    
  if (!digitalRead (23))
    Keyboard.press(_KEY_D23);
  else
    Keyboard.release(_KEY_D23);
    
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
