#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

class WebServerManager {
public:
    static void setupServer();
    static void handleClient();
    static ESP8266WebServer server;
    static WebSocketsServer webSocket; 

    // Ajoutez ces méthodes pour la gestion de WebSocket
    static void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
};
