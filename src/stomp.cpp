#include "stomp.h"

Stomp::Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down, MidiMessage *up) : button (b_pin, 10)
{
    button_pin = b_pin;
    indicator_pin = i_pin;

    pinMode(button_pin, INPUT_PULLUP);
    pinMode(indicator_pin, OUTPUT);

    down_msg = down;
    up_msg = up;
    release = true;

}

Stomp::Stomp(uint8_t b_pin, uint8_t i_pin, MidiMessage *down) : button (b_pin, 10)
{
    button_pin = b_pin;
    indicator_pin = i_pin;

    pinMode(button_pin, INPUT_PULLUP);
    pinMode(indicator_pin, OUTPUT);

    down_msg = down;
    up_msg = nullptr;
    release = false;

}

void Stomp::onPress()
{
    digitalWrite(indicator_pin, HIGH);
    down_msg->sendMessage();
}

void Stomp::onRelease()
{
    digitalWrite(indicator_pin, LOW);
    if( release) up_msg->sendMessage();
}

void Stomp::loop()
{
    if( button.update())
    {
        if( button.risingEdge()) onRelease();
        else if ( button.fallingEdge()) onPress();
    }

    delay(3);
}
