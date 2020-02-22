#include "../lib/betterkeyboard/betterkeyboard.h"

#include <Wire.h>
#include <avr/pgmspace.h>

#define UPPERCASE_POS 8
#define SPACE_POS 9

void getKeystroke();
void getKeyState();