#include "hello_base.h"

#define BUILDING_ON_ARDUINO

HelloBase* g_hellobase = 0;


ESP8266WebServer* g_webserver = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println("Init Server Base");

  g_hellobase = new HelloBase();


  
  HelloBase::get_hellobase_instance()->init();
  
  Serial.println("Start Server Base Update Loop");
}

void loop()
{
  HelloBase::get_hellobase_instance()->update_server();
  
}
