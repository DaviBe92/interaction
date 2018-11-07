#include <FastLED.h>
#include <CapacitiveSensor.h>
#include "capSense.h";
#include "led.h";

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

// How many leds are in the strip?
#define NUM_LEDS 16

// Data pin that led data will be written out over
#define DATA_PIN 6

boolean State = false;
int THRESHOLD = 100;




// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_3 = CapacitiveSensor(4,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired


// This function sets up the ledsand tells the controller about them
void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
       cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
       cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
        Serial.begin(9600);
}

void loop() {
  long touch =  cs_4_2.capacitiveSensor(30);
  boolean pressed = false;
  
  long touch2 =  cs_4_3.capacitiveSensor(30);
  
  if(touch > THRESHOLD && !pressed){
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
     leds[whiteLed] = CRGB::Black;
      // Show the leds (only one of which is set to white, from above)
      FastLED.show();
   }
    State = !State;
    delay(200);
    pressed = true;
  } else if (touch2 > THRESHOLD) {
     State = false;
  }
  
  
  
else if(!State){
      for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB( 0,  0, 25);
      // Show the leds (only one of which is set to white, from above)
      FastLED.show();
   }
}
Serial.print(touch);                  // print sensor output 1
Serial.print("\t");
Serial.println(touch2);                  // print sensor output 1
delay(10);
}