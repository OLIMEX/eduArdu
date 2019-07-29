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
#include <Joystick.h>

Joystick Joy (A0, A1);

// readCapacitivePin

//  Input: Arduino pin number
//  Output: A number, from 0 to 30 expressing
//  how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher



uint8_t readCapacitivePin(int pinToMeasure) {

  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;

  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.

  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);

  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  delay(1);

  uint8_t SREG_old = SREG; //back up the AVR Status Register

  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();

  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
  uint8_t cycles = 20;

  if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}
  else if (*pin & bitmask) { cycles = 17;}
  else if (*pin & bitmask) { cycles = 18;}
  else if (*pin & bitmask) { cycles = 19;}
  else if (*pin & bitmask) { cycles = 20;}
  else if (*pin & bitmask) { cycles = 21;}
  else if (*pin & bitmask) { cycles = 22;}
  else if (*pin & bitmask) { cycles = 23;}
  else if (*pin & bitmask) { cycles = 24;}
  else if (*pin & bitmask) { cycles = 25;}
  else if (*pin & bitmask) { cycles = 26;}
  else if (*pin & bitmask) { cycles = 27;}
  else if (*pin & bitmask) { cycles = 28;}
  else if (*pin & bitmask) { cycles = 29;}
  else if (*pin & bitmask) { cycles = 30;}

  // End of timing-critical section; turn interrupts back on if they were on before, or leave them off if they were off before
  SREG = SREG_old;

  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}


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
#define _KEY_D13  'd'
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
  if (readCapacitivePin(9) >3) 
    Keyboard.press(_KEY_D9);
  else 
    Keyboard.release(_KEY_D9);

  if (readCapacitivePin(10) >3)
    Keyboard.press(_KEY_D10);
  else
    Keyboard.release(_KEY_D10);
    
  if (readCapacitivePin(13) >3)
    Keyboard.press(_KEY_D13);
  else
    Keyboard.release(_KEY_D13);
    
  if (readCapacitivePin(14) >3)
    Keyboard.press(_KEY_D14);
  else
    Keyboard.release(_KEY_D14);

  if (readCapacitivePin(15) >3)
    Keyboard.press(_KEY_D15);
  else
    Keyboard.release(_KEY_D15);
    
  if (readCapacitivePin(16) >3)
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
