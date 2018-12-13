/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
This demo is based on IRsendDemo sketch of the "IRremote" library.
Allows you to send commands by pressing the button or moving
the joystick in the four directions:
Left/Right is for decrease/increase volume of the sound.
Up/Down is for channel up/down.
Pushing the button is turn on/off.

IMPORTANT: For eduArdu rev.A you need to use the patched IRremote library:
https://github.com/OLIMEX/eduArdu/blob/master/SOFTWARE/4_eduArdu_Infrared/IRremote.zip

Note: The command codes are different for each device so you
have to define them in your sketch in order to work properly.
**********************************************************************/

#include <IRremote.h>  // go to Sketch --> Include Library --> Manage Libraries --> IRremote (tested with 2.2.3v)
#include "Joystick.h"

IRsend irsend;
Joystick Joy(A0, A1); // X, Y

#define _RC5
//#define _NEC

#ifdef  _RC5
  // RC5 macros
  // these macros may differ for the different devices.
  #define DIGIT(Digit)  (0x40|Digit)
  #define TURN_ON_OFF 0x4C
  #define VOLUME_UP 0x50
  #define VOLUME_DOWN 0x51
  #define CHANNEL_UP  0x60
  #define CHANNEL_DOWN  0x61
  #define CHANNEL_SWAP  0x62
  #define MENU  0x70
  #define ARROW_DOWN  0x53
  #define ARROW_UP  0x54
  #define ARROW_LEFT  0x55
  #define ARROW_RIGHT  0x56
  #define OK  0x75


void Send (unsigned long int Command)
{
  static int Invert = 0;
  irsend.sendRC5 (Invert | Command, 12);
  Invert = Invert ^ 0x800;
  delay (50);
}

#elif defined _NEC
  // define NEC macros
  // these macros may differ for the different devices.
  #define TURN_ON_OFF 0x7
  #define CHANNEL_DOWN 0xFFA25D
  #define CHANNEL_UP 0xFFE21D
  #define PREV  0xFF22DD
  #define NEXT  0xFF02FD
  #define PLAY_PAUSE  0xFFC23D
  #define VOLUME_DOWN 0xFFE01F
  #define VOLUME_UP 0xFFA857
  #define EQ  0xFF906F
  #define DIGIT_0 0xFF6897
  #define DIGIT_1 0xFF30CF
  #define DIGIT_2 0xFF18E7
  #define DIGIT_3 0xFF7A85
  #define DIGIT_4 0xFF10EF
  #define DIGIT_5 0xFF38C7
  #define DIGIT_6 0xFF5AA5
  #define DIGIT_7 0xFF42BD
  #define DIGIT_8 0xFF4AB5
  #define DIGIT_9 0xFF52AD
  #define CHANNEL_100 0xFF9867
  #define CHANNEL_200 0xFFB04F

void Send (unsigned long int Command)
{
  irsend.sendNEC (Command, 32);
  delay (50);
}
#else
  #error No infrared protocol defined! Define at least one infrared protocol!
#endif

void setup()
{
}

bool ButtonReleased = true;
void loop()
{
  if (Joy.But () && ButtonReleased)
  {
    ButtonReleased = false;
    Send(TURN_ON_OFF);
    delay (50);
  }
  if (!Joy.But ())
    ButtonReleased = true;

  if (Joy.X () < 20)
    Send(VOLUME_DOWN);
  if (Joy.X () > 80)
    Send(VOLUME_UP);
  if (Joy.Y () < 20)
    Send(CHANNEL_DOWN);
  if (Joy.Y () > 80)
    Send(CHANNEL_UP);
}
