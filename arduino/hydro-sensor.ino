// secrets
#include "src/arduino_secrets.h"
const char* mqtt_user = MQTT_USER;
const char* mqtt_pw = MQTT_PW;

// Wifi
#include <WiFiManager.h>
#include <ESP8266WiFi.h>

// MQTT
#include <PubSubClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference

#define MQTT_VERSION MQTT_VERSION_3_1_1
const char* MQTT_CLIENT_ID = "water01";
const char* MQTT_SERVER_IP = "192.168.86.202";
const uint16_t MQTT_SERVER_PORT = 1883;
const char* MQTT_TOPIC = "moisture01";

WiFiUDP wifi_udp;

WiFiClient espClient;
PubSubClient mqttClient(espClient);

#define SensorPin A0 
float sensorValue = 0; 

// function called to publish the moisture
void publishData(float p_moisture) {
  // create a JSON object
  StaticJsonDocument<200> jsonBuffer;
  JsonObject root = jsonBuffer.to<JsonObject>(); // clear and replace with a new JsonObject
  root["moisture"] = (String)p_moisture;
  serializeJsonPretty(root, Serial);
  Serial.println("");
  char data[200];
  serializeJson(root,data);
  mqttClient.publish(MQTT_TOPIC, data, true);
}

// function called when a MQTT message arrives
void callback(char* p_topic, byte* p_payload, unsigned int p_length) {
}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.println("INFO: Attempting MQTT connection...");
    // Attempt to connect
    if (mqttClient.connect(MQTT_CLIENT_ID, mqtt_user, mqtt_pw)) {
      Serial.println("INFO: connected");
    } else {
      Serial.print("ERROR: failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println("DEBUG: try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() { 
    Serial.begin(9600);
    WiFiManager wifiManager;  
    wifiManager.autoConnect();
    mqttClient.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
    mqttClient.setCallback(callback);
} 

void loop() { 
    for (int i = 0; i <= 100; i++) 
    { 
        sensorValue = sensorValue + analogRead(SensorPin); 
        delay(1); 
    } 
    sensorValue = sensorValue/100.0; 

    if (!mqttClient.connected()) {
        reconnect();
    }

    if (isnan(sensorValue)) {
        Serial.println("ERROR: Failed to read from DHT sensor!");
        return;
    } else {
        publishData(sensorValue);
    }

    delay (60UL * 60UL * 1000UL); //1 hour delay
} 