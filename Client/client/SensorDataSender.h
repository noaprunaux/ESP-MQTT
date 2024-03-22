#ifndef SensorDataSender_h
#define SensorDataSender_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>

class SensorDataSender {
public:
    SensorDataSender(const char* serverUrl);
    void sendSensorData(int sensorValue);

private:
    const char* _serverUrl;
};

#endif
