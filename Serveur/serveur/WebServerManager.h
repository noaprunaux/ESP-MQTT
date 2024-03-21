#ifndef WebServerManager_h
#define WebServerManager_h
#include <LittleFS.h> // Ecrire de la data
#include <ESPAsyncWebServer.h>

class WebServerManager {
public:
    static void setup(AsyncWebServer& server, const char* serverIndex);
private:
    static AsyncWebSocket ws;
    static void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
};

#endif
