#include "SensorDataSender.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

SensorDataSender::SensorDataSender(const char* serverUrl) : _serverUrl(serverUrl) {}

void SensorDataSender::sendSensorData(int16_t sensorValues[], int numSensors) {
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, _serverUrl); // Utilisez la nouvelle API HTTPClient avec WiFiClient
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        String httpRequestData = "values=";
        for (int i = 0; i < numSensors; ++i) {
            if (i > 0) httpRequestData += ","; // Séparer les valeurs par une virgule
            httpRequestData += String(sensorValues[i]);
        }

        int httpResponseCode = http.POST(httpRequestData);
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}
