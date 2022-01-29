#include "Led.h"

Led::Led(byte pin)
{
    this->pin = pin;
    state = LOW;
}

void Led::init()
{
    pinMode(pin, OUTPUT);
}

void Led::init(byte defaultState)
{
    init();

    if (defaultState == HIGH)
    {
        on();
    }
    else
    {
        off();
    }
}

void Led::on()
{
    state = HIGH;
    digitalWrite(pin, state);
}

void Led::off()
{
    state = LOW;
    digitalWrite(pin, state);
}

bool Led::isPoweredOn()
{
    return state == HIGH;
}

void Led::toggle()
{
    if (isPoweredOn())
    {
        off();
    }
    else
    {
        on();
    }
}