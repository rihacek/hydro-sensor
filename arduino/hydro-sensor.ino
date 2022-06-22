// secrets
#include "src/arduino_secrets.h"
const char* mqtt_user = MQTT_USER;
const char* mqtt_pw = MQTT_PW;

// Wifi
#include <WiFiManager.h>
#include <ESP8266WiFi.h>

// Time
#include <NTPClient.h>

// Sensor Specific Libraries (using a dht 11)
#include <Adafruit_Sensor.h>
#include <DHT.h>

// MQTT
#include <PubSubClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson/wiki/API%20Reference
