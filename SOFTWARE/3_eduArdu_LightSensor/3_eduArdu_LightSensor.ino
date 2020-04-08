/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
The buzzer beeps (if enabled) with frequency depending on
the light sensor value. You toggle the buzzer enable/disable by
pushing the button. By default it is disabled.
On the terminal you can monitor the light sensor data (raw and %)
**********************************************************************/

#include <Olimex_Buzzer.h>
#include <Olimex_Light_Sensor.h>
#include <Olimex_Joystick.h>

Olimex_Light_Sensor Sensor(A2);
Olimex_Buzzer Buzz (6);
Olimex_Joystick Joy (A0, A1);

char Buff[64];
int Data, BuzzOn = 0, Flag = 1;
float DataP;

void setup()
{
  Serial.begin (115200);
}

void loop()
{
  if (Joy.But() && Flag) // push the button on the joystick to start the buzzzer
  {
    Flag = 0;
    delay (50);
    BuzzOn = !BuzzOn; // Turn On/Off the Buzzer
  }
  if (!Joy.But())
    Flag = 1;

  Data = Sensor.Read ();
  DataP = Sensor.ReadPercentage ();
  sprintf (Buff, "Raw data: %d; Percentage: %d%%", Data, (int)DataP);
  Serial.println (Buff);

  if (BuzzOn)
    Buzz.Beep (Data);
  else
    Buzz.Mute ();
  delay (100);
}
