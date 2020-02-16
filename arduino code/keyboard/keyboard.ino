#include "betterkeyboard.h"

#include <Wire.h>
#include <avr/pgmspace.h>

const char string_0[] PROGMEM = "a";
const char string_1[] PROGMEM = "s";
const char string_2[] PROGMEM = "w";
const char string_3[] PROGMEM = "e";
const char string_4[] PROGMEM = "x";
const char string_5[] PROGMEM = "d";
const char string_6[] PROGMEM = "we";
const char string_7[] PROGMEM = "t";
const char string_8[] PROGMEM = "f";
const char string_9[] PROGMEM = "c";
const char string_10[] PROGMEM = "fact";
const char string_11[] PROGMEM = "r";
const char string_12[] PROGMEM = "are";
const char string_13[] PROGMEM = "set";
const char string_14[] PROGMEM = "were";
const char string_15[] PROGMEM = "n";
const char string_16[] PROGMEM = "q";
const char string_17[] PROGMEM = "j";
const char string_18[] PROGMEM = "san";
const char string_19[] PROGMEM = "y";
const char string_20[] PROGMEM = "any";
const char string_21[] PROGMEM = "eyes";
const char string_22[] PROGMEM = "and";
const char string_23[] PROGMEM = "b";
const char string_24[] PROGMEM = "fan";
const char string_25[] PROGMEM = "";
const char string_26[] PROGMEM = "can";
const char string_27[] PROGMEM = "be";
const char string_28[] PROGMEM = "ran";
const char string_29[] PROGMEM = "best";
const char string_30[] PROGMEM = "went";
const char string_31[] PROGMEM = "i";
const char string_32[] PROGMEM = "z";
const char string_33[] PROGMEM = "k";
const char string_34[] PROGMEM = "ask";
const char string_35[] PROGMEM = ",";
const char string_36[] PROGMEM = "";
const char string_37[] PROGMEM = "did";
const char string_38[] PROGMEM = "said";
const char string_39[] PROGMEM = "v";
const char string_40[] PROGMEM = "if";
const char string_41[] PROGMEM = "its";
const char string_42[] PROGMEM = "wait";
const char string_43[] PROGMEM = "ever";
const char string_44[] PROGMEM = "five";
const char string_45[] PROGMEM = "tried";
const char string_46[] PROGMEM = "first";
const char string_47[] PROGMEM = "h";
const char string_48[] PROGMEM = "ah";
const char string_49[] PROGMEM = "his";
const char string_50[] PROGMEM = "has";
const char string_51[] PROGMEM = "he";
const char string_52[] PROGMEM = "yeah";
const char string_53[] PROGMEM = "she";
const char string_54[] PROGMEM = "when";
const char string_55[] PROGMEM = "bit";
const char string_56[] PROGMEM = "that";
const char string_57[] PROGMEM = "this";
const char string_58[] PROGMEM = "with";
const char string_59[] PROGMEM = "the";
const char string_60[] PROGMEM = "have";
const char string_61[] PROGMEM = "these";
const char string_62[] PROGMEM = "where";
const char string_63[] PROGMEM = "o";
const char string_64[] PROGMEM = "(";
const char string_65[] PROGMEM = ".";
const char string_66[] PROGMEM = "";
const char string_67[] PROGMEM = "-";
const char string_68[] PROGMEM = "";
const char string_69[] PROGMEM = "do";
const char string_70[] PROGMEM = "wood";
const char string_71[] PROGMEM = "g";
const char string_72[] PROGMEM = "of";
const char string_73[] PROGMEM = "cost";
const char string_74[] PROGMEM = "two";
const char string_75[] PROGMEM = "get";
const char string_76[] PROGMEM = "for";
const char string_77[] PROGMEM = "good";
const char string_78[] PROGMEM = "words";
const char string_79[] PROGMEM = "u";
const char string_80[] PROGMEM = "";
const char string_81[] PROGMEM = "soon";
const char string_82[] PROGMEM = "now";
const char string_83[] PROGMEM = "you";
const char string_84[] PROGMEM = "anyone";
const char string_85[] PROGMEM = "done";
const char string_86[] PROGMEM = "down";
const char string_87[] PROGMEM = "but";
const char string_88[] PROGMEM = "about";
const char string_89[] PROGMEM = "just";
const char string_90[] PROGMEM = "town";
const char string_91[] PROGMEM = "your";
const char string_92[] PROGMEM = "before";
const char string_93[] PROGMEM = "course";
const char string_94[] PROGMEM = "because";
const char string_95[] PROGMEM = "l";
const char string_96[] PROGMEM = "all";
const char string_97[] PROGMEM = "lock";
const char string_98[] PROGMEM = "will";
const char string_99[] PROGMEM = "lie";
const char string_100[] PROGMEM = "";
const char string_101[] PROGMEM = "like";
const char string_102[] PROGMEM = "well";
const char string_103[] PROGMEM = "till";
const char string_104[] PROGMEM = "fall";
const char string_105[] PROGMEM = "still";
const char string_106[] PROGMEM = "call";
const char string_107[] PROGMEM = "tell";
const char string_108[] PROGMEM = "felt";
const char string_109[] PROGMEM = "told";
const char string_110[] PROGMEM = "work";
const char string_111[] PROGMEM = "oh";
const char string_112[] PROGMEM = "hell";
const char string_113[] PROGMEM = "soul";
const char string_114[] PROGMEM = "who";
const char string_115[] PROGMEM = "only";
const char string_116[] PROGMEM = "alone";
const char string_117[] PROGMEM = "should";
const char string_118[] PROGMEM = "would";
const char string_119[] PROGMEM = "thought";
const char string_120[] PROGMEM = "again";
const char string_121[] PROGMEM = "such";
const char string_122[] PROGMEM = "without";
const char string_123[] PROGMEM = "through";
const char string_124[] PROGMEM = "another";
const char string_125[] PROGMEM = "could";
const char string_126[] PROGMEM = "already";
const char string_127[] PROGMEM = "p";
const char string_128[] PROGMEM = "?";
const char string_129[] PROGMEM = ")";
const char string_130[] PROGMEM = "pass";
const char string_131[] PROGMEM = "";
const char string_132[] PROGMEM = "";
const char string_133[] PROGMEM = "deep";
const char string_134[] PROGMEM = "we'd";
const char string_135[] PROGMEM = "\b";
const char string_136[] PROGMEM = "pat";
const char string_137[] PROGMEM = "";
const char string_138[] PROGMEM = "past";
const char string_139[] PROGMEM = "per";
const char string_140[] PROGMEM = "part";
const char string_141[] PROGMEM = "step";
const char string_142[] PROGMEM = "we're";
const char string_143[] PROGMEM = "m";
const char string_144[] PROGMEM = "am";
const char string_145[] PROGMEM = "ms";
const char string_146[] PROGMEM = "mass";
const char string_147[] PROGMEM = "my";
const char string_148[] PROGMEM = "many";
const char string_149[] PROGMEM = "seemed";
const char string_150[] PROGMEM = "same";
const char string_151[] PROGMEM = "";
const char string_152[] PROGMEM = "";
const char string_153[] PROGMEM = "";
const char string_154[] PROGMEM = "camp";
const char string_155[] PROGMEM = "remember";
const char string_156[] PROGMEM = "army";
const char string_157[] PROGMEM = "spent";
const char string_158[] PROGMEM = "came";
const char string_159[] PROGMEM = "!";
const char string_160[] PROGMEM = "";
const char string_161[] PROGMEM = "";
const char string_162[] PROGMEM = "";
const char string_163[] PROGMEM = "i";
const char string_164[] PROGMEM = "";
const char string_165[] PROGMEM = "keep";
const char string_166[] PROGMEM = "speak";
const char string_167[] PROGMEM = "tip";
const char string_168[] PROGMEM = "";
const char string_169[] PROGMEM = "pick";
const char string_170[] PROGMEM = "pack";
const char string_171[] PROGMEM = "trip";
const char string_172[] PROGMEM = "private";
const char string_173[] PROGMEM = "it's";
const char string_174[] PROGMEM = "we've";
const char string_175[] PROGMEM = "him";
const char string_176[] PROGMEM = "pain";
const char string_177[] PROGMEM = "ship";
const char string_178[] PROGMEM = "spanish";
const char string_179[] PROGMEM = "I'm";
const char string_180[] PROGMEM = "happy";
const char string_181[] PROGMEM = "she'd";
const char string_182[] PROGMEM = "make";
const char string_183[] PROGMEM = "";
const char string_184[] PROGMEM = "path";
const char string_185[] PROGMEM = "smith";
const char string_186[] PROGMEM = "captain";
const char string_187[] PROGMEM = "them";
const char string_188[] PROGMEM = "remain";
const char string_189[] PROGMEM = "didn't";
const char string_190[] PROGMEM = "that's";
const char string_191[] PROGMEM = ";";
const char string_192[] PROGMEM = "";
const char string_193[] PROGMEM = "";
const char string_194[] PROGMEM = "";
const char string_195[] PROGMEM = "pope";
const char string_196[] PROGMEM = "";
const char string_197[] PROGMEM = "possessed";
const char string_198[] PROGMEM = "top";
const char string_199[] PROGMEM = "gap";
const char string_200[] PROGMEM = "stop";
const char string_201[] PROGMEM = "";
const char string_202[] PROGMEM = "report";
const char string_203[] PROGMEM = "page";
const char string_204[] PROGMEM = "stopped";
const char string_205[] PROGMEM = "power";
const char string_206[] PROGMEM = "up";
const char string_207[] PROGMEM = "";
const char string_208[] PROGMEM = "sum";
const char string_209[] PROGMEM = "woman";
const char string_210[] PROGMEM = "monkey";
const char string_211[] PROGMEM = "";
const char string_212[] PROGMEM = "women";
const char string_213[] PROGMEM = "put";
const char string_214[] PROGMEM = "among";
const char string_215[] PROGMEM = "most";
const char string_216[] PROGMEM = "famous";
const char string_217[] PROGMEM = "more";
const char string_218[] PROGMEM = "from";
const char string_219[] PROGMEM = "don't";
const char string_220[] PROGMEM = "company";
const char string_221[] PROGMEM = "pool";
const char string_222[] PROGMEM = "lap";
const char string_223[] PROGMEM = "slip";
const char string_224[] PROGMEM = "";
const char string_225[] PROGMEM = "people";
const char string_226[] PROGMEM = "apple";
const char string_227[] PROGMEM = "spoke";
const char string_228[] PROGMEM = "we'll";
const char string_229[] PROGMEM = "pilot";
const char string_230[] PROGMEM = "";
const char string_231[] PROGMEM = "split";
const char string_232[] PROGMEM = "capital";
const char string_233[] PROGMEM = "prove";
const char string_234[] PROGMEM = "april";
const char string_235[] PROGMEM = "replied";
const char string_236[] PROGMEM = "place";
const char string_237[] PROGMEM = "million";
const char string_238[] PROGMEM = "human";
const char string_239[] PROGMEM = "\n";
const char string_240[] PROGMEM = "small";
const char string_241[] PROGMEM = "home";
const char string_242[] PROGMEM = "example";
const char string_243[] PROGMEM = "simply";
const char string_244[] PROGMEM = "explained";
const char string_245[] PROGMEM = "might";
const char string_246[] PROGMEM = "film";
const char string_247[] PROGMEM = "much";
const char string_248[] PROGMEM = "almost";
const char string_249[] PROGMEM = "government";
const char string_250[] PROGMEM = "family";
const char string_251[] PROGMEM = "something";
const char string_252[] PROGMEM = "especially";
const char * const keymap[] PROGMEM = { string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11, string_12, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20, string_21, string_22, string_23, string_24, string_25, string_26, string_27, string_28, string_29, string_30, string_31, string_32, string_33, string_34, string_35, string_36, string_37, string_38, string_39, string_40, string_41, string_42, string_43, string_44, string_45, string_46, string_47, string_48, string_49, string_50, string_51, string_52, string_53, string_54, string_55, string_56, string_57, string_58, string_59, string_60, string_61, string_62, string_63, string_64, string_65, string_66, string_67, string_68, string_69, string_70, string_71, string_72, string_73, string_74, string_75, string_76, string_77, string_78, string_79, string_80, string_81, string_82, string_83, string_84, string_85, string_86, string_87, string_88, string_89, string_90, string_91, string_92, string_93, string_94, string_95, string_96, string_97, string_98, string_99, string_100, string_101, string_102, string_103, string_104, string_105, string_106, string_107, string_108, string_109, string_110, string_111, string_112, string_113, string_114, string_115, string_116, string_117, string_118, string_119, string_120, string_121, string_122, string_123, string_124, string_125, string_126, string_127, string_128, string_129, string_130, string_131, string_132, string_133, string_134, string_135, string_136, string_137, string_138, string_139, string_140, string_141, string_142, string_143, string_144, string_145, string_146, string_147, string_148, string_149, string_150, string_151, string_152, string_153, string_154, string_155, string_156, string_157, string_158, string_159, string_160, string_161, string_162, string_163, string_164, string_165, string_166, string_167, string_168, string_169, string_170, string_171, string_172, string_173, string_174, string_175, string_176, string_177, string_178, string_179, string_180, string_181, string_182, string_183, string_184, string_185, string_186, string_187, string_188, string_189, string_190, string_191, string_192, string_193, string_194, string_195, string_196, string_197, string_198, string_199, string_200, string_201, string_202, string_203, string_204, string_205, string_206, string_207, string_208, string_209, string_210, string_211, string_212, string_213, string_214, string_215, string_216, string_217, string_218, string_219, string_220, string_221, string_222, string_223, string_224, string_225, string_226, string_227, string_228, string_229, string_230, string_231, string_232, string_233, string_234, string_235, string_236, string_237, string_238, string_239, string_240, string_241, string_242, string_243, string_244, string_245, string_246, string_247, string_248, string_249, string_250, string_251, string_252};

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
