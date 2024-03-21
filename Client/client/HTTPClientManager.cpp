#include "HTTPClientManager.h"

String HTTPClientManager::httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    int httpResponseCode = http.GET();

    String payload = "--";
    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end();
    return payload;
}

String HTTPClientManager::httpPOSTRequest(const char* serverName, const String& payload) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(payload);

    String response = "--";
    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        response = http.getString();
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end();
    return response;
}
