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
#include <Olimex_Joystick.h>
#include <math.h>

#define PIN A4

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
Olimex_Joystick Joy (A0, A1);

int R=0, G=0, B=0;

void SetPixel (int Red, int Green, int Blue)
{
  strip.setPixelColor(0, strip.Color(Red, Green, Blue));
  strip.show();
  delay(3);
}

// https://www.rapidtables.com/convert/color/hsl-to-rgb.html
void HSL_to_RGB (int H, float S)
{
  // Lightness set const to 50%
  int R, G, B;
  float C, X; 
  C = S;
  X = C * (1 - abs(((float)H / 60.0) / 2 - 1) );

  if ((H>=0) && (H<=60))
  {
    R = C * 255;
    G = X * 255;
  }

  if ((H>=60) && (H<120))
  {
    R = X * 255;
    G = C * 255;
  }

  if ((H>=120) && (H<180))
  {
    G = C * 255;
    B = X * 255;
  }

  if ((H>=180) && (H<240))
  {
    G = X * 255;
    B = C * 255;
  }

  if ((H>=240) && (H<300))
  {
    B = C * 255;
    R = X * 255;
  }

  if ((H>=300) && (H<360))
  {
    B = X * 255;
    R = C * 255;
  }

  SetPixel (R, G, B);
}

//https://www.sessions.edu/color-calculator/
int Joystick_to_Color (int X, int Y)
{
  float Ratio, Deg_Fraction, Saturation;
  int Hue, Quadrant, Degree;
  X = X * 2 - 100;
  if (X == 0)
    X = 1;
  Y = Y * 2 - 100;
  if (Y == 0)
    Y = 1;
  if ((X<0) && (Y>0))
    Quadrant = 1;
  if ((X>0) && (Y>0))
    Quadrant = 2;
  if ((X>0) && (Y<0))
    Quadrant = 3;
  if ((X<0) && (Y<0))
    Quadrant = 4;

  Saturation = sqrt (X*X + Y*Y);
  if (Saturation > 100)
    Saturation = 100;
  Saturation = Saturation / 100.0;
  Ratio = (float)Y/(float)X;
  Deg_Fraction = atan (Ratio) * 180 / 3.14;
  switch (Quadrant)
  {
    case 1:
      Hue = abs (Deg_Fraction);
    break; 
    case 2:
      Hue = 180 - abs (Deg_Fraction);
    break; 
    case 3:
      Hue = 180 + abs (Deg_Fraction);
    break; 
    case 4:
      Hue = 360 - abs (Deg_Fraction);
    break; 
  }
  HSL_to_RGB (Hue, Saturation);
}

void setup()
{
  Serial.begin (115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  for (int i=0; i<255; i++)
    SetPixel (R, G, B);
}

void loop ()
{
  static int Button = 1, Set_LED = 1;
  if (Joy.But () && Button)
  {
    Button = 0;
    delay (100);
    Set_LED = !Set_LED;
    Serial.print ("LED toggled:  ");
    Serial.println (Set_LED);
  }
  if (!Joy.But ())
    Button = 1;
  if (Set_LED)
    Joystick_to_Color (Joy.X(), Joy.Y());
}
