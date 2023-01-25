#include "MyWebserver.hpp"
#include "Websites.hpp"

extern uint8_t* ledBuff;

MyWebserver::MyWebserver():
    webServer(80)
{

}

void MyWebserver::init()
{
  webServer.onNotFound(std::bind(&MyWebserver::handleNotFound, this));
  webServer.on("/", std::bind(&MyWebserver::handleRequest, this));
  //webServer.onFileUpload(handleUpload);

  webServer.on("/upload", HTTP_POST,                       // if the client posts to the upload page
    std::bind(&MyWebserver::handlePostRequest, this) ,                          // Send status 200 (OK) to tell the client we are ready to receive
    std::bind(&MyWebserver::handleFileUpload, this)                // Receive and save the file
  );

  webServer.begin();

}

void MyWebserver::handlePostRequest()
{
    Serial.println("POST request"); 
    
    webServer.send(200);
}

void MyWebserver::loop()
{
    webServer.handleClient();
}

void MyWebserver::handleNotFound() {
  Serial.println("handleNotFound");
  //webServer.sendHeader 	("Location","http://192.168.4.1/"); 	
  //webServer.send(302, "text/html", "<h1>Moved</h1>");
  
  webServer.send(200, "text/html", "<h1>not Found :)</h1>");
  
}

void MyWebserver::handleRequest() {
  Serial.println("handleRequest");
  webServer.send(200, "text/html", Websites::mainPage);
/*
  char tmpBuf[7];
  for(uint16_t i = 0; i < 6000; i++)
  {
    itoa(adcData[i], tmpBuf, 10);
    webServer.sendContent( tmpBuf );
    webServer.sendContent( "\n" );
  }
  webServer.client().stop();*/
}


String MyWebserver::getContentType(String filename) { // convert the file extension to the MIME type
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}


void MyWebserver::handleFileUpload(){ // upload a new file to the SPIFFS
  HTTPUpload& upload = webServer.upload();

  Serial.print("handleFileUpload: ");
  Serial.println(upload.status);

  if(upload.status == UPLOAD_FILE_START){
      fileBufIndex = 0;
    String filename = upload.filename;
    if(!filename.startsWith("/")) filename = "/"+filename;
    Serial.print("handleFileUpload Name: "); Serial.println(filename);
  } else if(upload.status == UPLOAD_FILE_WRITE){
    Serial.println("File:");
    for(uint32_t i = 0; i < upload.currentSize; i++)
    {
      //Serial.print(upload.buf[i]);
      ledBuff[fileBufIndex] = upload.buf[i];
      
      //if(fileBufIndex < (MAX_FILE_SIZE-1))
        fileBufIndex++;

    }
    Serial.println("");
  } else if(upload.status == UPLOAD_FILE_END){
      Serial.print("handleFileUpload Size: "); 
      Serial.println(upload.totalSize);
      Serial.print("pointer: ");
      Serial.println(fileBufIndex);
      webServer.sendHeader("Location","/");      // Redirect the client to the success page
      webServer.send(303);
    //} else {
    //  webServer.send(500, "text/plain", "500: couldn't create file");
    //}
  }
}





/*
bool handleFileRead(String path) { // send the right file to the client (if it exists)
  Serial.println("handleFileRead: " + path);
  if (path.endsWith("/")) path += "index.html";          // If a folder is requested, send the index file
  String contentType = getContentType(path);             // Get the MIME type
  String pathWithGz = path + ".gz";
  if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) { // If the file exists, either as a compressed archive, or normal
    if (SPIFFS.exists(pathWithGz))                         // If there's a compressed version available
      path += ".gz";                                         // Use the compressed verion
    File file = SPIFFS.open(path, "r");                    // Open the file
    size_t sent = webServer.streamFile(file, contentType);    // Send it to the client
    file.close();                                          // Close the file again
    Serial.println(String("\tSent file: ") + path);
    return true;
  }
  Serial.println(String("\tFile Not Found: ") + path);   // If the file doesn't exist, return false
  return false;
}*/
