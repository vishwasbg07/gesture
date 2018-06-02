#include <DFRobotDFPlayerMini.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini Player;
int i = 0;
char ch;
void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Voice command mp3 player"));
  Serial.println(F("Initializing mp3 player ... (May take 3~5 seconds)"));

  if (!Player.begin(mySoftwareSerial))
  {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  
  Serial.println(F("Player Mini Available"));
  Player.volume(25);
  delay(1000);
}

void loop()
{

  while (Serial.available())
  {

    ch = Serial.read();
    Serial.println(ch);

    switch (ch)
    {
      case 'a':
        Player.play(2);
        break;

      case 'b':
        Player.play(3);
        break;

        break;

      case 'e':
        Player.pause();
        break;
        
      case 'j':
        Player.pause();
        break;
    }
    delay(3000);
  }

}


