#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h> // Assurez-vous que cette inclusion est présente
#include "WiFiManager.h"
#include "WebServerManager.h"

AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    WiFiManager::setup(); // Configuration du WiFi
    WebServerManager::setup(server, "/index.html"); // Notez que vous n'avez plus besoin de passer `index_html` comme une chaîne
}
 
void loop() {
  // Garder le serveur en fonctionnement
}
