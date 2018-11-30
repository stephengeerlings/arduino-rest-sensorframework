#include "hello_base.h"


HelloBase server_base;

void setup()
{
	println("Init Server Base");
	server_base.init();
	
	println("Start Server Base Update Loop");
}

void loop()
{
	server_base.update();
	 
}
