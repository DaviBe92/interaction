#include "CapacitiveSensor.h"

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2); // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup()
{
    cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
    Serial.begin(9600);
}

void loop()
{
    long start = millis();
    long total1 = cs_4_2.capacitiveSensor(30);


    Serial.print(millis() - start); // check on performance in milliseconds
    Serial.print("\t");             // tab character for debug windown spacing

    Serial.print(total1); // print sensor output 1
    Serial.print("\t");

    delay(10); // arbitrary delay to limit data to serial port
}