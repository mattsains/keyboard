#include "keyboard.h"

#include "../lib/generated.cpp"

boolean lastKeyState[10] = { false };
boolean keyState[10] = { false };

int keystroke = 0;

boolean constructing = true;

void setup() {
  for (byte i=4; i<9; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  Wire.begin(); // connect to left hand

  Keyboard.begin();

  delay(500);
  Keyboard.writeRaw(232);
}

void loop() {
  getKeystroke();

  char buffer[10];

  if (keystroke > 0 && keystroke < 253) {
    strcpy_P(buffer, (char *)pgm_read_word(&(keymap[keystroke-1])));
    Keyboard.print(buffer);
  } else if (keystroke == 1<<9) {
    Keyboard.print(" ");
  } else if (keystroke > 1<<8 && keystroke < (253 + (1<<8))) {
    strcpy_P(buffer, (char *)pgm_read_word(&(keymap[(keystroke - (1<<8) )-1])));
    if (buffer[0] >= 'a' && buffer[0] <= 'z') buffer[0] += 'A' -'a';
    Keyboard.print(buffer);
  }

  delay(10);
}

void getKeystroke() {
  getKeyState();

  keystroke = 0;

  boolean keyWasReleased = false;
  for(byte i=0; i<10; i++) {

    if (lastKeyState[i] && !keyState[i]) {
      keyWasReleased = true;
      break;
    }
  }

  boolean keyWasPressed = false;
  for(byte i=0; i<10; i++) {

    if (keyState[i] && !lastKeyState[i]) {
      keyWasPressed = true;
      break;
    }
  }

  if (keyWasReleased && constructing) {
    byte index = 0;
    for (byte i=0; i<10; i++) {
      if (lastKeyState[i]) {
        keystroke |= 1<<i;
      }
    }
  } else {
    keystroke = 0;
  }

  for(byte i=0; i<10; i++) {
    lastKeyState[i] = keyState[i];
  }

  if (keyWasReleased) constructing = false;
  if (keyWasPressed) constructing = true;
}

// returns an array of key states
void getKeyState() {
  Wire.requestFrom(0x21, 1);
  byte c = Wire.read();
  Wire.endTransmission();

  for (byte i=0; i<4; i++) {
    keyState[i] = (c&1<<i) == 0;
  }

  for (byte i=5; i<9; i++) {
    keyState[i-1] = digitalRead(i) == LOW;
  }

  keyState[8] = (c&1<<4) == 0;
  keyState[9] = digitalRead(4) == LOW;
}
