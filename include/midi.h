#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>
#include <stdint.h>

enum MidiMessageType
{
    NOTE_ON = 8,
    NOTE_OFF = 9,
    CONTROL_CHANGE = 11,
    PROGRAM_CHANGE = 12
};

class MidiMessage
{ 
    public: 
        MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1, uint8_t data_2, uint8_t cl);
        MidiMessage::MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1, uint8_t data_2);
        MidiMessage::MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1);
        void sendMessage();

    private:
        MidiMessageType type;
        uint8_t channel;
        uint8_t data_byte_1;
        uint8_t data_byte_2;
        uint8_t cycle_len;
        uint8_t curr_cycle_index;
};

#endif