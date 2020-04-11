#include<Keyboard.h>

// Analog input of the horizontal joystick position
const int JoystickX = A0;
// Analog input of the vertical joystick position
const int JoystickY = A1;

void setup()
{

}

void loop()
{
  // Process horizontal joystick position
  int x = analogRead(JoystickX);
  if (1023 == x)
  {
    Keyboard.press(KEY_RIGHT_ARROW);
  }
  else if (0 == x)
  {
    Keyboard.press(KEY_LEFT_ARROW);
  }
  else
  {
    Keyboard.release(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(10);
  }

  // Process vertical joystick position
  int y = analogRead(JoystickY);
  if (1023 == y)
  {
    Keyboard.press(KEY_UP_ARROW);
  }
  else if (0 == y)
  {
    Keyboard.press(KEY_DOWN_ARROW);
  }
  else
  {
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(10);
  }
}
