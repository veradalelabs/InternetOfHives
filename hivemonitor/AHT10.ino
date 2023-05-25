//Seed XIAO nRF52840 sense
//aht10
//GY/BM ME/PM 280


//aht10 Sample Code

#include <Wire.h>

#include <AHT10.h> //See the library download
link below!

 

AHT10Class AHT10;

void setup() {

  Serial.begin(9600);

  Wire.begin();

  if
(AHT10.begin(eAHT10Address_Low))


Serial.println("Init AHT10 Success!");

  else


Serial.println("Init AHT10 Failed!");

}

 

void loop() {


Serial.println("//Arduino & AHT10//");


Serial.println("Quick Test – Serial Monitor");


Serial.println(String("") + "Humidity(%RH):\t\t" +
AHT10.GetHumidity() + "%");


Serial.println(String("") + "Temperature(F):\t"
+ AHT10.GetTemperature() + "℃");


Serial.println(String("") + "Dewpoint(℃):\t\t"
+ AHT10.GetDewPoint() + "℃");

  delay(1000);

}