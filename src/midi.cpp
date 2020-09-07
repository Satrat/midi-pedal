#include "midi.h"

MidiMessage::MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1, uint8_t data_2, uint8_t cl)
{
    type = t;
    channel = ch;
    data_byte_1 = data_1;
    data_byte_2 = data_2;
    cycle_len = cl;
    curr_cycle_index = 0;
}

MidiMessage::MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1, uint8_t data_2)
{
    type = t;
    channel = ch;
    data_byte_1 = data_1;
    data_byte_2 = data_2;
    cycle_len = 0;
    curr_cycle_index = 0;
}

MidiMessage::MidiMessage(MidiMessageType t, uint8_t ch, uint8_t data_1)
{
    type = t;
    channel = ch;
    data_byte_1 = data_1;
    data_byte_2 = 0;
    cycle_len = 0;
    curr_cycle_index = 0;
}

void MidiMessage::sendMessage()
{
    switch(type)
    {
        case NOTE_ON:
            usbMIDI.sendNoteOn(data_byte_1 + curr_cycle_index, data_byte_2, channel);
            break;
        case NOTE_OFF:
            usbMIDI.sendNoteOff(data_byte_1 + curr_cycle_index, data_byte_2, channel);
            break;
        case CONTROL_CHANGE:
            usbMIDI.sendControlChange(data_byte_1 + curr_cycle_index, data_byte_2, channel);
            break;
        case PROGRAM_CHANGE:
            usbMIDI.sendProgramChange(data_byte_1 + curr_cycle_index, channel);
            break;
        default:
            break;
    }

    if (cycle_len > 0)
    {
        curr_cycle_index = (curr_cycle_index + 1) % cycle_len;
    }
}