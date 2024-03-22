#ifndef HTTPClientManager_h
#define HTTPClientManager_h

#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h> 

class HTTPClientManager {
public:
    static void sendPostRequest(const String& url, const String& payload);
};

#endif
