


#include "hello_base.h"

#include "hello_server_conf.h"
#include "hello_function_mapper.h"
#include "hello_function_mapping.h"




const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWD;

const char* filename = "/hostnamefile.txt";




int HelloBase::init()
{
	this->main_loop_alive = true;

  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  //Initialize File System
  if(SPIFFS.begin())
  {
    Serial.println("SPIFFS Initialize....ok");
  }
  else
  {
    Serial.println("SPIFFS Initialization...failed");
  }


  //this->server.on("/", this->url_handle_root);
  this->get_webserver_instance()->on("/", url_handle_root);
//  
//  
  this->get_webserver_instance()->onNotFound(url_handle_not_found);

  
  this->get_webserver_instance()->begin();
//  
  Serial.println("HTTP server started");
	
	return 0;
}






int HelloBase::load_configuration()
{
  
  
  return 0;
}



int HelloBase::store_configuration()
{
  
  
  return 0;
}


/**
* Loads default configuration into flash, should only be used after flashing.
*/
int HelloBase::load_default_configuration()
{
  
  
  return 0;
}

/**
* Stores default configuration into flash, should only be used after flashing.
*   Can only store if base server is in the right mode.
*/
int HelloBase::store_default_configuration()
{
  
  
  return 0;
}



int HelloBase::update_server()
{
  
	this->get_webserver_instance()->handleClient();
  Serial.print("#");
  if( this->m_value < SERIAL_HEARTBEAT_INTERVAL)
  {
    this->m_value++;
  }
  else
  {
    this->m_value = 0;
    Serial.print("\n#");
    
  }
  delay(SERVER_UPDATE_DELAY_MILLIS);
	return 0;
 
}




void url_handle_root() {
  char* bla = "hello from esp8266!";
  ESP8266WebServer* server = HelloBase::get_webserver_instance();
  
  server->send(200, "text/plain", bla);  
}



void url_handle_not_found(){
  bool found = false;
  ESP8266WebServer* server = HelloBase::get_webserver_instance();

  String sensor = "";
  String function = "";
  
  String message = "Handle Not Found\n\n";
  String temp_uri = server->uri();


  Serial.println(temp_uri+"\n");
  


  
  int temp_slash_position = temp_uri.indexOf('/');

  if(temp_slash_position == 0)
  {
    temp_uri = temp_uri.substring(1);
    //Serial.println("remove leading slash");
  }
  else
  {
    //Serial.println("error leading slash");
    server->send(404, "text/plain", message);
    return;
  }


  
  temp_slash_position = temp_uri.indexOf('/');
  
  if(temp_slash_position != -1)
  {
    sensor = temp_uri.substring(0, temp_uri.indexOf('/'));
    function = temp_uri.substring(temp_uri.indexOf('/')+1);
  }
  else
  {
    Serial.println("Error Sensor");
    server->send(404, "text/plain", message);
    return;
  }

  
  message += "Sensor: " + sensor;
  message += "\n";
  message += "Function: " + function;
  message += "\n";
  
  message += "\nMethod: ";
  message += (server->method() == HTTP_GET)?"GET":"POST/OTHER";
  message += "\nArguments: ";
  message += server->args();
  message += "\n";

  for (uint8_t i=0; i<server->args(); i++){
    message += " " + server->argName(i) + ": " + server->arg(i) + "\n";
  }

  if(found == true)
  {
    server->send(200, "text/plain", message);
  }
  else
  {
    server->send(404, "text/plain", message);
  }

}




