#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#include <ESP8266WiFi.h>  // Biblioteca para conexión WiFi (opcional)
#include <ESP8266HTTPClient.h>  // Biblioteca para realizar solicitudes HTTP (opcional)

#include <math.h>  // Biblioteca para funciones matemáticas (opcional)

// Definiciones de pines y variables globales

#define SENSOR_PIN A0
#define DHTPIN D4     // Pin donde está conectado el sensor
#define DHTTYPE DHT11   // DHT 11
#define WIFI_SSID "INFINITUM4326"  // Nombre de la red WiFi (opcional)
#define WIFI_PASSWORD "KKZHbp7grd"  // Contraseña de la red WiFi (opcional)

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;

float last_soil_moisture = 0;  // Variable para almacenar la última lectura de humedad del suelo
float last_time = 0;  // Variable para almacenar el último instante de tiempo

void setup() {
  Serial.begin(9600);

  dht.begin();
  Wire.begin();
  lightMeter.begin();

  // Conectar a la red WiFi (opcional)
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float lux = lightMeter.readLightLevel();
  float hic = dht.computeHeatIndex(t, h, false);
  float soil_moisture = analogRead(SENSOR_PIN);

  // Calcular el ratio de disminución de la humedad del suelo
  float soil_moisture_ratio = (soil_moisture - last_soil_moisture) / (millis() - last_time);

  // Actualizar los valores anteriores
  last_soil_moisture = soil_moisture;
  last_time = millis();


  // Realizar predicción utilizando un modelo de regresión lineal (o cualquier otro modelo)
  float prediction = predict(soil_moisture, soil_moisture_ratio, t, h, lux);

  Serial.println("NEW RECORD"),
  Serial.println(soil_moisture_ratio);
  Serial.println(soil_moisture);
  Serial.println(t);
  Serial.println(h);
  Serial.println(lux);

  // Enviar los datos y la predicción a través de una solicitud HTTP (opcional)
  Serial.println("PREDICTION: ");
  Serial.println(prediction);
  

  delay(2000);
}


// Función para realizar la predicción utilizando un modelo de regresión lineal (o cualquier otro modelo)
float predict(float soil_moisture, float soil_moisture_ratio, float temperature, float humidity, float lux) {
  // Variables de coeficientes del modelo (ajustar según el modelo entrenado)
  float coef_soil_moisture = 0.1;
  float coef_temperature = 0.2;
  float coef_humidity = 0.3;
  float coef_lux = 0.1;
  float intercept = 0.05;

  // Realizar la predicción utilizando la ecuación del modelo
  float prediction = intercept +  coef_soil_moisture * soil_moisture +
                     coef_soil_moisture * soil_moisture_ratio +
                     coef_temperature * temperature + coef_humidity * humidity +
                     coef_lux * lux;

  return prediction;
}