#pragma once
#include "Arduino.h"
#include "led.h"
#include "defines.h"

// LED Ring class erstellen
// Funktionen: Off, On1, On2
// Initiate LEDs
CRGB leds[NUM_LEDS * NUM_OF_KEYS];

class LedRing
{
  public:
    LedRing(int number){
        _number = (number+1)*NUM_LEDS ;
        _start = (number * NUM_LEDS);
        _state = false;
    }

    void off(){
        if(_state){
            for(int dot = _start ; dot < _number; dot++) { 
            leds[dot] = CRGB::Black;
            FastLED.show();
        }
        _state = false;
        }
    };
    void on1(){
        if(!_state){
            for(int dot = _start ; dot <  _number; dot++) { 
            leds[dot] = CRGB( 0,  0, 25);
            FastLED.show();
        }
        _state = true;
        }
    };
    void on2(){
        if(!_state){
            for(int dot = _start ; dot <  _number; dot++) { 
            leds[dot] = CRGB( 25,  25, 0);
            FastLED.show();
            }
            _state = true;
        }
    };


    int _start;
    int _number;
    bool _state;

};