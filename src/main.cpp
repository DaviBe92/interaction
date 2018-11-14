#include <FastLED.h>
#include <CapacitiveSensor.h>
#include "defines.h"
//#include "capSense.h"
#include "led.h"

///////////////////////////////////////////////////////////////////////////////////////////



#define CS(Y) CapacitiveSensor(COMMON_PIN, Y)

// Initiate Sensors - Receive pin in brackets
CapacitiveSensor sensor[] = {CS(2), CS(3), CS(4), CS(5)};


LedRing LED[] = {LedRing(0),LedRing(1),LedRing(2),LedRing(3)};


// This function sets up the ledsand tells the controller about them
void setup() {
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS*NUM_OF_KEYS);
      Serial.begin(9600);
      Serial.println("SETUP"); 
}

void loop() {

      for (int i = 0; i < NUM_OF_KEYS; ++i){
            long sense = sensor[i].capacitiveSensor(NUM_OF_SAMPLES);
            if(sense > CAP_THRESHOLD){
                  Serial.print("Sensor");  
                  Serial.print(i); 
                  Serial.print(": "); 
                  Serial.print(sense);                 
                  Serial.print("\t");
                  LED[i].on1();
            } else{
                  LED[i].off();
            } 
      }
      
      /*
      
      
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


*/

}
