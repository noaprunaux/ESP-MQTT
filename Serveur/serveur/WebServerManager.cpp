#include "WebServerManager.h"

ESP8266WebServer WebServerManager::server(80);

void WebServerManager::setupServer() {
    server.on("/", HTTP_GET, []() {
        WebServerManager::server.send(200, "text/html", "<!DOCTYPE HTML><html><head><title>ESP8266 Pression Capteur Monitoring</title></head><body><h1>Monitoring de la Pression</h1><p>Page de monitoring...</p></body></html>");
    });

    // Mettez ici la configuration de votre serveur, par exemple:
    server.on("/post-data", HTTP_POST, []() {
        if (server.hasArg("plain")) {
            String data = server.arg("plain");
            Serial.println(data);
            server.send(200, "text/plain", "Donnees recues");
        } else {
            server.send(200, "text/plain", "Aucune donnee recue");
        }
    });

    server.begin();
    Serial.println("Serveur HTTP demarre");
}

void WebServerManager::handleClient() {
    server.handleClient();
}
