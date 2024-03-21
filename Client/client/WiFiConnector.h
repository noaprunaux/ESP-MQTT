#ifndef WiFiConnector_h
#define WiFiConnector_h

#include <ESP8266WiFi.h>

class WiFiConnector {
  public:
    WiFiConnector(const char* ssid, const char* password);
    void connectToWiFi();
  
  private:
    const char* _ssid;
    const char* _password;
};

#endif
