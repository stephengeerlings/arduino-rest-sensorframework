
#include "hello_server_conf.h"
#include "hello_function_mapping.h"
#include "hello_function_mapper.h"

#include <string.h>
#include <stdio.h>
#include <iostream>

#define STRING_SUCCESS "[S]\t"
#define STRING_FAILURE "[F]\t"

HelloFunctionMapper subject;
	
	char fop_string0[] = "read";
	char fop_string1[] = "write";
	char fop_string2[] = "shibby";
	char fop_string3[] = "update";
	char fop_string4[] = "restart";
	char fop_string5[] = "status";

	
	


void read()
{
	std::cout << "This is a function";
	//return 0;
}

void write()
{
	std::cout << "This is a function";
	//return 0;
}
void shibby()
{
	std::cout << "This is a function";
	//return 0;
}
void update()
{
	std::cout << "This is a function";
	//return 0;
}
void restart()
{
	std::cout << "This is a function number2";
	//return 0;
}
void status()
{
	std::cout << "This is a function";
	//return 0;
}

int main (int argc, char *argv[]) 
{ 
	int result = 0;
	
	char show_functions_result[500];

	
	void* test_pointer0 = (void*) read;
	void* test_pointer1 = (void*) write;
	void* test_pointer2 = (void*) shibby;
	void* test_pointer3 = (void*) update;
	void* test_pointer4 = (void*) restart;
	void* test_pointer5 = (void*) status;
		
	result = subject.MapFunction(fop_string0, test_pointer0);
	result += subject.MapFunction(fop_string1, test_pointer1);
	result += subject.MapFunction(fop_string2, test_pointer2);
	result += subject.MapFunction(fop_string3, test_pointer3);
	result += subject.MapFunction(fop_string4, test_pointer4);
	result += subject.MapFunction(fop_string5, test_pointer5);
	
	if(result == 0)
	{
		std::cout << STRING_SUCCESS;
		std::cout << "Adding succesful\n";
		
	}
	else
	{
		std::cout << STRING_FAILURE;
		std::cout << "Adding failed\n";
		
	}
	
	void* retrieve_pointer;
	
	result = subject.FindFunction(fop_string2, &retrieve_pointer);
	 
	 
	if(result == 0)
	{
		std::cout << STRING_SUCCESS;		
		std::cout << "Retrieve succesful\n";
		
		if(test_pointer2 == retrieve_pointer)
		{
		
			std::cout << STRING_SUCCESS;		
			std::cout << "Pointers are the same\n";
			
		}
		else
		{
			std::cout << STRING_FAILURE;
			std::cout << "Pointers are not the same\n";		
		}
		
	}
	else
	{ 
		std::cout << STRING_FAILURE;
		std::cout << "Retrieve failed\n";	
	}

	
	result = subject.FindFunction(fop_string5, &retrieve_pointer);
	 
	 
	if(result == 0)
	{
		std::cout << STRING_SUCCESS;		
		std::cout << "Retrieve succesful\n";
		
		if(test_pointer2 == retrieve_pointer)
		{
		
			std::cout << STRING_SUCCESS;		
			std::cout << "Pointers are the same\n";
			
		}
		else
		{
			std::cout << STRING_FAILURE;
			std::cout << "Pointers are not the same\n";		
		}
		
	}
	else
	{ 
		std::cout << STRING_FAILURE;
		std::cout << "Retrieve failed\n";	
	}

	
	subject.ShowFunctions(show_functions_result);
	
	std::cout << show_functions_result;
	
	
	std::cout << "Test finished\n";

	return 0;
}

