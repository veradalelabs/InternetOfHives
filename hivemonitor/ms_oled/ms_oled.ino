#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <LSM6DS3.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_BME280 bme;
Adafruit_AHTX0 aht;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

void setup() {
  Serial.begin(9600);
  Wire.begin();

  
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
      Serial.println("Device error");
  } else {
      Serial.println("Device OK!");
  }

  if (!bme.begin(0x76) || !aht.begin()) {
    Serial.println("Could not find valid sensors, check wiring!");
    while (1);
  }
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);  
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println();
  display.println("nRF52840 Multi-Sensor");
  display.println("Environmental Monitor");
  display.println("v0.1 initial release");
  display.println("veradalelabs - 2023");
  display.display();
  delay(5000);
}

void loop() {

  float bmeTemperature = bme.readTemperature() * 1.8 + 32;
  float bmeHumidity = bme.readHumidity();
  float bmePressure = bme.readPressure() / 100.0F;

  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  float ahtTemperature = temp.temperature * 1.8 + 32;
  float ahtHumidity = humidity.relative_humidity;

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Current Conditions");
  display.print("BME280:   ");
  display.print(bmeTemperature);
  display.println(" F");
  display.print("AHT10:    ");
  display.print(ahtTemperature);
  display.println(" F");
  display.print("LSM6DS3:  ");
  display.print(myIMU.readTempF(), 2);
  display.println(" F");
  display.print("Humidity: ");
  display.print(bmeHumidity);
  display.println(" %");  
  display.print("RH:       ");
  display.print(ahtHumidity);
  display.println(" %");
  display.print("Pressure: ");
  display.print(bmePressure);
  display.println(" hPa");

  display.display();
  delay(6000);
}

