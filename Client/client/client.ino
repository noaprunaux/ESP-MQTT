#include "WiFiConnector.h"
#include "HTTPClientManager.h"
#include "SensorReader.h"

// Remplacez les valeurs ci-dessous par votre SSID et votre mot de passe WiFi
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

WiFiConnector wifiConnector(ssid, password);
HTTPClientManager httpManager;

void setup() {
  Serial.begin(115200);
  Serial.println();

  wifiConnector.connectToWiFi(); // Connecte le client au WiFi
  Wire.begin(); // Initialise la communication I2C pour les capteurs
}

void loop() {
  int16_t sensorValue = readSensors(); // Lecture de la valeur du capteur
  
  // Création du payload JSON pour l'envoi
  String payload = "{\"sensorValue\":" + String(sensorValue) + "}";

  // L'adresse IP ou le nom de domaine du serveur ESP8266
  String serverName = "192.168.4.1";

  // Envoi de la valeur du capteur au serveur via HTTP POST
  String response = httpManager.httpPOSTRequest(serverName.c_str(), payload);
  Serial.println("Réponse du serveur: " + response);
  
  delay(10000); // Délai avant la prochaine lecture et envoi
}
