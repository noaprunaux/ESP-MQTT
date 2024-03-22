#include "WiFiManager.h" // Assurez-vous d'inclure votre WiFiManager
#include "WebServerManager.h"

void setup() {
  Serial.begin(115200);
  
  // Initialise le point d'accès WiFi avec les paramètres définis dans WiFiManager
  WiFiManager::setup();

  // Configuration et démarrage du serveur web
  WebServerManager::setupServer();
  
  Serial.println("Serveur et WiFi démarrés avec succès");
}

void loop() {
  // Gestion des clients connectés au serveur web
  WebServerManager::handleClient();
}
