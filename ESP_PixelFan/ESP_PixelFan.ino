#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <SPI.h>
#include "src/MyWebserver.hpp"
#include "src/MyWebsocketServer.hpp"

/* Set these to your desired credentials. */
const char *ssid = "PixelFan";
const char *password = "";

#define LINES_PER_ROUND 180
#define LEDS_PER_LINE 26

uint8_t ledBuff[LINES_PER_ROUND*LEDS_PER_LINE][4];

WiFiServer dnsServer(53);
MyWebserver pixelFanWebserver;
MyWebsocketServer websocketServer(81);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/


void setup() {
  SPI.setFrequency(8000000);
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();

  delay(5000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  pixelFanWebserver.init();
  
  Serial.println("Web server started");

  dnsServer.begin();
  Serial.println("DNS server started");

  websocketServer.begin();

  //fill buffer:
	for(uint32_t i = 0; i < LINES_PER_ROUND*LEDS_PER_LINE; i++)
	{
    if(i < LINES_PER_ROUND*LEDS_PER_LINE/2)
    {
      ledBuff[i][0] = 0xFF;
      ledBuff[i][1] = 0;
      ledBuff[i][2] = 0;
      ledBuff[i][3] = 6;
    }
    else
    {
      ledBuff[i][0] = 0xFF;
      ledBuff[i][1] = 6;
      ledBuff[i][2] = 0;
      ledBuff[i][3] = 6;
    }
	}

  SPI.setFrequency(8000000);
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();

}

void loop() {
  static uint32_t cnt = 0;

  pixelFanWebserver.loop();
  websocketServer.loop();

  cnt++;

  if(cnt == 800)
  {
    if(websocketServer.newImage())
    {
      for(int i = 0; i < LINES_PER_ROUND*LEDS_PER_LINE; i++)
      {
        SPI.transfer(ledBuff[i][0]);
        SPI.transfer(ledBuff[i][1]);
        SPI.transfer(ledBuff[i][2]);
        SPI.transfer(ledBuff[i][3]);
      }
    }
    cnt = 0;
  }


  /*WiFiClient client = dnsServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        Serial.write(c);
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }*/
}
