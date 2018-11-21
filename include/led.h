#pragma once
#include "Arduino.h"
#include <CapacitiveSensor.h>
#include "led.h"
#include "defines.h"

// Initiate LEDs
CRGB leds[NUM_LEDS * NUM_OF_KEYS];

class LedRing
{
  public:
    LedRing(int number, int pin){
        _number = (number+1)*NUM_LEDS ;
        _start = (number * NUM_LEDS);
        _state = false;
        _sensor = new CapacitiveSensor(COMMON_PIN, pin);
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
            leds[dot] = CRGB(70, 25, 0);
            FastLED.show();
            }
            _state = true;
        }
    };

    long senseRaw(){
        return _sensor->capacitiveSensor(NUM_OF_SAMPLES);
    };

    bool sense(){
        if(_sensor->capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD){
            return true;
        } else {
            return false;
        }
    }

    protected:
    
    int _start;
    int _number;
    bool _state;
    CapacitiveSensor *_sensor;

};