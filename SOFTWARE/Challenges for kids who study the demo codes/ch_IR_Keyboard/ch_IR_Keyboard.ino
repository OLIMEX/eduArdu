/**********************************************************************
Demo example for Olimex board eduArdu
Tested with Arduino 1.8.8
Date: 2018/03/16

Description:
This demo is based on IRrecvDumpV2 sketch of the "IRremote" library.
On the terminal you can monitor the input data from IR transmitters.
The LED changes depending on the IR signal received.
More signal values can be added as seen in the example.
You will see the infrared protocol and the code.
**********************************************************************/

#include <IRremote.h>  // go to Sketch --> Include Library --> Manage Libraries --> IRremote (tested with 2.2.3v)
#include <Adafruit_NeoPixel.h>
#include "Keyboard.h"

#define PIN A4
#define KEY_3   '3'
#define KEY_4   '4'
#define KEY_7   '7'
#define KEY_8   '8'

IRrecv irrecv(7);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void SetPixel (int Red, int Green, int Blue)
{
  strip.setPixelColor(0, strip.Color(Red, Green, Blue));
  strip.show();
  delay(3);
}

void  setup ( )
{
  Serial.begin(115200);   // Status message will be sent to PC at 9600 baud
  irrecv.enableIRIn();  // Start the receiver
  Keyboard.begin();
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  SetPixel(0,0,0);
}

void  ircode (decode_results *results)
{
  // Panasonic has an Address
  if (results->decode_type == PANASONIC)
  {
    Serial.print(results->address, HEX);
    Serial.print(":");
  }

  // Print Code
  Serial.print(results->value);
}

void  encoding (decode_results *results)
{
  switch (results->decode_type)
  {
    default:
    case UNKNOWN:      Serial.print("UNKNOWN");       break ;
    case NEC:          Serial.print("NEC");           break ;
    case SONY:         Serial.print("SONY");          break ;
    case RC5:          Serial.print("RC5");           break ;
    case RC6:          Serial.print("RC6");           break ;
    case DISH:         Serial.print("DISH");          break ;
    case SHARP:        Serial.print("SHARP");         break ;
    case JVC:          Serial.print("JVC");           break ;
    case SANYO:        Serial.print("SANYO");         break ;
    case MITSUBISHI:   Serial.print("MITSUBISHI");    break ;
    case SAMSUNG:      Serial.print("SAMSUNG");       break ;
    case LG:           Serial.print("LG");            break ;
    case WHYNTER:      Serial.print("WHYNTER");       break ;
    case AIWA_RC_T501: Serial.print("AIWA_RC_T501");  break ;
    case PANASONIC:    Serial.print("PANASONIC");     break ;
    case DENON:        Serial.print("Denon");         break ;
  }
}

void  dumpInfoAndChangeLED (decode_results *results)
{
  // Check if the buffer overflowed
  if (results->overflow)
  {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWBUF");
    return;
  }

  //if ((results->decode_type == UNKNOWN) || (results->value == 0xFFFFFFFF))  // filter to skip the invalid data
    //return;
  
  // Show Encoding standard
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");

  // Show Code & length
  Serial.print("Code      : ");
  ircode(results);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.println();           // Blank line between entries

  switch(results->value)//Change LED colour based upon values
  {
    case 0xE0E020DF: SetPixel(0,255,0);break;//Remote signal "1"
    case 0xE0E0A05F: SetPixel(255,0,0);break;//Remote signal "2"
  }
  
  
}

void  loop ()
{
  static decode_results  results;        // Somewhere to store the results

  if (irrecv.decode(&results))
  {
    dumpInfoAndChangeLED(&results);           // Output the results and change LED colour
    TypeOnKeyboard(results.value);

    delay(100);
    irrecv.resume();              // Prepare for the next value
  }
}

void TypeOnKeyboard(int val)
{
  if (val == 67 || val == 2115) 
  {
       Keyboard.press(KEY_3);
       Keyboard.release(KEY_3);
  }
  if (val == 68 || val == 2116) 
  {
       Keyboard.press(KEY_4);
       Keyboard.release(KEY_4);
  }
  if (val == 71 || val == 2119) 
  {
       Keyboard.press(KEY_7);
       Keyboard.release(KEY_7);
  }
  if (val == 72 || val == 2120) 
  {
       Keyboard.press(KEY_8);
       Keyboard.release(KEY_8);
  }
}
