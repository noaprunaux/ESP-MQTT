#ifndef WebServerManager_h
#define WebServerManager_h

#include <ESP8266WebServer.h>

class WebServerManager {
public:
    static void setupServer();
    static void handleClient();
    static ESP8266WebServer server;
};

#endif
