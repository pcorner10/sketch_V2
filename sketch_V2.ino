#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#define DHTPIN D4     // Pin donde está conectado el sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter;  // Crea una instancia del sensor BH1750

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx and BH1750 test!");

  dht.begin();
  Wire.begin();
  lightMeter.begin();
}

void loop() {

  // Lee la humedad (porcentaje)
  float h = dht.readHumidity();
  // Lee la temperatura en Celsius (por defecto)
  float t = dht.readTemperature();
  // Lee la temperatura en Fahrenheit (comentarlo si no se necesita)
  // float f = dht.readTemperature(true);

    // Lee la luz en lux
  float lux = lightMeter.readLightLevel();

  // Comprueba si alguna lectura falló y sale temprano (para volver a intentarlo).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
   // Espera un par de segundos entre medidas.
  // Calcula el índice de calor en Fahrenheit (el índice de calor es la temperatura percibida por el cuerpo humano en función de la humedad.
  // float hif = dht.computeHeatIndex(f, h);
  // Calcula el índice de calor en Celsius
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C");
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(2000);
}