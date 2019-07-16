/*
LED_Matrix_L is lightweight Library to drive the Olimex 8x8 (non-rgb) matrix
*/

#ifndef _LED_MATRIX_L_H
#define _LED_MATRIX_L_H

#define ROWS 8

#include <Arduino.h>

typedef unsigned char uchar;

class LED_Matrix_L
{
public:
	LED_Matrix_L(int latchPin, int dataPin, int clockPin);	// constructor for an object of the class initializing the SPI pins

	void Clear(); 				// clears matrix

	void SetPixel(int x, int y);		// Light on pixel XY

	void ClearPixel(int x, int y);		// Light off pixel XY

	int GetPixel(int x, int y);		//return 1 if On ; 0 if Off

	void Line (int x1, int y1, int x2, int y2);	//draw line

	void DrawRectangle(int x, int y, int w, int h, boolean filled = false); //draws a rectangle

	void UpdateMatrix();	//refresh the display

private:
	uchar matrix[ROWS];	// contains the data shown on the LED matrix
	int latchPin,dataPin,clockPin;	// SPI pins
};

#endif
