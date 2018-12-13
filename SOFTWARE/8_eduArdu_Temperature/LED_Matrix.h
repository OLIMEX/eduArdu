/*
LED_Matrix is a Library to drive the Olimex 8x8 (non-rgb) matrix
Based on the original library LED_Matrix created by Lutz Reiter, Dec 2014.
*/

#ifndef _LED_MATRIX_H
#define _LED_MATRIX_H

#define ROWS 8
#define STRING_MAX_CHAR  64

#include <Arduino.h>
#include "font.h"

typedef unsigned char uchar;

class LED_Matrix
{
public:
	LED_Matrix(int latchPin, int dataPin, int clockPin);

	// clears matrix
	void clear();

	void SetBrightness (int Brightness);

	void ChangeBrightness (int X);
	
	void drawArray(int x, int y, const uchar *array, int rows);

	// draws a pixel
	void drawPixel(int x, int y);

	void DrawColumn(int Column, unsigned char Byte);

	void DisplayChar (char C);

	void CharIntoBuffer (unsigned char C, int Index);

	void StringIntoBuffer (unsigned char Str[], int Index);
	
	void DisplayText(unsigned char Str[]);
	
	void DisplayText(unsigned char Str[], int Offset);

	void UpdateText();

	void SlideRight (int Positions);

	void SlideLeft (int Positions);

	// erase a Pixel
	void erasePixel(int x, int y);

	void drawLine(int x, int y, int length, boolean horizontal = true);

	// draws a rectangle
	void drawRectangle(int x, int y, int w, int h, boolean filled = false);

	// shifts the data to the led-matrix to display it
	//the multiplexing has to be done by the arduino, so this function has to be called constantly
	void UpdateMatrix();

private:
	int LED_Offset, TextLen;
	unsigned char TextBuffer[STRING_MAX_CHAR * CHAR_WIDTH];
	uchar matrix[ROWS];
	int brightness; // 255 highest brigthness, 0 lowest brightness
	int latchPin,dataPin,clockPin;
};

#endif

