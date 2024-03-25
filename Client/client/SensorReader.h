#ifndef SensorReader_h
#define SensorReader_h

#include <Arduino.h>
#include <Wire.h>
#include <Ticker.h>
#include "SensorDataSender.h"

// Définissez le nombre de capteurs ici
#define NUM_SENSORS 8

// Déclaration du tableau pour stocker les données des capteurs
extern int16_t sensorData[NUM_SENSORS]; 


void setupSensorReader();
void readSensors();

#endif