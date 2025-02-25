# eduArdu
Open Source Hardware Educational board based on Arduino Leonardo

Product page: https://www.olimex.com/Products/Duino/AVR/eduArdu/open-source-hardware

Introduction video: https://youtu.be/3kFrveMF56s

# Getting started

## Arduino IDE

* [Download and install Arduino IDE](https://www.arduino.cc/en/Main/Software)
* Open Arduino IDE
* Click **Sketch > Include Library > Add .ZIP library...** and add all libraries provided with this repository
* If you get "arduino Error: 13 INTERNAL: Library install failed: archive is not valid: multiple files found in zip file top level" (usually when you use newer version of Arduino IDE) extract the .zip files into respective folders: `Olimex_Buzzer.zip` into `Olimex_Buzzer` in the same `libraries` folder. Then open Arduino IDE and click `File->Preferences` and change Sketchbook location to the `SOFTWARE` folder of the repo location.
* Open a sketch, compile and upload it to Olimex eduArdu

## Licensee
* Hardware is released under Apache 2.0 Licensee
* Software is released under GPL3 Licensee
* Documentation is released under CC BY-SA 3.0
