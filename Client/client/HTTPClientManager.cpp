#include "HTTPClientManager.h"

void HTTPClientManager::sendPostRequest(const String& url, const String& payload) {
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, url); // Modification ici
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        
        int httpResponseCode = http.POST(payload);
        
        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Réponse reçue du serveur : " + response);
        } else {
            Serial.print("Erreur dans l'envoi de la requête : ");
            Serial.println(httpResponseCode);
        }
        http.end();
    } else {
        Serial.println("Non connecté au WiFi");
    }
}
