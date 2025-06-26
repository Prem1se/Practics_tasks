// Ссылка на WOKWI (схема с кодом) https://wokwi.com/projects/434837360757291009

#include <Adafruit_NeoPixel.h>

#define PIN 3
#define LEDS 100  // 10x10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  // плавно меняю цвет всей ленты
  for(int i=0; i<256; i++) {
    for(int j=0; j<LEDS; j++) {
      strip.setPixelColor(j, strip.ColorHSV(i*256, 255, 100));
    }
    strip.show();
    delay(20);
  }
}
