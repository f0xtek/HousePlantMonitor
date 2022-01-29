#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
private:
    byte pin;
    byte state;
    byte brightness = 255;

public:
    Led() {}
    Led(byte pin);

    void init();
    void init(byte defaultState);
    void init(byte defaultState, byte brightness);
    void on();
    void on(byte brightness);
    void off();
    bool isPoweredOn();
    void toggle();
};

#endif