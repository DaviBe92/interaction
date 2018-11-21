#pragma once

// How many leds are in the Circle?
#define NUM_LEDS 13
// Data pin that led data will be written out over
#define DATA_PIN 7
// Common pin of the sensors
#define COMMON_PIN      6 
// Lower number=faster sensing, but lower accuracy
#define NUM_OF_SAMPLES  3
// Sensing threshhold
#define CAP_THRESHOLD   10
// Number of sensors
#define NUM_OF_KEYS     4
// Start button 1
#define START_A     0
// Start button 2
#define START_B     3
// led refresh delay
#define REFRESH_DELAY 200
// Splash screen delay
#define SPLASH_DELAY 3000
// Game timer in seconds
#define GAME_TIME 30
// Game delay
#define GAME_DELAY 300
// TIMEOUT
#define GAME_TIMEOUT 1000