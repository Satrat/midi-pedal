#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>
#include <stdint.h>

enum MidiMessageType
{
    NOTE_ON,
    NOTE_OFF
};

class MidiMessage
{ 
    public: 
        MidiMessage(uint8_t p, uint8_t v, uint8_t c, MidiMessageType t);
        MidiMessage(uint8_t p, MidiMessageType t);
        MidiMessage(uint8_t p);
        void sendMessage();

    private:
        uint8_t pitch;
        uint8_t velocity;
        uint8_t channel;
        MidiMessageType type;
};

#endif