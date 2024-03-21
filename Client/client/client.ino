#include "WiFiConnector.h"

// Remplacez les valeurs ci-dessous par votre SSID et votre mot de passe WiFi
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

WiFiConnector wifiConnector(ssid, password);

void setup() {
  Serial.begin(115200);
  Serial.println();

  wifiConnector.connectToWiFi(); // Utilise la bibliothèque pour se connecter au WiFi
}

void loop() {
  // Votre code qui nécessite une connexion WiFi vient ici
}
