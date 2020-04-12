/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description: Capacitive sense MakeyMakey implementation
Demo sketch using the default Arduino library "Keyboard".
When D9/D10/D13/D14/D15/D16 are low they trigger
keys on the keyboard respectively: a/b/c/d/e/f
**********************************************************************/

#include "Keyboard.h"
#include "pins_arduino.h" // Arduino pre-1.0 needs this
#include <Olimex_Joystick.h>
#include <Olimex_Capacitive_Pin.h>

Olimex_Joystick Joy (A0, A1);
Olimex_Capacitive_Pin CPin9(9), CPin10(10), CPin23(23), CPin14(14), CPin15(15), CPin16(16);

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
#define _KEY_D10  's'
#define _KEY_D23  'd'
#define _KEY_D14  'f'
#define _KEY_D15  'g'
#define _KEY_D16  'w'


void setup()
{
  Serial.begin (115200);
  Keyboard.begin();
}

void loop ()
{
  if (CPin9.Read() >3) 
    Keyboard.press(_KEY_D9);
  else 
    Keyboard.release(_KEY_D9);

  if (CPin10.Read() >3)
    Keyboard.press(_KEY_D10);
  else
    Keyboard.release(_KEY_D10);
    
  if (CPin23.Read() >3)
    Keyboard.press(_KEY_D23);
  else
    Keyboard.release(_KEY_D23);
    
  if (CPin14.Read() >3)
    Keyboard.press(_KEY_D14);
  else
    Keyboard.release(_KEY_D14);

  if (CPin15.Read() >3)
    Keyboard.press(_KEY_D15);
  else
    Keyboard.release(_KEY_D15);
    
  if (CPin16.Read() >3)
    Keyboard.press(_KEY_D16);
  else
    Keyboard.release(_KEY_D16);

   if (Joy.X () < 20)
      Keyboard.press(KEY_LEFT_ARROW);
   else
      Keyboard.release(KEY_LEFT_ARROW);
      
   if (Joy.X () > 80)
      Keyboard.press(KEY_RIGHT_ARROW);
   else
      Keyboard.release(KEY_RIGHT_ARROW);

   if (Joy.Y () < 20)
      Keyboard.press(KEY_DOWN_ARROW);
   else
      Keyboard.release(KEY_DOWN_ARROW);

   if (Joy.Y () > 80)
      Keyboard.press(KEY_UP_ARROW);
   else
      Keyboard.release(KEY_UP_ARROW);

   if (Joy.But ())
      Keyboard.press(' ');
   else
      Keyboard.release(' ');
   
}
