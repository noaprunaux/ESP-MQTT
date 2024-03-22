#include "SensorDataSender.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

SensorDataSender::SensorDataSender(const char* serverUrl) : _serverUrl(serverUrl) {}

void SensorDataSender::sendSensorData(int sensorValue) {
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, _serverUrl); // Modification ici
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        String httpRequestData = "value=" + String(sensorValue);
        int httpResponseCode = http.POST(httpRequestData);

        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}
