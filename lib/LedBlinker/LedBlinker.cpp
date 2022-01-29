#include <LedBlinker.h>
#include <Arduino.h>

LedBlinker::LedBlinker(Led &led)
{
    this->led = led;
    lastTimeBlinkedMillis = millis();
    blinkDelayMillis = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long blinkDelayMillis)
{
    this->led = led;
    lastTimeBlinkedMillis = millis();
    this->blinkDelayMillis = blinkDelayMillis;
}

void LedBlinker::initLed()
{
    led.init();
}

void LedBlinker::toggleLed()
{
    led.toggle();
}

void LedBlinker::update()
{
    unsigned long currentMillis = millis();
    if (currentMillis - lastTimeBlinkedMillis > blinkDelayMillis)
    {
        lastTimeBlinkedMillis = currentMillis;
        toggleLed();
    }
}

unsigned long LedBlinker::getBlinkDelayMillis()
{
    return blinkDelayMillis;
}

void LedBlinker::setBlinkDelayMillis(unsigned long newDelayMillis)
{
    blinkDelayMillis = newDelayMillis;
}