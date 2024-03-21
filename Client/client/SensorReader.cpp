#include "SensorReader.h"

int16_t readSensors() {
  unsigned long currentTime = millis();
  int currentSensor = 0;
  int16_t sensorValue = 0;

  // Commence la transmission I2C à l'adresse du capteur
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(SENSOR_MEMORY_ADDR); // Sélectionne l'adresse mémoire du capteur
  if (Wire.endTransmission() != 0) {
    Serial.println("Erreur lors de la sélection de l'adresse mémoire du capteur");
    return 0; // Retourne 0 en cas d'erreur
  }

  // Débuter une nouvelle transmission avant d'écrire le canal
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(1 << currentSensor); // Sélectionne le canal du capteur
  if (Wire.endTransmission() != 0) {
    Serial.println("Erreur lors de la sélection du canal");
    return 0; // Retourne 0 en cas d'erreur
  }

  // Demande la lecture des données du capteur
  Wire.requestFrom(SENSOR_ADDR, 2); // Demande 2 octets
  if (Wire.available() >= 2) {
    sensorValue = Wire.read() | (Wire.read() << 8); // Lit la valeur du capteur
  } else {
    // Si moins de 2 octets sont disponibles, retourne 0 ou une valeur d'erreur spécifique
    return 0;
  }

  // Optionnellement, afficher les données lues sur la console série
  //Serial.print("Temps: ");
  //Serial.print(currentTime);
  //Serial.print(" ms, Valeur du capteur: ");
  //Serial.println(sensorValue);

  return sensorValue; // Retourne la valeur lue du capteur
}
