#include <Arduino.h>
#include "stomp.h"
#include "midi.h"
#include "constants.h"

uint8_t stompPins[NUM_STOMPS] = {stompPin1, stompPin2, stompPin3, stompPin4};
uint8_t indicatorPins[NUM_STOMPS] = {indicatorPin1, indicatorPin2, indicatorPin3, indicatorPin4};
Stomp *stomps[NUM_STOMPS];

void setup()
{
    stomps[0] = new Stomp(stompPins[0], indicatorPins[0], new MidiMessage(60, NOTE_ON));
    stomps[1] = new Stomp(stompPins[1], indicatorPins[1], new MidiMessage(62, NOTE_ON));
    stomps[2] = new Stomp(stompPins[2], indicatorPins[2], new MidiMessage(64, NOTE_ON));
    stomps[3] = new Stomp(stompPins[3], indicatorPins[3], new MidiMessage(65, NOTE_ON), new MidiMessage(67, NOTE_OFF));
}

void loop()
{
    for(size_t i = 0; i < NUM_STOMPS; i++)
    {
        stomps[i]->loop();
    }

    delay(10);
}