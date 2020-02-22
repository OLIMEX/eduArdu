#ifndef	_BUZZER_H
#define	_BUZZER_H

#include <Arduino.h>
#include "Notes.h"

class Buzzer
{
public:
	Buzzer (int _Pin);
	void Beep (int Frequency);
	void Note (int Frequency, int Duration);
	void Mute ();
	void Play (const int Notes[], const float Durations[], int Tempo);
private:
	int Pin;
};

#endif
