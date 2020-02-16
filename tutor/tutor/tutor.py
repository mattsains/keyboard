#!/usr/bin/env python3

import hid

with hid.Device(9025, 32823) as keyboard:
  while True:
    print(keyboard.read(8))