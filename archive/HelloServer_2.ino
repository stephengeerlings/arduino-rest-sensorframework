//
//
//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
//#include <Wire.h>
//#include <FS.h>
//#include <ArduinoJson.h>
//
//#include "hello_server_conf.h"
//
//#include "hello_function_mapper.h"
//#include "fake_sensor.h"
//
//
//const char* filename = "/hostnamefile.txt";
//
//const char* ssid = WIFI_SSID;
//const char* password = WIFI_PASSWD;
//
//ESP8266WebServer server(80);
//
//
//MySensor bla;
//
//
//void handleRoot() {
//  char* bla = "hello from esp8266!";
//  
//  server.send(200, "text/plain", bla);  
//}
//
//void handleNotFound(){
//  bool found = false;
//  String message = "Handle Not Found\n\n";
//  String temp_uri = server.uri();
//
//  String sensor = "";
//  String function = "";
//  Serial.print(temp_uri);
//  
//  int temp_slash_position = temp_uri.indexOf('/');
//
//  if(temp_slash_position == 0)
//  {
//    temp_uri = temp_uri.substring(1);
//    Serial.println("remove leading slash");
//  }
//  else
//  {
//    Serial.println("error leading slash");
//    server.send(404, "text/plain", message);
//    return;
//  }
//
//
//  
//  temp_slash_position = temp_uri.indexOf('/');
//  
//  if(temp_slash_position != -1)
//  {
//   
//    sensor = temp_uri.substring(0, temp_uri.indexOf('/'));
//    
//    function = temp_uri.substring(temp_uri.indexOf('/')+1);
//
//    
//    
//    
//    Serial.print("Sensor: ");
//    Serial.println(sensor);
//
//    Serial.print("function: ");
//    Serial.println(function);
//    
//  }
//  else
//  {
//    Serial.println("Error Sensor");
//    server.send(404, "text/plain", message);
//    return;
//  }
//
//  
//  message += "Sensor: " + sensor;
//  message += "\n";
//  message += "Function: " + function;
//  message += "\n";
//  
////  message += "\nMethod: ";
////  message += (server.method() == HTTP_GET)?"GET":"POST";
////  message += "\nArguments: ";
////  message += server.args();
////  message += "\n";
//
//  for (uint8_t i=0; i<server.args(); i++){
//    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//  }
//
//  if(found == true)
//  {
//    server.send(200, "text/plain", message);
//  }
//  else
//  {
//    server.send(404, "text/plain", message);
//  }
//
//  
//  
//
//}
//
//void handleChangeName(){
//
//  File f = SPIFFS.open(filename, "w");
//  
//  if (!f) {
//    Serial.println("file open failed");
//    server.send(200, "text/plain", "[F]\tname change unsuccesful");
//  }
//  else
//  {
//
//      f.println("shibby");
//      f.close();  //Close file
//      
//      MDNS.begin("shibby");
//      Serial.println("MDNS responder restarted");
//      server.send(200, "text/plain", "[T]\tname changed");
//  }  
//
//
//    
//
//  
//}
//
//void handleRead(){
//
//  char* read_value = bla.ReadMe();
//
//  Serial.print("Read respond: ");
//  
//  server.send(200, "text/plain", read_value);
//  
//  Serial.print("OK\n");
//  free(read_value);
//}
//
//
//void setup(void){
//
//
//  Serial.begin(115200);
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, password);
//  Serial.println("");
//
//  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  
//  Serial.println("");
//  Serial.print("Connected to ");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  //Initialize File System
//  if(SPIFFS.begin())
//  {
//    Serial.println("SPIFFS Initialize....ok");
//  }
//  else
//  {
//    Serial.println("SPIFFS Initialization...failed");
//  }
//
//  String our_name = MDNS_DEFAULT_NAME;
//
//  if(SPIFFS.exists(filename))
//  {
//    Serial.println("Opening file");
//    File f = SPIFFS.open(filename, "r");
//  
//    if (!f) {
//      Serial.println("file open failed");
//    }
//    else
//    {
//      Serial.println("Reading Data from File:");
//      String line = f.readStringUntil('\n');
//
//      Serial.println(line);
//
//      f.close();
//      our_name = line;
//
//    }
//    
//  }
//  else{
//
//    Serial.println("Hostname File does not exist");
//  }
//  
//  if (MDNS.begin(our_name.c_str())) { 
//    Serial.print(our_name);
//    Serial.println(" : MDNS responder started");
//    
//  }
//
//  bla = MySensor();
//
//  Serial.print("Read Sensor:"); 
//  char* msg = bla.ReadMe();
//  Serial.println(msg);
//  
//  free(msg);
//  Serial.print("OK\n");
//
//  server.on("/", handleRoot);
//
//  server.on("/rename", handleChangeName);
//  
//  server.on("/read", handleRead);
//  
//  server.onNotFound(handleNotFound);
//
//  server.begin();
//  Serial.println("HTTP server started");
//}
//
//void loop(void){
//  server.handleClient();
//
//
//  
//  delay(200);
//  
//}
//
//void handleChangeName(){
//
//  File f = SPIFFS.open(filename, "w");
//  
//  if (!f) {
//    Serial.println("file open failed");
//    server.send(200, "text/plain", "[F]\tname change unsuccesful");
//  }
//  else
//  {
//
//      f.println("shibby");
//      f.close();  //Close file
//      
//      MDNS.begin("shibby");
//      Serial.println("MDNS responder restarted");
//      server.send(200, "text/plain", "[T]\tname changed");
//  }  
//
//
//    
//
//  
//}
//
//void handleRead(){
//
//  char* read_value = bla.ReadMe();
//
//  Serial.print("Read respond: ");
//  
//  server.send(200, "text/plain", read_value);
//  
//  Serial.print("OK\n");
//  free(read_value);
//}
//
//

