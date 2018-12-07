
#ifndef HELLO_BASE_H
#define HELLO_BASE_H


#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <FS.h>



class HelloBase
{
  int m_value;
  
  static HelloBase *this_hellobase_instance;
  static ESP8266WebServer *this_webserver_instance;
  
  HelloBase(int v = 0)
  {
    m_value = v;
  }

    
	public:
		bool main_loop_alive;

    static HelloBase* get_hellobase_instance()
    {
      if (!this_hellobase_instance)
        this_hellobase_instance = new HelloBase;
      return this_hellobase_instance;
    }
    
    static ESP8266WebServer* get_webserver_instance()
    {
        if (!this_webserver_instance)
          this_webserver_instance = new ESP8266WebServer;
        return this_webserver_instance;
    }
    

    int load_configuration();
    int store_configuration();
    int load_default_configuration();
    int store_default_configuration();

		int init();
		int update_server();

   
        

};



void url_handle_root(void);
void url_handle_not_found(void);


#endif // HELLO_BASE_H  
