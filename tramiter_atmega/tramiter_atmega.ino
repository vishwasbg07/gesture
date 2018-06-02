#include <SoftwareSerial.h> 
#include <Keypad.h>
#include<LiquidCrystal.h>
#include<EEPROM.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
SoftwareSerial mySerial(16, 17);
//17 pin connected to esp gpio_02 of esp02
void flexsensor(void);
char password[4];
char pass[4], pass1[4];
int i = 0;
char customKey = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {31, 33, 35, 37}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int F1 = A12;
int F2 = A10;
int F3 = A8;
//const int xpin = A1;
const int ypin = A14;
//const int zpin = A3;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(F1, INPUT);
  pinMode(F2, INPUT);
  pinMode(F3, INPUT);
  //pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
 // pinMode(zpin, INPUT);
  lcd.begin(16, 2);
  lcd.print(" Device is locked ");
  Serial.print(" Device is locked ");
  lcd.setCursor(0, 1);
  lcd.print(" Unlock to use ");
  Serial.print(" Unlock to use");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Ur Passkey:");
  Serial.println("Enter Ur Passkey:");
  lcd.setCursor(0, 1);
  int j = 0;
//  EEPROM.write(0, 50);
//  EEPROM.write(1, 65);
//  EEPROM.write(2, 55);
//  EEPROM.write(3, 67);
  for (int j = 0; j < 4; j++)
    pass[j] = EEPROM.read(j);

  for (int j = 0; j < 4; j++)
  {
    Serial.println(pass[j]);
  }
}

void loop()
{

  customKey = customKeypad.getKey();

  if (customKey)
  {
    password[i++] = customKey;
    lcd.print(customKey);
    Serial.print(customKey);
    delay(200);

  }
  if (i == 4)
  {
    delay(200);
    for (int j = 0; j < 4; j++)
      pass[j] = EEPROM.read(j);
    if (!(strncmp(password, pass, 4)))
    {

      lcd.clear();
      lcd.print("Passkey Accepted");
      Serial.println("Passkey Accepted");
      delay(2000);
      lcd.setCursor(0, 1);
      lcd.clear();
      lcd.print("Passkey Accepted");
      Serial.println("Passkey Accepted");
      sensor();
      i = 0;
    }
    else
    {

      lcd.clear();
      lcd.print("Access Denied...");
      Serial.println("Access Denied...");
      lcd.setCursor(0, 1);
      lcd.print("Try again....");
      Serial.println("Try again....");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Passkey:");
      Serial.println("Enter Passkey:");
      lcd.setCursor(0, 1);
      i = 0;
                                                                                                                                              
    }
  }
}

void sensor()
{ char ch;

  while (1)
  {
    lcd.clear();
    int f1 = analogRead(F1);
    int f2 = analogRead(F2);
    int f3 = analogRead(F3);
    Serial.println(f1);
    Serial.println(f2);
    Serial.println(f3);
    int y1 = analogRead(ypin);
    Serial.println(y1);
    if (260 < y1 && y1 < 320)
    {
        Serial.print("upword\n");
      if ((90 <= f1 && f1 <= 105) && (115 <= f2 && f2 <= 130) && (115 <= f3 && f3 <= 130))
      {
        
        Serial.print("attack\n");
        lcd.print("attack");
        mySerial.write("a");
        
      }
      else if ((105 <= f1 && f1 <= 120) && (130 <= f2 && f2 <= 145) && (115 <= f3 && f3 <= 130))
      {
        Serial.print("follow me\n");
        lcd.print("follow me");
        mySerial.write("b");
        
      }

      else if ((105 <= f1 && f1 <= 120) && (130 <= f2 && f2 <= 145) && (105 <= f3 && f3 <= 115))
      {
        
        Serial.print("success\n");
        lcd.print("success");
        mySerial.write("c");
        
      }

      else if ((90 <= f1 && f1 <= 105) && (115 <= f2 && f2 <= 130) && (105 <= f3 && f3 <= 115))
      {
        
        Serial.print("stop\n");
        lcd.print("stop");
        mySerial.write("d");
        
      }

      else
      {
        
        Serial.print("reading");
        lcd.print("reading up");
        mySerial.write("j");
        
      }
    }
    else if (320 < y1 && y1 < 390)
    {
      Serial.print("flat\n");

      if ((90 <= f1 && f1 <= 105) && (115 <= f2 && f2 <= 130) && (105 <= f3 && f3 <= 115))
      {

        Serial.print("alert\n");
        lcd.print("alert");
        mySerial.write("e");


      }

      else if ((90 <= f1 && f1 <= 105) && (130 <= f2 && f2 <= 145) && (115 <= f3 && f3 <= 130))
      {

        Serial.print("shoot target\n");
        lcd.print("shoot target");
        mySerial.write("f");

      }

      else if ((105 <= f1 && f1 <= 120) && (130 <= f2 && f2 <= 145) && (115 <= f3 && f3 <= 130))
      {

        Serial.print("at risk\n");
        lcd.print("at risk");
        mySerial.write("g");


      }
      else
      {

        Serial.print("reading");
        lcd.print("reading flat");
        mySerial.write("j");

      }
    }
    else if (390 < y1 && y1 < 420)
    {
      Serial.print("down\n");

      if ((90 <= f1 && f1 <= 105) && (115 <= f2 && f2 <= 130) && (105 <= f3 && f3 <= 115))
      {

        Serial.print("knee down\n");
        lcd.print("knee down");
        mySerial.write("h");

      }


      else if ((105 <= f1 && f1 <= 120) && (130 <= f2 && f2 <= 145) && (115 <= f3 && f3 <= 130))
      {

        Serial.print("cover up\n");
        lcd.print("cover up");
        mySerial.write("i");

      }
      else
      {

        Serial.print("reading");
        lcd.print("reading down");
        mySerial.write("j");

      }
    }
    else
    {
      Serial.print("reading");
      lcd.print("reading");
      mySerial.write("j");

    }

    delay(3000);
  }
}

