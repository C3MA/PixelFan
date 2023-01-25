#ifndef MY_WEBSOCKET_SERVER_HPP
#define MY_WEBSOCKET_SERVER_HPP

#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>

class MyWebsocketServer
{
    public:
    MyWebsocketServer(int port);
    void begin();
    void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
    void loop();
    bool newImage();

    private:
    bool newImageReceived = false;
    WebSocketsServer webSocket;
};

#endif