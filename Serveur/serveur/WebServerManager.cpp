#include "WebServerManager.h"

ESP8266WebServer WebServerManager::server(80);
WebSocketsServer WebServerManager::webSocket(81); // Initialisation du serveur WebSocket sur le port 81

void WebServerManager::setupServer() {
    server.on("/", HTTP_GET, []() {
        WebServerManager::server.send(200, "text/html", "<!DOCTYPE HTML><html><head><title>ESP8266 Pression Capteur Monitoring</title></head><body><h1>Monitoring de la Pression</h1><p>Page de monitoring...</p></body></html>");
    });

    // Configuration de votre route pour la réception des données POST
    server.on("/post-data", HTTP_POST, []() {
        if (server.hasArg("plain")) {
            String data = server.arg("plain");
            Serial.println(data);
            // Ici, retransmettez les données aux clients WebSocket
            webSocket.broadcastTXT(data);
            server.send(200, "text/plain", "Donnees recues");
        } else {
            server.send(200, "text/plain", "Aucune donnee recue");
        }
    });

    server.begin();
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.println("Serveur HTTP et WebSocket demarres");
}

void WebServerManager::handleClient() {
    server.handleClient();
    webSocket.loop(); // Gestion des événements WebSocket
}

void WebServerManager::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Deconnecte!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connecte: %d.%d.%d.%d\n", num, ip[0], ip[1], ip[2], ip[3]);
            // Envoyez un message de bienvenue au client WebSocket
            webSocket.sendTXT(num, "Bienvenue!");
            break;
        }
        case WStype_TEXT:
            Serial.printf("[%u] Texte: %s\n", num, payload);
            // Ici, vous pouvez traiter les messages entrants si nécessaire
            break;
        // Ajoutez d'autres cas si nécessaire
    }
}
