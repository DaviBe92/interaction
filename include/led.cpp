#include "led.h"
#include <Arduino.h>
#include <FastLED.h>
#include "defines.h"

// Initiate LEDs
CRGB leds[NUM_LEDS + NUM_OF_KEYS];




void LedRing::off() {
    
}


void LedRing::on1() {
        for(int dot = _number ; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Blue;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(30);
        }
}

void LedRing::on2() {

}
