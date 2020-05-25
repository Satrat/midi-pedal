#include "midi.h"

MidiMessage::MidiMessage(uint8_t p, uint8_t v, uint8_t c, MidiMessageType t)
{
    pitch = p;
    velocity = v;
    channel = c;
    type = t;
}

MidiMessage::MidiMessage(uint8_t p, MidiMessageType t)
{
    pitch = p;
    velocity = 100;
    channel = 1;
    type = t;
}

MidiMessage::MidiMessage(uint8_t p)
{
    pitch = p;
    velocity = 100;
    channel = 1;
    type = NOTE_ON;
}

void MidiMessage::sendMessage()
{
    switch(type)
    {
        case NOTE_ON:
            usbMIDI.sendNoteOn(pitch, velocity,channel);
            break;
        case NOTE_OFF:
            usbMIDI.sendNoteOff(pitch, velocity, channel);
            break;
        default:
            break;
    }
}