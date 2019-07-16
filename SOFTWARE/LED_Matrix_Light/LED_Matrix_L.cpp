/*
LED_Matrix is a Library to drive the Olimex 8x8 (non-rgb) matrix
Based on the original library LED_Matrix created by Lutz Reiter, Dec 2014.
*/
#include "LED_Matrix_L.h"

LED_Matrix_L::LED_Matrix_L(int latchPin, int dataPin, int clockPin)
{
	this->dataPin = dataPin;
	this->latchPin = latchPin;
	this->clockPin = clockPin;

	pinMode (latchPin, OUTPUT);
	pinMode (clockPin, OUTPUT);
	pinMode (dataPin, OUTPUT);

	this->Clear();
}

void LED_Matrix_L::Clear()		// Clears matrix
{
	for (int i=0;i<ROWS;i++)
	this->matrix[i] = 0;
}

// draws a pixel
void LED_Matrix_L::SetPixel(int x, int y)
{
	if ((x<0) || (x>=ROWS) || (y<0) || (y>=ROWS))
		return;
	matrix[7-x] |= (1<<y);
}

// erase a Pixel
void LED_Matrix_L::ClearPixel(int x, int y)
{
	if ((x<0) || (x>=ROWS) || (y<0) || (y>=ROWS))
		return;

	matrix[7-x] &= ~(1<<y);
}

// Get the value of the coordinates pixel
int LED_Matrix_L::GetPixel(int x, int y)
{
	if ((x<0) || (x>=ROWS) || (y<0) || (y>=ROWS))
		return;
	if (matrix[7-x] & (1<<y))
		return 1;
	else
		return 0;
}

void LED_Matrix_L::Line (int x1, int y1, int x2, int y2)
{
	int dx, dy, sx, sy, err, e2;
	dx = abs (x2-x1);
	dy = abs (y2-y1);
	if (x1<x2)
		sx = 1;
	else
		sx = -1;
	if (y1<y2)
		sy = 1;
	else
		sy = -1;
	err = dx-dy;
	do
	{
		SetPixel (x1, y1);
		if ((x1 == x2) && (y1 == y2))
			break;
		e2 = 2*err;
		if (e2 > -dy)
		{
			err = err - dy;
			x1 = x1+sx;
		}
		if (e2 < dx)
		{
			err = err + dx;
			y1 = y1 + sy;
		}
	}
	while (1);

	return;
}

// draws a rectangle
void LED_Matrix_L::DrawRectangle(int x, int y, int w, int h, boolean filled)
{
	if (filled)
	{
		for(int i=y; i<y+h; i++)
			for(int j=x; j<x+w; j++)
				this->SetPixel(i,j);
	}
	else
	{
		for(int i=y; i<y+h; i++)
		{
			this->SetPixel(x,i);
			this->SetPixel(x+w-1,i);
		}
		for(int i=x; i<x+w; i++)
		{
			this->SetPixel(i,y);
			this->SetPixel(i,y+h-1);
		}
	}
}

void LED_Matrix_L::UpdateMatrix()
{
	for (byte i=0; i<ROWS; i++)
	{
		// bitwise operations are faster
		PORTB = PORTB & 0x7F;	//digitalWrite(this->latchPin, LOW);
		shiftOut(this->dataPin, this->clockPin, LSBFIRST, matrix[i]);
		shiftOut(this->dataPin, this->clockPin, LSBFIRST, 1 << i);
    PORTB = PORTB | 0x80; //digitalWrite(this->latchPin, HIGH);
	}

}
