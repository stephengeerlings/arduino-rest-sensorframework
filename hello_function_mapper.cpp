
#include "hello_server_conf.h"
#include "hello_function_mapper.h"

#include <stdlib.h>
#include <string.h>

int HelloFunctionMapper::MapFunction(char* url, void* func)
{
	HelloFunctionMapping new_mapping = HelloFunctionMapping();
	strcpy( new_mapping.url, url);
	new_mapping.function = func;
	
	if( this->hello_map_size < MAX_FUNCTION_MAPPINGS)
	{
		this->hello_map[this->hello_map_size] = new_mapping;
		this->hello_map_size++;
	
		return GENERIC_SUCCESS;
	}
	else{
		return GENERIC_FAILURE;
	}
	
	return GENERIC_FAILURE;
	
}

int HelloFunctionMapper::FindFunction(char* url, void* func)
{
  int i=0;
	void* some_function;
	bool found = false;

  for(i=0; i<this->hello_map_size; i++)
  {
    if(strcmp(this->hello_map[i].url, url) == 0)
    {
      found = true;
      some_function = this->hello_map[i].function;    
    }
  }

  
	if(found == true)
	{
		func = some_function;
		return GENERIC_SUCCESS;
	}
	else
	{
		return GENERIC_FAILURE;
	}
	
	return GENERIC_FAILURE;
	
}

int HelloFunctionMapper::ShowFunctions(char* result)
{
  int i = 0;
  int result_buffer_write_index = 0;
  
  char* result_buffer = (char*) malloc(this->hello_map_size*(HELLO_FUNC_NAME_CHAR_LIMIT+2)*sizeof(char));

  
  for(i=0; i<this->hello_map_size; i++){
	strcpy(&result_buffer[result_buffer_write_index], hello_map[i].url);
    
	result_buffer_write_index += strlen(hello_map[i].url);
	
	
	if(i < this->hello_map_size-1){
		result_buffer[result_buffer_write_index++] = ',';
		result_buffer[result_buffer_write_index++] = ' ';
	}
	else
	{
		result_buffer[result_buffer_write_index++] = '\0';
	}
	
  }
  strcpy(result, result_buffer);
  free(result_buffer);
  
  return 0;
}

