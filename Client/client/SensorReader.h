#ifndef SENSORREADER_H
#define SENSORREADER_H

#include <Arduino.h>
#include <Wire.h>

// Adresses I2C
#define SENSOR_ADDR   0x6C

// Adresses mémoire des capteurs
#define SENSOR_MEMORY_ADDR 0x30

void readSensors();

#endif