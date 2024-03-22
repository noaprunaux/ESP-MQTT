#include "WiFiConnector.h"

WiFiConnector::WiFiConnector(const char* ssid, const char* password)
: _ssid(ssid), _password(password) {}

void WiFiConnector::connectToWiFi() {
    Serial.print("Connexion à ");
    Serial.print(_ssid);
    WiFi.begin(_ssid, _password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnecté au WiFi");
}
