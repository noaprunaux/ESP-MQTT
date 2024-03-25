#ifndef SensorDataSender_h
#define SensorDataSender_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class SensorDataSender {
public:
    SensorDataSender(const char* serverUrl);
    void sendSensorData(int sensorValue); // Garder pour compatibilité / utilisation unique
    void sendSensorData(int16_t sensorValues[], int numSensors);


private:
    const char* _serverUrl;
};

#endif
