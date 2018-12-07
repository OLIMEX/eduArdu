#ifndef	_JOYSTICK_H
#define	_JOYSTICK_H

#include <Arduino.h>

class Joystick
{
public:
	Joystick (int PinX, int PinY, int PinBut);
	float X_Raw ();
	float Y_Raw ();
	float X ();
	float Y ();
	bool But ();
private:
	int X_Axis, Y_Axis, B;
};

#endif
