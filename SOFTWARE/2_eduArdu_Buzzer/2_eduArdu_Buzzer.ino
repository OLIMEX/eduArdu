#include "Joystick.h"
#include "Buzzer.h"
#include "Tracks/All_Tracks.h"

Buzzer Buzz (6);
Joystick Joy(A0, A1);

void Imperial_March ()
{
  Buzz.Play (IM1_Note, IM1_Duration, IM1_Tempo);
  Buzz.Play (IM2_Note, IM2_Duration, IM2_Tempo);
  Buzz.Play (IMV1_Note, IMV1_Duration, IMV1_Tempo);
  Buzz.Play (IM2_Note, IM2_Duration, IM2_Tempo);
  Buzz.Play (IMV2_Note, IMV2_Duration, IMV2_Tempo);
}

void Amazing_Grace ()
{
  Buzz.Play (AG1_Note, AG1_Duration, AG1_Tempo);
  Buzz.Play (AG2_Note, AG2_Duration, AG2_Tempo);
}

void Mario_Bros ()
{
  Buzz.Play (MB1_Note, MB1_Duration, MB1_Tempo);
  Buzz.Play (MB2_Note, MB2_Duration, MB2_Tempo);
  Buzz.Play (MB3_Note, MB3_Duration, MB3_Tempo);
  Buzz.Play (MB4_Note, MB4_Duration, MB4_Tempo);
}

void Mario_Bros_Underwater ()
{
  Buzz.Play (MBU1_Note, MBU1_Duration, MBU1_Tempo);
  Buzz.Play (MBU2_Note, MBU2_Duration, MBU2_Tempo);
  Buzz.Play (MBU3_Note, MBU3_Duration, MBU3_Tempo);
  Buzz.Play (MBU4_Note, MBU4_Duration, MBU4_Tempo);
}

void Silent_Night_Holy_Night ()
{
  Buzz.Play (SNHN1_Note, SNHN1_Duration, SNHN1_Tempo);
  Buzz.Play (SNHN2_Note, SNHN2_Duration, SNHN2_Tempo);
  Buzz.Play (SNHN3_Note, SNHN3_Duration, SNHN3_Tempo);
}

void setup()
{
  pinMode (31, INPUT);  // button
}

void loop()
{
  while (!Joy.But ()) // push the button on the joystick to start the buzzzer
    Buzz.Mute ();

  Imperial_March ();
  //Amazing_Grace ();
  //Mario_Bros ();
  //Mario_Bros_Underwater ();
  //Silent_Night_Holy_Night ();
}
