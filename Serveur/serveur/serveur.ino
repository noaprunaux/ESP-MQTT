#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  if(!SPIFFS.begin()){ Serial.println("An Error has occurred while mounting SPIFFS"); return; }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){ request->send(SPIFFS, "/index.html", "text/html"); });

  // Ajout d'un gestionnaire pour les requêtes POST à /post-data
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request){}, NULL,
  [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
    Serial.println("Données POST reçues à la racine:");
    for(size_t i = 0; i < len; i++) {
      Serial.write(data[i]);
    }
    Serial.println();
    request->send(200, "text/plain", "Données reçues avec succès à la racine");
  });


  server.begin();
}

void loop() {}
