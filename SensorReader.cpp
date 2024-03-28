#include "SensorReader.h"


int16_t sensorData[NUM_SENSORS];

#define TCA9548A_ADDR 0x70
#define SENSOR_ADDR   0x6C
#define SENSOR_MEMORY_ADDR 0x30
#define NUM_SENSORS 8


String concat_val = "";
Ticker timer;

void setupSensorReader() {
    Serial.begin(115200);
    Wire.begin();
    Wire.setClock(340000);

    Wire.beginTransmission(TCA9548A_ADDR);
    Wire.write(0xFF);
    Wire.endTransmission();

    timer.attach_ms(2, readSensors);
}

void readSensors() {
    unsigned long currentTime = millis();
    concat_val = "";

    Wire.beginTransmission(TCA9548A_ADDR);
    Wire.write(0xFF); // Activer tous les canaux, si nécessaire à chaque lecture
    Wire.endTransmission();

    for (int currentSensor = 0; currentSensor < NUM_SENSORS; currentSensor++) {
        Wire.beginTransmission(TCA9548A_ADDR);
        Wire.write(1 << currentSensor);
        if (Wire.endTransmission() != 0) {
            Serial.println("Erreur lors de la sélection du canal");
            continue;
        }

        Wire.beginTransmission(SENSOR_ADDR);
        Wire.write(SENSOR_MEMORY_ADDR);
        if (Wire.endTransmission() != 0) {
            Serial.println("Erreur lors de la sélection de l'adresse mémoire du capteur");
            continue;
        }

        Wire.requestFrom(SENSOR_ADDR, 2);
        if (Wire.available() >= 2) {
            int16_t sensorValue = Wire.read() | (Wire.read() << 8);
            concat_val += String(sensorValue) + " ";
        }
    }

    Serial.print(concat_val);
    Serial.print(" ");
    Serial.println(currentTime);
}