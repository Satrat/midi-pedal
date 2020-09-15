#ifndef STOMP_H
#define STOMP_H

#include <Arduino.h>
#include "midi.h"
#include <stdint.h>
#include <Bounce.h>

#define PRESS_STATE 0
#define RELEASE_STATE 1

typedef struct StompConfig { 
    uint8_t state;
    uint8_t stomp_id;
    uint8_t cycle_on;
    uint8_t cycle_len;

    MidiMessageType midi_type;
    uint8_t channel;
    uint8_t data_1;
    uint8_t data_2;
} StompConfig;

class Stomp 
{ 
    public: 
        Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down, MidiMessage *up);
        Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down);
        void processStompConfig(StompConfig config);
        void onPress();
        void onRelease();
        void loop();

    private:
        void updatePressMessage(MidiMessage *new_msg);
        void updateReleaseMessage(MidiMessage *new_msg);
        uint8_t button_pin;
        uint8_t indicator_pin;

        bool release;
        MidiMessage *press_msg;
        MidiMessage *release_msg;

        Bounce button;

};

#endif