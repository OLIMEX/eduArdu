#include "Joystick.h"

Joystick::Joystick (int PinX, int PinY, int PinBut)
{
	X_Axis = PinX;
	Y_Axis = PinY;
	B = PinBut;

	pinMode (B, INPUT);
	pinMode (X_Axis, INPUT_PULLUP); // Joystick X axis
	pinMode (Y_Axis, INPUT_PULLUP); // Joystick Y axis
}

float Joystick::X_Raw ()
{
	return analogRead(X_Axis);
}

float Joystick::Y_Raw ()
{
	return analogRead(Y_Axis);
}

float Joystick::X ()
{
	return analogRead(X_Axis) * 100.0 / 1023.0;
}

float Joystick::Y ()
{
	return analogRead(Y_Axis) * 100.0 / 1023.0;
}

bool Joystick::But ()
{
	return digitalRead (B);
}