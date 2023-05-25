#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!aht.begin()) {
    Serial.println("Could not find AHT10 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  float temperature = aht.readTemperature();
  float humidity = aht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Delay between readings
}
