#ifndef MY_WEBSERVER_HPP
#define MY_WEBSERVER_HPP


#include <ESP8266WebServer.h>

//#define MAX_FILE_SIZE 12675

class MyWebserver
{
    public:
    MyWebserver();
    void init();
    void loop();

    private:
    void handleRequest();
    void handlePostRequest();
    void handleNotFound();
    bool handleFileRead(String path);       // send the right file to the client (if it exists)
    void handleFileUpload();                // upload a new file to the SPIFFS
    String getContentType(String filename); // convert the file extension to the MIME type

    ESP8266WebServer webServer;
    //char fileBuf[MAX_FILE_SIZE];
    uint32_t fileBufIndex;
};

#endif
