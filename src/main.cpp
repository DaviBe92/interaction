#include <FastLED.h>
#include <CapacitiveSensor.h>
#include "defines.h"
#include "led.h"
#include "player.h"

///////////////////////////////////////////////////////////////////////////////////////////

// LedRing(fortlaufende Nummer, Anschluss Pin)
LedRing LED[] = {LedRing(0, 2), LedRing(1, 3), LedRing(2, 4), LedRing(3, 5)};

//initalize players
Player one;
Player two;


void setup()
{
      // This function sets up the LEDs and tells the controller about them
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS * NUM_OF_KEYS);
      //Random seed
      randomSeed(analogRead(0));
}

//gamelogic

void startgame()
{

      // Wait for both Players
      LED[START_A].on1();
      LED[START_B].on2();
      while (!(LED[START_A].sense() && LED[START_B].sense()))
      {
            delay(10);
      }
      LED[START_A].off();
      LED[START_B].off();
      delay(REFRESH_DELAY);

      // Splash screen

      for (int i = 0; i < NUM_OF_KEYS / 2; i++)
      {
            LED[i].on1();
            LED[i + NUM_OF_KEYS / 2].on2();
            delay(REFRESH_DELAY);
      }

      delay(SPLASH_DELAY);

      for (int i = 0; i < NUM_OF_KEYS; i++)
      {
            LED[i].off();
            delay(REFRESH_DELAY);
      }
}

void rungame()
{

      // Light up 2 random buttons , make sure not the same
      int ran1 = random(NUM_OF_KEYS);
      int ran2 = random(NUM_OF_KEYS);
      while (ran1 == ran2)
      {
            ran2 = random(NUM_OF_KEYS);
      }
      LED[ran1].on1();
      LED[ran2].on2();

      // wait for input, (timeout)
      bool touch = false;
      unsigned long currentTime = millis();       
      while (!touch && millis() < currentTime + GAME_TIMEOUT)
      {
            if (LED[ran1].sense())
            {
                  touch = true;
                  one.addScore();
            }
            else if (LED[ran2].sense())
            {
                  touch = true;
                  two.addScore();
            }
      }
      LED[ran1].off();
      LED[ran2].off();

      //delay between rounds
      delay(GAME_DELAY);
}

void endgame()
{
      for (int i = 0; i < NUM_OF_KEYS; i++)
      {

            if (one.getScore() > two.getScore())
            {
                  //if player 1 wins
                  LED[i].on1(); 
            }
            else if (two.getScore() > one.getScore())
            {
                  //if player 2 wins
                  LED[i].on2();
            }

            else
            {
                  for (int i = 0; i < NUM_OF_KEYS / 2; i++)
                  {
                        LED[i].on1();
                        LED[i + NUM_OF_KEYS / 2].on2();
                        delay(REFRESH_DELAY);
                  }
            }
      }

      delay(SPLASH_DELAY);

      for (int i = 0; i < NUM_OF_KEYS; i++)
      {
            LED[i].off();
            delay(REFRESH_DELAY);
      }
}

void loop()
{
      
      startgame();
      // Log time before game start
      unsigned long time = millis();
      while (millis() < time + GAME_TIME * 1000)
      {
            rungame();
      }
      endgame();
      // restart rungame if game time not over
      // else launch endgame
      delay(1000);
}