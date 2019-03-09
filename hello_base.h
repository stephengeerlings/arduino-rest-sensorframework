
#ifndef HELLO_BASE_H
#define HELLO_BASE_H


#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <FS.h>



class HelloBase
{

  
  
  
  

  
  HelloBase(int v = 0)
    : m_value(v)
    , m_active(true)
  {  }

    
	public:
		bool m_active;

    static HelloBase* getInstance()
    {
      if (!this_hellobase_instance)
        this_hellobase_instance = new HelloBase;
      return this_hellobase_instance;
    }
    
    static ESP8266WebServer* getWebserver()
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

private:
  static HelloBase* m_instance;
  static ESP8266WebServer* m_webserver;
  int m_value; 
        

};



void url_handle_root(void);
void url_handle_not_found(void);


#endif // HELLO_BASE_H  
