#include "Buzzer.h"

Buzzer::Buzzer (int _Pin)
{
	Pin = _Pin;
	pinMode (Pin, OUTPUT);
}

void Buzzer::Beep (int Frequency)
{
	tone(Pin, Frequency);
}

void Buzzer::Note (int Frequency, int Duration)
{
	//Play tone on buzzerPin
	if (Frequency != _P)
		tone(Pin, Frequency);
	delay(Duration);
	//Stop tone on buzzerPin
	noTone(Pin);

	delay(20);  // very short silence between the notes to distinguish the equal tones (not to be mistaken with the pauses)
}

void Buzzer::Mute ()
{
	noTone (Pin);
}

void Buzzer::Play (const int Notes[], const float Durations[], int Tempo)
{
  int i, TPQ = 60000/Tempo;	// TPQ stands for Time Per Quarter (note). Calculates duration of a quarter note in milliseconds
  for (i=0; Notes[i] != _END; i++)
    Note(Notes[i], Durations[i]*TPQ);
}
