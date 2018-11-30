
#ifndef HELLO_BASE_H

#define HELLO_BASE_H


class HelloBase{	
	public:
		bool main_loop_alive;
		
		int init();
		int update();
		int load_configuration();
		int store_configuration();
		int load_default_configuration();
		
	private:
		int current_mode;
		
		int store_default_configuration();
}

#endif // HELLO_BASE_H  
