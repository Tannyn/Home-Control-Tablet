#include <Keypad.h>

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
byte rowPins[ROWS] = {/* Fill this in when hardware mod is planned */};
//Connect (7) COL pins here
byte colPins[COLS] = {/* Fill this in when hardware mod is planned */};

// @section keypad
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/* This is for if I decide to keep the RGB led functionality.. Uncomment section in setup too!

int rgbLed[3] = {0, 0, 0};

*/

void setup() {
  // put your setup code here, to run once:
  /* for(int i=0;x<3;x++){
    pinMode(rgbLed[i], OUTPUT);
    digitalWrite(rgbLed[i], LOW);} */
    Serial.begin(9600);

}

void loop() {
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
    }
  }

}
