#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include <Arduino.h>
#include <Led.h>

class LedBlinker
{
private:
    Led led;
    unsigned long blinkDelayMillis;
    unsigned long lastTimeBlinkedMillis;

    void toggleLed();

public:
    LedBlinker() {}
    LedBlinker(Led &led);
    LedBlinker(Led &led, unsigned long blinkDelayMillis);

    void initLed();
    void update();

    unsigned long getBlinkDelayMillis();
    void setBlinkDelayMillis(unsigned long newDelayMillis);
};

#endif