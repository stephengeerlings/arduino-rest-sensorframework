
#include "hello_function_mapping.h"

#ifndef URL_DECODE_H

#define URL_DECODE_H

#define MIN_FUNCTION_MAPPINGS (0)
#define MAX_FUNCTION_MAPPINGS (10)



class HelloFunctionMapper
{
  public:
	int hello_map_size = MIN_FUNCTION_MAPPINGS;
	HelloFunctionMapping hello_map[MAX_FUNCTION_MAPPINGS];
    int MapFunction(char* url, void* func);
    int FindFunction(char* url, void* func);
    int ShowFunctions(char* result);
};



#endif
