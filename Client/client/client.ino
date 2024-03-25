#include "WiFiConnector.h"
#include "SensorDataSender.h"
#include "SensorReader.h"

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";
const char* serverUrl = "http://192.168.4.1/post-data";

WiFiConnector wifiConnector(ssid, password);
SensorDataSender dataSender(serverUrl);

void setup() {
    Serial.begin(115200);
    wifiConnector.connectToWiFi();
    setupSensorReader();
}

void loop() {
    delay(10000); // Laissez du temps pour la lecture des capteurs
    
    dataSender.sendSensorData(sensorData, NUM_SENSORS);
}
