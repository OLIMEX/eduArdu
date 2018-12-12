#include "TCN75.h"

TCN75::TCN75 (int _Address)
{
	Wire.begin ();
	Address = _Address;
}

int TCN75::RawData ()
{
	int Data;
	Wire.beginTransmission(Address);// Start transmission
	Wire.write(0);					// move your register pointer back to 00h
	Wire.endTransmission();			// Stop transmission
	Wire.requestFrom(Address, 2);	// Send me the contents of your first two bytes
	Data = Wire.read();				// first received byte stored here
	Data = (Data<<8) | Wire.read();	// second received byte stored here
	return Data;			// convert received bytes into float value
}

float TCN75::Temperature()
{
	int Data;
	Data = RawData ();
	Data = Data >> 7;
	return (float)Data / 2;
}
