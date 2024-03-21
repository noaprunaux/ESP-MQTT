#include "WiFiManager.h"
#include <ESP8266WiFi.h>

const char* WiFiManager::ssid = "ESP8266-Access-Point";       // SSID du WiFi
const char* WiFiManager::password = "123456789";              // MDP du WiFi

void WiFiManager::setup() {
    Serial.print("Setting AP (Access Point)…");
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
}
