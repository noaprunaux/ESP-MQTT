#include "WiFiConnector.h"
#include "SensorDataSender.h"
#include <ESP8266WiFi.h> 

const char* ssid = "ESP8266-Access-Point"; // Remplacez par votre SSID
const char* password = "123456789"; // Remplacez par votre mot de passe
const char* serverUrl = "http://192.168.4.1/post-data"; // URL du serveur

WiFiConnector wifiConnector(ssid, password);
SensorDataSender dataSender(serverUrl);

void setup() {
    Serial.begin(115200);
    wifiConnector.connectToWiFi(); // Connexion au WiFi
}

void loop() {
    int sensorValue = analogRead(A0); // Simulez la lecture d'un capteur
    dataSender.sendSensorData(sensorValue);
    
    delay(10000); // Délai entre les envois de données
}
