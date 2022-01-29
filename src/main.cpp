#include <Arduino.h>
#include <Led.h>
#include <LedBlinker.h>

#define LED_PIN 8

Led led(LED_PIN);
LedBlinker ledBlinker(led);

void setup()
{
  ledBlinker.initLed();
}

void loop()
{
  ledBlinker.update();
}