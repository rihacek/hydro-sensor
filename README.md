## Moisture Sensor w Wifi

Gather moisture data and send over to an MQTT broker so that I stop murdering my potted plants

* wifi enabled
* time pulled from NTP

### Note:
I've included some info on configuring the ESP8266 WiFi chip in the comments. You can reset what's stored on the chip by changing board settings.

### Libraries:

WifiManager - https://github.com/tzapu/WiFiManager
NTPClient - https://github.com/arduino-libraries/NTPClient