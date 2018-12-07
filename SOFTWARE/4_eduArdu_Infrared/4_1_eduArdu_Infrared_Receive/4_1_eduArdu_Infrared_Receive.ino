#include <IRremote.h>

IRrecv irrecv(7);

void  setup ( )
{
  Serial.begin(115200);   // Status message will be sent to PC at 9600 baud
  irrecv.enableIRIn();  // Start the receiver
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
  Serial.print(results->value, HEX);
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

void  dumpInfo (decode_results *results)
{
  // Check if the buffer overflowed
  if (results->overflow)
  {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWBUF");
    return;
  }

  if ((results->decode_type == UNKNOWN) || (results->value == 0xFFFFFFFF))  // filter to skip the invalid data
    return;
  
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
}

void  loop ()
{
  static decode_results  results;        // Somewhere to store the results

  if (irrecv.decode(&results))
  {
    dumpInfo(&results);           // Output the results
    irrecv.resume();              // Prepare for the next value
  }
}
