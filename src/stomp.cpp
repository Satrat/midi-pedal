#include "stomp.h"

Stomp::Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down, MidiMessage *up) : button (b_pin, 10)
{
    button_pin = b_pin;
    indicator_pin = i_pin;

    pinMode(button_pin, INPUT_PULLUP);
    pinMode(indicator_pin, OUTPUT);

    press_msg = down;
    release_msg = up;
    release = true;

}

Stomp::Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down) : button (b_pin, 10)
{
    button_pin = b_pin;
    indicator_pin = i_pin;

    pinMode(button_pin, INPUT_PULLUP);
    pinMode(indicator_pin, OUTPUT);

    press_msg = down;
    release_msg = nullptr;
    release = false;

}

void Stomp::processStompConfig(StompConfig config)
{
    if (config.state == PRESS_STATE){
        updatePressMessage(new MidiMessage(config.midi_type, config.channel, config.data_1, config.data_2, config.cycle_len));
    } else {
        updateReleaseMessage(new MidiMessage(config.midi_type, config.channel, config.data_1, config.data_2));
    }

}


void Stomp::updatePressMessage(MidiMessage *new_msg)
{
    delete press_msg;
    press_msg = new_msg;
    release = false;
}

void Stomp::updateReleaseMessage(MidiMessage *new_msg)
{
    delete release_msg;
    release_msg = new_msg;
    release = true;
}

void Stomp::onPress()
{
    digitalWrite(indicator_pin, HIGH);
    press_msg->sendMessage();
}

void Stomp::onRelease()
{
    digitalWrite(indicator_pin, LOW);
    if( release) release_msg->sendMessage();
}

void Stomp::loop()
{
    if( button.update())
    {
        if( button.risingEdge()) onRelease();
        else if ( button.fallingEdge()) onPress();
    }
}
