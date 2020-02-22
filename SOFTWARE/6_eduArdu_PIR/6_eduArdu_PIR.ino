/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
A simple demo for PIR detector that triggers the buzzer (like siren)
and turns on the LED (D12) for a short time when motion is detected.
**********************************************************************/

#define LED 12
#define PIR 5
#define BUZZER  6

int pirState = LOW;             // we start, assuming no motion detected

void Siren(int State)
{
  int i;
  if (State)
  {
    for(i=700;i<800;i++)
    {
      tone(BUZZER,i);
      delay(10);
    }
    for(i=800;i>700;i--)
    {
      tone(BUZZER,i);
      delay(10);
    }
  }
  else
    noTone (BUZZER);
}

void setup()
{
  pinMode(LED, OUTPUT);      // declare LED as output
  pinMode(PIR, INPUT);     // declare sensor as input
 
  Serial.begin(115200);
}

void loop()
{
  if (digitalRead(PIR) == HIGH) // check if the input is HIGH
  {
    digitalWrite(LED, HIGH);  // turn LED ON
    Siren (1);
    if (pirState == LOW)
    {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(LED, LOW); // turn LED OFF
    Siren (0);
    if (pirState == HIGH)
    {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
