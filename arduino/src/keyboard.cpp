#include "keyboard.h"

#include "../lib/generated.cpp"

boolean lastKeyState[10] = { false };
boolean keyState[10] = { false };

int keystroke = 0;

boolean constructing = true;

int sendKeyUpdates = 10;

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

  if (keystroke > 0 && keystroke < KEYMAP_LENGTH) {
    strcpy_P(buffer, (char *)pgm_read_word(&(keymap[keystroke-1])));
    Keyboard.print(buffer);
  } else if (keystroke == 1<<SPACE_POS) {
    Keyboard.print(" ");
  } else if (keystroke > 1<<UPPERCASE_POS && keystroke < (KEYMAP_LENGTH + (1<<UPPERCASE_POS))) {
    strcpy_P(buffer, (char *)pgm_read_word(&(keymap[(keystroke - (1<<8) )-1])));
    if (buffer[0] >= 'a' && buffer[0] <= 'z') {
      buffer[0] += 'A' -'a';
    } else {
      for (byte i = 0; i < PUNC_COUNT; i++) {
        if (buffer[0] == (char) pgm_read_byte_near(puncKeys + i)) {
          buffer[0] = (char) pgm_read_byte_near(puncUpper + i);
          break;
        }
      }
    }
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

  // periodically, let the computer know what keys are being held down, for the tutor.
  if (sendKeyUpdates-- == 0) {
    sendKeyUpdates = 10;

    Keyboard.writeRaw(232);
    for (byte i=0; i<10; i++) {
      if (keyState[i])
        Keyboard.writeRaw(233 + i);
    }
    Keyboard.writeRaw(243);
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

  keyState[8] = digitalRead(4) == LOW;
  keyState[9] = (c&1<<4) == 0;
}
