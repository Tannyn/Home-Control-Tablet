#include <AdafruitIO.h>
#include <AdafruitIO_Dashboard.h>
#include <AdafruitIO_Data.h>
#include <AdafruitIO_Definitions.h>

#include <AdafruitIO_Feed.h>
#include <AdafruitIO_Group.h>
#include <AdafruitIO_MQTT.h>
#include <AdafruitIO_WiFi.h>

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Key.h>
#include <Keypad.h>
#include "config.h"

const byte ROWS = 4;
const byte COLS = 7;

//Define the keymap below
char keys[ROWS][COLS] = {
  {'A','B','C','D','E','F','G'},
  {'H','I','J','K','L','M','N'},
  {'O','P','Q','R','S','T','U'},
  {'#','V','W','X','Y','Z','*'}
};

//Connect (4) ROW pins here
byte rowPins[ROWS] = {4,5,2,16};
//Connect (7) COL pins here
byte colPins[COLS] = {0,15,13,12,14,1,3};

// @section keypad
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/*for(int x = 0; x<ROWS; x++){
  pinMode(rowPins[x], INPUT);
}
for(int x = 0; x<COLS; x++){
  pinMode(colPins[x], INPUT);
} */

/* This is for if I decide to keep the RGB led functionality.. Uncomment section in setup too!

int rgbLed[3] = {0, 0, 0};

*/

//setup 'digital' feed
AdafruitIO_Feed *digital = io.feed("digital");

void setup() {
  
  // put your setup code here, to run once:
  /* for(int i=0;x<3;x++){
    pinMode(rgbLed[i], OUTPUT);
    digitalWrite(rgbLed[i], LOW);} */

  //Start serial connection and wait for it to initialize
  Serial.begin(115200);
  while(! Serial);
  
  //connect to io.adafruit.com
  Serial.print("Connecting to Adafruit");
  io.connect();
  

}

void loop() {
  io.run();
  
  // put your main code here, to run repeatedly:
  char key = kpd.getKey();
  if(key) //check for a valid key
  {
    switch(key)
    {
      case 'A':
        break;
      case 'B':
        break;
      default:
        Serial.println("Misread key");
        //break;
    }
    //digital->save(key);
  }

}


