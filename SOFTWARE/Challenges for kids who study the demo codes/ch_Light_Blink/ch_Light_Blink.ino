/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/12/12

Description:
Demo sketch using the Adafruit library "NeoPixel". Using the joystick
you can change the color of the RGB LED.
0-359 degrees changes the hue, while saturation is based on the range
from the center. Lightness is always set to 50%.
By pushing the joystick button you lock that color on the RGB LED.
Push it again to release it and select another color.
**********************************************************************/

#include <Adafruit_NeoPixel.h>
#include <math.h>

#define PIN A4
#define MICROPHONE  A3
#define THRESHOLD 75  // higher value means less sensitivity

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

int R=0, G=0, B=0;

void SetPixel (int Red, int Green, int Blue)
{
  strip.setPixelColor(0, strip.Color(Red, Green, Blue));
  strip.show();
  delay(3);
}

void setup()
{
  Serial.begin (115200);
  randomSeed(analogRead(0));
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  for (int i=0; i<255; i++)
    SetPixel (R, G, B);
}

void loop ()
{
  static int Button = 1, Set_LED = 1;
  int Max=0, Min=1024;
  for(int i=0; i<50; i++) // taking a sequence of samples to determine whether there is noise or not
  {
    int Sample;
    Sample = analogRead(MICROPHONE);
    if (Sample > Max)
      Max = Sample;

    if (Sample < Min)
      Min = Sample;

    if((Max-Min) > THRESHOLD)
    {
      R = random(255);
      G = random(255);
      B = random(255);
      SetPixel (R, G, B);
      delay(100);
      break;
    }
  }
}
