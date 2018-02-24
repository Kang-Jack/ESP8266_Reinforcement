ESP01/s (ESP8266) has embedded WIFI add faster processor  which can connect with an Arduino board to get more sensor extensibility.

However , there are  two common problem  
1. The ESP01/s has a powerful process and bigger memory,it is a waste to only use its wifi part.  
2. Some of Arduino  only contains one serial port for usb connection. so only soft serial can be used to connect with ESP8266. In this case since the Arduino perform the loop much faster than soft serial communication speed, lots of MQTT message will be lost and we have to use delay in the loop to wait for MQTT message. 

the library will make ESP01/s as independent MQTT node. it make ESP01/s take responsibility to comul




d
reference 
https://www.john-lassen.de/en/projects/esp-8266-arduino-ide-webconfig