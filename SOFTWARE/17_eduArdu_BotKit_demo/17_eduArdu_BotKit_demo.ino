/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo sketch using the default Arduino library "Servo".
Servo 1 and 2 are controled by microphone.
Clapping once makes Servo1 and Servo2 move making different movements
Clapping twice makes Servo1 and Servo2 stop rotating and the car stops.
Clapping once again the car moves again into another direction.

 Directions:

 1st time - forward
 2nd time - turn right
 3rd time - backward
 4th time - turn left

 Every second clap activates car's break. 

**********************************************************************/

#include <Servo.h>

#define LED 12
#define MICROPHONE  A3

#define THRESHOLD 350  // higher value means less sensitivity

Servo Servo1, Servo2;

typedef enum state{
  MOVE_FORWARD = 0,
  MOVE_RIGHT,
  MOVE_BACKWARD,
  MOVE_LEFT,
  MOVE_STOP
}states;


states ST_MACHINE = MOVE_STOP;


uint8_t break_flag = 1;

/* Servo control */
void servo_break()
{
    Servo1.write(90);
    Servo2.write(90);
  
}

void servo_fwd()
{
    Servo1.write(180);
    Servo2.write(0);
  
}

void servo_bwd()
{
    Servo1.write(0);
    Servo2.write(180);
  
}

void servo_left()
{
    Servo1.write(40);
    Servo2.write(40);
}

void servo_right()
{
    Servo1.write(120);
    Servo2.write(120);
}


/* Microphone clap recognition */

uint8_t clap_detect()
{

 int Max=0, Min=1024;
  for(int i=0; i<50; i++) // taking a sequence of samples to determine whether there is noise or not
  {
    int Sample;
    Sample = analogRead(MICROPHONE);
    if (Sample > Max)
      Max = Sample;

    if (Sample < Min)
      Min = Sample;

    if((Max-Min) > THRESHOLD)
    {
      digitalWrite (LED, !digitalRead(LED));
      
      delay(300);
     return 1;
    }
    
  }

  return 0;
}

void setup()
{
  Servo1.attach(9);
  Servo2.attach(10);
    pinMode(LED, OUTPUT);
  digitalWrite (LED, LOW);

  Serial.begin(115200);
  delay(200);
  
}

void loop()
{

  while(clap_detect()==0);

  if (break_flag == 0)
  {
    switch (ST_MACHINE) {
      case MOVE_FORWARD: ST_MACHINE = MOVE_RIGHT; servo_right(); break;
      case MOVE_RIGHT: ST_MACHINE = MOVE_BACKWARD; servo_bwd(); break;
      case MOVE_BACKWARD: ST_MACHINE = MOVE_LEFT;  servo_left(); break;
      case MOVE_LEFT: ST_MACHINE = MOVE_FORWARD;  servo_fwd(); break;
      default: ST_MACHINE = MOVE_FORWARD;  servo_fwd(); break;
      
    }
    break_flag = 1;
  }
  else {
    servo_break();

    break_flag = 0;
  }

 
  
}
