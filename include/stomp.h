#ifndef STOMP_H
#define STOMP_H

#include <Arduino.h>
#include "midi.h"
#include <stdint.h>
#include <Bounce.h>

class Stomp 
{ 
    public: 
        Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down, MidiMessage *up);
        Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down);
        void onPress();
        void onRelease();
        void loop();

    private:
        uint8_t button_pin;
        uint8_t indicator_pin;

        bool release;
        MidiMessage *down_msg;
        MidiMessage *up_msg;

        Bounce button;

};

#endif