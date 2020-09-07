#include <Arduino.h>
#include "stomp.h"
#include "midi.h"
#include "constants.h"
#include <PacketSerial.h>

uint8_t stompPins[NUM_STOMPS] = {stompPin1, stompPin2, stompPin3, stompPin4};
uint8_t indicatorPins[NUM_STOMPS] = {indicatorPin1, indicatorPin2, indicatorPin3, indicatorPin4};
Stomp *stomps[NUM_STOMPS];
PacketSerial pSerial;

void onPacketReceived(const uint8_t* buffer, size_t size)
{
    if(size != 4) return;

    uint8_t config_byte = buffer[0];
    uint8_t state = (config_byte & 0x80) >> 7;
    uint8_t stomp_id = (config_byte & 0x70) >> 4;
    if(stomp_id >= NUM_STOMPS) return;

    uint8_t cycle_id = (config_byte & 0x08) >> 3;
    uint8_t cycle_len = (config_byte & 0x07);

    MidiMessageType midi_type = (MidiMessageType)((buffer[1] & 0xF0) >> 4);
    uint8_t channel = (buffer[1] & 0x0F);
    uint8_t data_1 = buffer[2];
    uint8_t data_2 = buffer[3];

    StompConfig config = {state, stomp_id, cycle_id, cycle_len, midi_type, channel, data_1, data_2};
    stomps[stomp_id]->processStompConfig(config);
}

void setup()
{
    stomps[0] = new Stomp(stompPins[0], indicatorPins[0], new MidiMessage(NOTE_ON, 1, 60, 100));
    stomps[1] = new Stomp(stompPins[1], indicatorPins[1], new MidiMessage(NOTE_ON, 1, 62, 100));
    stomps[2] = new Stomp(stompPins[2], indicatorPins[2], new MidiMessage(NOTE_ON, 1, 64, 100));
    stomps[3] = new Stomp(stompPins[3], indicatorPins[3], new MidiMessage(NOTE_ON, 1, 65, 100), new MidiMessage(NOTE_OFF, 1, 65));

    pSerial.setPacketHandler(&onPacketReceived);
    pSerial.begin(9600);
}

void loop()
{
    for(size_t i = 0; i < NUM_STOMPS; i++)
    {
        stomps[i]->loop();
   }

    pSerial.update();

    delay(10);
}