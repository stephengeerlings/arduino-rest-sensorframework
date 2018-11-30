#include "hello_base.h"
#include <iostream>

HelloBase server_base;


#define HELLO_BASE_SELF_TEST
/**
*	Perform some self test of the system.
*
*/
int main_self_test()
{
	
	return 0;
}


/**
*	Perform initial configuration of the system
*
*/
int main_init()
{
	
	return 0;
}

/**
*	Main function for standalone operation / non-arduino targets.
*
* 	Calls:
* 		main_init()
*		server_base.init()
*		main_self_test() 		(if HELLO_BASE_SELF_TEST is defined)
*		server_base.update() 	(loops during lifetime)
*
* 	Returns 0 on completion.
*/
int main(int argc, char *argv[])()
{

	main_init();

	std::cout << "Server Base Init\n";
	
	server_base.init();
	
	std::cout << "Server Base Start Update Loop\n";
	
#ifdef HELLO_BASE_SELF_TEST
	
	main_self_test();
	
#endif
	
	while(server_base.main_loop_alive)
	{
		server_base.update();
	}
	
	std::cout << "Server Base End Update Loop\n";
	
	return 0;
	
}

/**
* 	hello_main.cpp
* 	End
*/