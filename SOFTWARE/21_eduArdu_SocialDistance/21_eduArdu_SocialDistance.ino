/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.12
Date: 2020/04/07

Description:
The buzzer beeps is someone get closer than 1.5 meters
**********************************************************************/

#include <Olimex_Buzzer.h>
#include <NewPing.h>

#define US_TX 8
#define US_RX 4
#define MAX_DISTANCE   200 	// max distance in cm

Olimex_Buzzer Buzz (6);
NewPing Sonar(US_TX, US_RX, MAX_DISTANCE);

int distance;

void setup()
{
  Serial.begin (115200);
}

void loop()
{
  distance = Sonar.ping_cm ();
  if (distance == 0) distance = 151;
  Serial.println(distance);

  if (distance<=150) {
    Buzz.Beep (1000);
    delay(100);
    Buzz.Mute ();
  }
  delay (500);
}
