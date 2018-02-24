
#include "FS.h"
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <Ticker.h>

#include "datad.h"
#include "helpers.h"
#include "WebGlobal.h"
#include "OTA.h"
#include "MQTT_Client.h"

/*
Include the HTML, STYLE and Script "Pages"
*/
#include "Page_Root.h"
#include "Page_Admin.h"
#include "Page_Script.js.h"
#include "Page_Style.css.h"
#include "Page_NTPsettings.h"
#include "Page_Information.h"
#include "Page_General.h"
#include "PAGE_NetworkConfiguration.h"
#include "PAGE_MqttConfig.h"
#include "example.h"

#include "WebServer.h"


#define AdminTimeOut 30  // Defines the Time in Seconds, when the Admin-Mode will be diabled
//boolean isOTADone=false;


void setup ( void ) {
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }
	Serial.begin(9600);
	delay(500);
	ReadConfig();
	Serial.println("config fetched");	

  sprintf (mqttCharServer, "%i.%i.%i.%i", config.MqttIP [0], config.MqttIP [1], config.MqttIP [2], config.MqttIP [3]);
	
  ConfigureWifi();
  Set_mqtt_server(AdminEnabled);
  Setup_Pins();
	Setup_web_page();

	Serial.println( "HTTP server started" );
	tkSecond.attach(1,Second_Tick);
	UDPNTPClient.begin(2390);  // Port for NTP receive

    // Start OTA server.
  SetupOTA((const char *)config.DeviceName.c_str());
}

 
void loop ( void ) { 
   if (!HandleOTA(config.ota))// OTA mode 
  {
    	if (AdminEnabled)
    	{
    		if (AdminTimeOutCounter > AdminTimeOut)
    		{
    			 AdminEnabled = false;
            WiFi.mode(WIFI_STA);
           //ConfigureWifi();
           Set_mqtt_server(AdminEnabled);
    			 Serial.println("Admin Mode disabled!");
    		}
    	}

      Handle_NTP();

    	Handle_auto_switch();

    	server.handleClient();

    	/*
    	*    Your Code here
    	*/
      if (!AdminEnabled)
      {
          //delay(200);
          Handle_mqtt();
      }

    	if (Refresh)  
    	{
    		Refresh = false;
    		///Serial.println("Refreshing...");
    		 //Serial.printf("FreeMem:%d %d:%d:%d %d.%d.%d \n",ESP.getFreeHeap() , DateTime.hour,DateTime.minute, DateTime.second, DateTime.year, DateTime.month, DateTime.day);
    	}
 
  }

}




