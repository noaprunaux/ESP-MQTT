#ifndef SensorDataSender_h
#define SensorDataSender_h

#include <Arduino.h>
#include <vector>
#include "EspMQTTClient.h"

class SensorDataSender {
public:
    SensorDataSender(EspMQTTClient& mqttClient, const String& topic, unsigned long sendInterval = 10000);
    void addData(const String& data);
    void loop();
private:
    EspMQTTClient& _mqttClient;
    String _topic;
    unsigned long _sendInterval;
    unsigned long _lastSendTime;
    String _dataBuffer;
};

#endif
