#ifndef HTTPCLIENTMANAGER_H
#define HTTPCLIENTMANAGER_H

#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class HTTPClientManager {
public:
    String httpGETRequest(const char* serverName);
    String httpPOSTRequest(const char* serverName, const String& payload);
};

#endif
