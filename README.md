# Proyecto de Monitoreo de Condiciones Ambientales con ESP8266

Este proyecto utiliza un microcontrolador ESP8266 para monitorear las condiciones ambientales con sensores DHT11 y BH1750. Los datos recogidos son enviados a Azure IoT Hub para su posterior análisis y almacenamiento.

## Componentes

- Microcontrolador ESP8266
- Sensor de temperatura y humedad DHT11
- Sensor de luz BH1750

## Funcionalidad

El ESP8266 recoge datos de temperatura, humedad y luz de los sensores DHT11 y BH1750, respectivamente. Estos datos se envían a Azure IoT Hub a intervalos regulares.

## Configuración

Para utilizar este proyecto, necesitarás:

- Un ESP8266 configurado con el entorno de desarrollo Arduino.
- Un Azure IoT Hub configurado para recibir datos.
- Las bibliotecas necesarias para interactuar con los sensores DHT11 y BH1750 y Azure IoT Hub.

### Configuración de Azure IoT Hub

1. Crea una instancia de Azure IoT Hub en el portal de Azure.
2. Registra tu dispositivo en Azure IoT Hub para obtener las credenciales necesarias.

### Configuración del ESP8266

1. Instala las bibliotecas necesarias en el entorno de desarrollo de Arduino: DHT sensor library, BH1750 library y Azure IoT Hub library.
2. Carga el código del proyecto en el ESP8266.
3. Asegúrate de actualizar las credenciales de Azure IoT Hub en el código antes de cargarlo en el ESP8266.

## Uso

Una vez configurado, el ESP8266 comenzará a enviar datos de temperatura, humedad y luz a Azure IoT Hub.

## Contribuir

Las contribuciones son bienvenidas. Por favor, abre un issue o pull request para cualquier corrección o mejora.

## Licencia

MIT