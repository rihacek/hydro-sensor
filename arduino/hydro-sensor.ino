// secrets
#include "src/arduino_secrets.h"
const char* mqtt_user = MQTT_USER;
const char* mqtt_pw = MQTT_PW;

// Wifi
#include <WiFiManager.h>
#include <ESP8266WiFi.h>

// Time
#include <NTPClient.h>

// MQTT
#include <PubSubClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference

#define SensorPin A0 
float sensorValue = 0; 
void setup() { 
 Serial.begin(9600); 
} 
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 delay(5000); 
} 