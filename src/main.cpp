#include <Arduino.h>
#include "stomp.h"

#define NUM_STOMPS 4

uint8_t stompPin1 = 2;
uint8_t stompPin2 = 3;
uint8_t stompPin3 = 4;
uint8_t stompPin4 = 5;
uint8_t stompPins[NUM_STOMPS] = {stompPin1, stompPin2, stompPin3, stompPin4};

uint8_t indicatorPin1 = 6;
uint8_t indicatorPin2 = 8;
uint8_t indicatorPin3 = 10;
uint8_t indicatorPin4 = 12;
uint8_t indicatorPins[NUM_STOMPS] = {indicatorPin1, indicatorPin2, indicatorPin3, indicatorPin4};

Stomp *stomps[NUM_STOMPS];

void setup()
{
    for(size_t i = 0; i < NUM_STOMPS; i++)
    {
        stomps[i] = new Stomp(stompPins[i], indicatorPins[i]);
    }

}

void loop()
{
    for(size_t i = 0; i < NUM_STOMPS; i++)
    {
        stomps[i]->loop();
    }

    delay(10);
}