#include "SensorDataSender.h"

SensorDataSender::SensorDataSender(EspMQTTClient& mqttClient, const String& topic, unsigned long sendInterval) :
    _mqttClient(mqttClient), _topic(topic), _sendInterval(sendInterval), _lastSendTime(0) {}

void SensorDataSender::addData(const String& data) {
    if (!_dataBuffer.isEmpty()) {
        _dataBuffer += ",";
    }
    _dataBuffer += data;
}

void SensorDataSender::loop() {
    if (millis() - _lastSendTime >= _sendInterval && !_dataBuffer.isEmpty()) {
        _mqttClient.publish(_topic, _dataBuffer);
        _dataBuffer = ""; // Clear the buffer after sending
        _lastSendTime = millis();
    }
}
