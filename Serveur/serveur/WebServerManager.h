#ifndef WEBSERVERMANAGER_H // Garde d'inclusion pour éviter l'inclusion récursive
#define WEBSERVERMANAGER_H

#include <ESPAsyncWebServer.h>
#include <FS.h>

class WebServerManager {
public:
    static void setup(AsyncWebServer& server, const char* serverIndex);
    static void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
private:
    static AsyncWebSocket ws; // Déclaration du WebSocket
};

#endif // WEBSERVERMANAGER_H
