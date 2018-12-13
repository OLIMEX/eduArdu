#include "Light_Sensor.h"

Light_Sensor::Light_Sensor (int _Pin)
{
	Pin = _Pin;
	pinMode (Pin, INPUT_PULLUP);
}

int Light_Sensor::Read ()
{
	return analogRead(Pin);
}

float Light_Sensor::ReadPercentage ()
{
	return Read() * 100.0/1023.0;
}
