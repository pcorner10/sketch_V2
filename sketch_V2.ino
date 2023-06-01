#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#define SENSOR_PIN A0
#define DHTPIN D4     // Pin donde está conectado el sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter;  // Crea una instancia del sensor BH1750

void setup() {
  Serial.begin(9600);

  dht.begin();
  Wire.begin();
  lightMeter.begin();
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float lux = lightMeter.readLightLevel();
  float hic = dht.computeHeatIndex(t, h, false);
  int sensorValue = analogRead(SENSOR_PIN); // Lee el valor del sensor


  delay(2000);
}