#include "hello_base.h"

#define BUILDING_ON_ARDUINO

HelloBase *HelloBase::this_hellobase_instance = 0;


ESP8266WebServer *HelloBase::this_webserver_instance = 0;


void setup()
{
  Serial.begin(115200);
  
  Serial.println("Init Server Base");
  HelloBase::get_hellobase_instance()->init();
  
  Serial.println("Start Server Base Update Loop");
}

void loop()
{
  HelloBase::get_hellobase_instance()->update_server();
   
}
