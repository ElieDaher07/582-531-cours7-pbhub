#include <Arduino.h>

#include <FastLED.h>

#define BROCHE_BOUTON_KEY 32
#define BROCHE_BOUTON_KEY_LUMIERE 26

#define BROCHE_BOUTON_ATOM 39
#define BROCHE_BOUTON_ATOM_LUMIERE 27

CRGB pixelKey;
CRGB pixelAtom;

void setup() {
  FastLED.addLeds< WS2812, BROCHE_BOUTON_KEY_LUMIERE , GRB >(&pixelKey, 1); 
  FastLED.addLeds< WS2812,  BROCHE_BOUTON_ATOM_LUMIERE , GRB >(&pixelAtom, 1); 
  pinMode( BROCHE_BOUTON_KEY , INPUT );
  pinMode( BROCHE_BOUTON_ATOM , INPUT );
}

void loop() { 
  int maLectureKey = digitalRead( BROCHE_BOUTON_KEY );
  int maLectureAtom = digitalRead( BROCHE_BOUTON_ATOM);


  if (maLectureAtom == 0) {
    pixelAtom = CRGB(0,0,127);
  } else {
    pixelAtom = CRGB (0, 0, 0);
  }
  

  if (maLectureKey == 0 ) {
    pixelKey = CRGB(127,255,0);
  } else {
    pixelKey = CRGB(0,0,0);
  }

  delay(20);


  FastLED.show();
}