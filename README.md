A fundamental project structure for ESP 8266 projects :
the project is based on https://www.john-lassen.de/en/projects/esp-8266-arduino-ide-webconfig
built up a configure web page, in addition the following features have been implemented: 

1.mqtt ( maqtt config page, mqtt client handle  )

2.use SPIFFS to replace EPPROM

3.OTA supports

4.A mqtt test (example)

5.Some code refatoring

reference 
https://www.john-lassen.de/en/projects/esp-8266-arduino-ide-webconfig

Know issues:

1.The project cannot compile on Arduino IDE Mac version . 
  Despite the poject can be compiled and uploaded successfully on Mac OS, it will crashed on run time. The same code on windows Arduino IDE
 works perfectly. Should be a internal bug in ESP8266 arduino lib.
