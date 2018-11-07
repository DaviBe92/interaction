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
#define NUM_LEDS 13

// Data pin that led data will be written out over
#define DATA_PIN 7

boolean State = false;
int THRESHOLD = 300;




// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

CapacitiveSensor   cs_1 = CapacitiveSensor(6,2);       
CapacitiveSensor   cs_2 = CapacitiveSensor(6,3);        
CapacitiveSensor   cs_3 = CapacitiveSensor(6,4);  
CapacitiveSensor   cs_4 = CapacitiveSensor(6,5);        



// This function sets up the ledsand tells the controller about them
void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
       cs_1.set_CS_AutocaL_Millis(0xFFFFFFFF);
       cs_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
       cs_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
       cs_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
        Serial.begin(9600);
}

void loop() {
  long touch =  cs_1.capacitiveSensor(30);
  boolean pressed = false;
  
  long touch2 =  cs_2.capacitiveSensor(30);
  long touch3 =  cs_3.capacitiveSensor(30);
  long touch4 =  cs_4.capacitiveSensor(30);
  
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
Serial.print("Sensor1: ");
Serial.print(touch);                  // print sensor output 1
Serial.print("\t");
Serial.print("Sensor2: ");
Serial.print(touch2);
Serial.print("\t");
Serial.print("Sensor3: ");
Serial.print(touch3);
Serial.print("\t");
Serial.print("Sensor4: ");
Serial.print(touch4);
Serial.println();

delay(50);
}