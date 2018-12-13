/*
LED_Matrix is a Library to drive the Olimex 8x8 (non-rgb) matrix
Based on the original library LED_Matrix created by Lutz Reiter, Dec 2014.
*/
#include "LED_Matrix.h"

LED_Matrix::LED_Matrix(int latchPin, int dataPin, int clockPin)
{
	this->dataPin = dataPin;
	this->latchPin = latchPin;
	this->clockPin = clockPin;

	pinMode (latchPin, OUTPUT);
	pinMode (clockPin, OUTPUT);
	pinMode (dataPin, OUTPUT);

	this->brightness = 255;
	
	LED_Offset = 0;

	this->clear();
}

// clears matrix
void LED_Matrix::clear()
{
	for (int i=0;i<ROWS;i++)
	this->matrix[i] = 0;
}

void LED_Matrix::SetBrightness (int Brightness)
{
	if (Brightness > 255)
		Brightness = 255;
	if (Brightness < 0)
		Brightness = 0;
	brightness = Brightness;
}

void LED_Matrix::ChangeBrightness (int X)
{
	brightness = brightness + X;
	if (brightness > 255)
		brightness = 255;
	if (brightness < 0)
		brightness = 0;
}

/* 
draws an array to the matrix, one char represents one row with 8 columns
x and y defines the offset where the input array should be drawn.
rows is the lengh of the input array
*/
void LED_Matrix::drawArray(int x, int y, const uchar *array, int rows)
{
	for (int i=0; i<rows; i++)
		matrix[7-(i+x)] |= (BitReverseTable256[array[i]] >> y);
		//matrix[7-(i+x)] |= Temp >> y;
}

// draws a pixel
void LED_Matrix::drawPixel(int x, int y)
{
	if ((x<0) || (x>=ROWS) || (y<0) || (y>=ROWS))
		return;
	matrix[7-x] |= (1<<y);
}

// uncomment one of the lines depending on the orientation of the LED_Matrix
void LED_Matrix::DrawColumn(int Column, unsigned char Byte)
{
	matrix[7-Column] = BitReverseTable256[Byte];
	//matrix[7-Column] = Byte;
	//matrix[Column] = BitReverseTable256[Byte];
	//matrix[Column] = Byte;
}

void LED_Matrix::DisplayChar (char C)
{
	int i;
	clear();
	for (i=0; i<CHAR_WIDTH-1; i++)
		DrawColumn (i, FontLookup[C-0x20][i]);
	UpdateMatrix ();
}

void LED_Matrix::CharIntoBuffer (unsigned char C, int Index)
{
	int i;
	for (i=0; i<CHAR_WIDTH; i++)
		if (i==CHAR_WIDTH - 1)
			TextBuffer[Index*CHAR_WIDTH + i] = 0;
		else
			TextBuffer[Index*CHAR_WIDTH + i] = FontLookup[C-0x20][i];
}

void LED_Matrix::StringIntoBuffer (unsigned char Str[], int Index)
{
	int i;
	for (i=0; Str[i]; i++)
		CharIntoBuffer(Str[i], Index+i);
	TextLen = i;
}

void LED_Matrix::DisplayText(unsigned char Str[])
{
	int i;
	StringIntoBuffer (Str, 0);
	clear();
	for (i=0; i<8; i++)
		DrawColumn (i, TextBuffer[(LED_Offset + i)%(CHAR_WIDTH * TextLen)]);
	UpdateMatrix();
}

void LED_Matrix::DisplayText(unsigned char Str[], int Offset)
{
	int i;
	StringIntoBuffer (Str, 0);
	LED_Offset = Offset;
	clear();
	for (i=0; i<8; i++)
		DrawColumn (i, TextBuffer[(LED_Offset + i)%(CHAR_WIDTH * TextLen)]);
	UpdateMatrix();
}

void LED_Matrix::UpdateText()
{
	int i;
	clear();
	for (i=0; i<8; i++)
		DrawColumn (i, TextBuffer[(LED_Offset + i)%(CHAR_WIDTH * TextLen)]);
	UpdateMatrix();
}

void LED_Matrix::SlideRight (int Positions)
{
	LED_Offset=LED_Offset - Positions;
	if (LED_Offset < 0)
		LED_Offset = LED_Offset + (CHAR_WIDTH * TextLen);
	UpdateText ();
}

void LED_Matrix::SlideLeft (int Positions)
{
	LED_Offset = (LED_Offset + Positions) % (CHAR_WIDTH * TextLen);
	UpdateText ();
}

// erase a Pixel
void LED_Matrix::erasePixel(int x, int y)
{
	if ((x<0) || (x>=ROWS) || (y<0) || (y>=ROWS))
		return;

	matrix[7-x] &= ~(1<<y);
}

void LED_Matrix::drawLine(int x, int y, int length, boolean horizontal)
{
	if (!horizontal)
		for(int i=0; i<length; i++)
			drawPixel(x,y+i);
	else
		for(int i=0; i<length; i++)
			drawPixel(x+i,y);
}

// draws a rectangle
void LED_Matrix::drawRectangle(int x, int y, int w, int h, boolean filled)
{
	if (filled)
	{
		for(int i=y; i<y+h; i++)
			for(int j=x; j<x+w; j++)
				this->drawPixel(i,j);
	}
	else
	{
		for(int i=y; i<y+h; i++)
		{
			this->drawPixel(x,i);
			this->drawPixel(x+w-1,i);
		}
		for(int i=x; i<x+w; i++)
		{
			this->drawPixel(i,y);
			this->drawPixel(i,y+h-1);
		}
	}
}

// shifts the data to the led-matrix to display it
//the multiplexing has to be done by the arduino, so this function has to be called constantly
void LED_Matrix::UpdateMatrix()
{
	for (byte i=0; i<ROWS; i++)
	{
		// bitwise operations are faster
		PORTB = PORTB & 0x7F;	//digitalWrite(this->latchPin, LOW);
		shiftOut(this->dataPin, this->clockPin, LSBFIRST, matrix[i]);
		shiftOut(this->dataPin, this->clockPin, LSBFIRST, 1 << i);
		PORTB = PORTB | 0x80;	//digitalWrite(this->latchPin, HIGH);
		//delayMicroseconds(20);

		// make the display less bright
		if (this->brightness < 255)
		{
			PORTB = PORTB & 0x7F;	//digitalWrite(this->latchPin, LOW);
			shiftOut(this->dataPin, this->clockPin, LSBFIRST, 0);
			shiftOut(this->dataPin, this->clockPin, LSBFIRST, 1 << i);
			PORTB = PORTB | 0x80;	//digitalWrite(this->latchPin, HIGH);
			delayMicroseconds((255 - this->brightness)*8);
		}
	}
}

