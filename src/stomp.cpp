#include "stomp.h"

Stomp::Stomp(uint8_t b_pin, uint8_t i_pin) : button (b_pin, 10)
{
    button_pin = b_pin;
    indicator_pin = i_pin;

    pinMode(button_pin, INPUT_PULLUP);
    pinMode(indicator_pin, OUTPUT);
}

void Stomp::onPress()
{
    digitalWrite(indicator_pin, LED_ON);
    usbMIDI.sendNoteOn(60, 100, 1);
}

void Stomp::onRelease()
{
    digitalWrite(indicator_pin, LED_OFF);
    usbMIDI.sendNoteOn(62, 100, 1);
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
