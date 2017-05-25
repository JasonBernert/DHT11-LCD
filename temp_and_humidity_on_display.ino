#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}

void loop() {
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f, h);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.clear();
  lcd.print("Temperature: ");
  lcd.print(round(f));
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(round(h));

}
