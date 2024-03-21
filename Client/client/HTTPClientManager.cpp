#include "HTTPClientManager.h"

String HTTPClientManager::httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName); // Début de la requête HTTP
    http.setTimeout(3000); // Timeout après 3000 ms
    int httpResponseCode = http.GET(); // Exécution de la requête GET

    String payload = "--";
    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString(); // Récupération de la réponse
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end(); // Fin de la session HTTP
    return payload; // Retour de la réponse
}

String HTTPClientManager::httpPOSTRequest(const char* serverName, const String& payload) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName); // Début de la requête HTTP
    http.addHeader("Content-Type", "application/json"); // Header pour JSON
    http.setTimeout(3000); // Timeout après 3000 ms

    int httpResponseCode = http.POST(payload); // Exécution de la requête POST
    String response = "--";

    // Tentatives répétées en cas d'échec
    int retries = 3;
    while (retries-- > 0 && httpResponseCode <= 0) {
        delay(1000); // Attente entre les tentatives
        httpResponseCode = http.POST(payload); // Nouvelle tentative
        if (httpResponseCode > 0) break; // Si réussite, sortir de la boucle
    }

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        response = http.getString(); // Récupération de la réponse
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end(); // Fin de la session HTTP
    return response; // Retour de la réponse
}
