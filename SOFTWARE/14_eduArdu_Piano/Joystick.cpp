#include "Joystick.h"

Joystick::Joystick (int PinX, int PinY)
{
	X_Axis = PinX;
	Y_Axis = PinY;

	Button_on_digital_pin = false;
	DDRE = DDRE & 0xFB;	// hardcoded button on pin PE2
	pinMode (X_Axis, INPUT_PULLUP); // Joystick X axis
	pinMode (Y_Axis, INPUT_PULLUP); // Joystick Y axis
}

Joystick::Joystick (int PinX, int PinY, int PinBut)
{
	X_Axis = PinX;
	Y_Axis = PinY;
	B = PinBut;

	Button_on_digital_pin = true;
	pinMode (B, INPUT);
	pinMode (X_Axis, INPUT_PULLUP); // Joystick X axis
	pinMode (Y_Axis, INPUT_PULLUP); // Joystick Y axis
}

int Joystick::X_Raw ()
{
	return analogRead(X_Axis);
}

int Joystick::Y_Raw ()
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
	if (Button_on_digital_pin)
		return digitalRead (B);
	else
		return PINE & 0x04;
}
