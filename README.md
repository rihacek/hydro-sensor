## Moisture Sensor w Wifi

Gather moisture data and send over to an MQTT broker via wifi so that I stop murdering my potted plants. 
Based on this introduction:  https://create.arduino.cc/projecthub/electropeak/complete-guide-to-use-soil-moisture-sensor-w-examples-756b1f


### Note:
This is built with resistive moisture sensor. If this corrodes too quickly, it might be a good plan to replace with a capacitive sensor.

### Libraries:
WifiManager - https://github.com/tzapu/WiFiManager
MQTT - https://github.com/knolleary/pubsubclient
