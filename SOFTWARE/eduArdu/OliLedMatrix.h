/*
OliLedMatrix is a Library to drive the Olimex 8x8 (non-rgb) matrix
Created by Lutz Reiter, Dec 2014.
Use it however you want to.
*/ 

#ifndef _OLI_LED_MATRIX
#define _OLI_LED_MATRIX

#define ROWS 8

#include <Arduino.h>

typedef unsigned char uchar;

class OliLedMatrix
{
public:
	uchar brightness; // 255 highest brigthness, 0 lowest brightness
	OliLedMatrix(int latchPin, int dataPin, int clockPin);

	// clears matrix
	void clear();
	
	void drawArray(int x, int y, const uchar *array, int rows);

	// draws a pixel
	void drawPixel(int x, int y);

	// erase a Pixel
	void erasePixel(int x, int y);

	void drawLine(int x, int y, int length, boolean horizontal = true);

	// draws a rectangle
	void drawRectangle(int x, int y, int w, int h, boolean filled = false);

	// shifts the data to the led-matrix to display it
	//the multiplexing has to be done by the arduino, so this function has to be called constantly
	void display();

private:
	uchar matrix[ROWS];
	int latchPin,dataPin,clockPin;
};

#endif

