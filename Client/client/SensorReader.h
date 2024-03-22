#ifndef SENSORREADER_H
#define SENSORREADER_H

#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include "SensorDataSender.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>

// Adresses I2C
#define SENSOR_ADDR   0x6C
#define SENSOR_MEMORY_ADDR 0x30

// Modification du prototype de la fonction
int16_t readSensors();

#endif
