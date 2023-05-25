#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_BME280 bme;             // Create an instance of the BME280 sensor
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Create an instance of the SSD1306 OLED display

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize the BME280 sensor
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("BME280");
  display.println("Temp:        F");
  display.println("Pressure:    hPa");
  display.println("Humidity:    %");
  display.println("--------------");
  display.display();
  delay(2000); // Wait for 2 seconds before starting the loop
}

void loop() {
  // Read the temperature, humidity, and pressure from the BME280 sensor
  float temperature = bme.readTemperature() * 1.8 + 32; // Convert temperature to Fahrenheit
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("BME280");
  display.print("Temp: ");
  display.print(temperature);
  display.println(" F");

  display.print("Pressure: ");
  display.print(pressure);
  display.println(" hPa");

  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.println("--------------");

  display.display();
  delay(2000); // Wait for 2 seconds before reading the sensor again
}
