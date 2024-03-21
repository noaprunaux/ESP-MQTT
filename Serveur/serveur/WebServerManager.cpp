#include "WebServerManager.h"
#include <LittleFS.h> // Assurez-vous d'inclure LittleFS si nécessaire

// Initialisation du WebSocket
AsyncWebSocket WebServerManager::ws("/ws");

void WebServerManager::setup(AsyncWebServer& server, const char* serverIndex) {
    if (!LittleFS.begin()) {
        Serial.println("An Error has occurred while mounting LittleFS");
        return;
    }

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/index.html", "text/html");
    });

    // Nouvelle route pour la page 'connected.html'
    server.on("/connected", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/connected.html", "text/html");
    });

    // Configuration du WebSocket
    ws.onEvent(onWsEvent);
    server.addHandler(&ws);

    server.begin();
}


void WebServerManager::onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.println("Websocket client connection received");
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.println("Client disconnected");
    } else if (type == WS_EVT_DATA) {
        // Ici, vous pouvez gérer les données reçues du client si nécessaire
    }
}
