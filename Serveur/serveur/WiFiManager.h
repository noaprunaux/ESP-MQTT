#ifndef WiFiManager_h
#define WiFiManager_h

class WiFiManager {
public:
    static void setup();
private:
    static const char* ssid;
    static const char* password;
};

#endif
