#include <Arduino.h>
#include <Led.h>
#include <LedBlinker.h>
#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LEDPIN 8
#define DHTPIN 13
#define DHTTYPE DHT11
#define SCREEN_WIDTH 128 // pixels
#define SCREEN_HEIGHT 64 // pixels
#define OLED_RESET -1    // reset pin

Led led(LEDPIN);
LedBlinker ledBlinker(led);
DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int delayMillis = 1000;
unsigned long lastReadingsMillis = millis();
unsigned long currentMillis;

struct environmentReadings
{
  float temp;
  float humid;
};

void printReadings(environmentReadings r)
{
  Serial.print("Temp: ");
  Serial.print(r.temp);
  Serial.print(" °C");
  Serial.print(" Humidity: ");
  Serial.print(r.humid);
  Serial.println(" %");
}

environmentReadings getEnvironmentReadings()
{
  environmentReadings reading;
  reading.temp = dht.readTemperature();
  reading.humid = dht.readHumidity();
  return reading;
}

void setup()
{
  Serial.begin(9600);
  ledBlinker.initLed();
  dht.begin();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 unnavailable!");
    for (;;)
      ;
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.drawPixel(10, 10, WHITE);
  display.display();
  delay(2000);
}

void displayEnvironmentReadings(environmentReadings reading)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.cp437(true); // Use full 256 char 'Code Page 437' font
  display.println("Temperature:");
  display.println();
  display.println(String(reading.temp) + " C");
  display.println();
  display.println("Humidity: ");
  display.println();
  display.println(String(reading.humid) + " %");
  display.display();
}

void loop()
{
  currentMillis = millis();
  environmentReadings r = getEnvironmentReadings();
  displayEnvironmentReadings(r);
  if (currentMillis - lastReadingsMillis > delayMillis)
  {
    lastReadingsMillis = currentMillis;
    printReadings(r);
    if (r.temp < 23.0)
    {
      ledBlinker.update();
    }
  }
}