#include "MyWebsocketServer.hpp"

extern uint8_t ledBuff[255*26][4];

MyWebsocketServer::MyWebsocketServer(int port):
    webSocket(port)
{
    
}

void MyWebsocketServer::begin()
{
    webSocket.begin();                          // start the websocket server
    //webSocket.onEvent(std::function<void(unsigned char, WStype_t, unsigned char*, unsigned int)> &webSocketEvent);          // if there's an incomming websocket message, go to function 'webSocketEvent'
    webSocket.onEvent(std::bind(&MyWebsocketServer::webSocketEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));          // if there's an incomming websocket message, go to function 'webSocketEvent'
    Serial.println("WebSocket server started.");
}

void MyWebsocketServer::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) 
{ // When a WebSocket message is received
  Serial.printf("[%u] Event\n", (int)type);

  switch (type) {
    case WStype_DISCONNECTED:             // if the websocket is disconnected
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {              // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:                     // if new text data is received
      Serial.printf("[%u] get Text: %s\n", num, payload);
      break;

      case WStype_BIN:
      Serial.printf("[%u] get Binary with length: %u \n", num, length);
      uint32_t startIndex = (((uint32_t)payload[0]) << 8) + payload[1];
      for(uint32_t i = 0; i < length-2; i++)
      {
        *((&ledBuff[0][0]) + (startIndex + i)) = payload[i+2];
      }
      newImageReceived = true;

      break;
  }
}

bool MyWebsocketServer::newImage()
{
  bool result = newImageReceived;
  newImageReceived = 0;
  return result;
}

void MyWebsocketServer::loop()
{
  webSocket.loop();
}