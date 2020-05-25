#ifndef STOMP_H
#define STOMP_H

#include <Arduino.h>
#include <stdint.h>
#include <Bounce.h>

class Stomp 
{ 
    public: 
        Stomp(uint8_t b_pin, uint8_t i_pin);
        void onPress();
        void onRelease();
        void loop();

    private:
        uint8_t button_pin;
        uint8_t indicator_pin;
        Bounce button;

};

#endif