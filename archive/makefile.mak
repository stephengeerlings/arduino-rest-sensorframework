CC = g++
CFLAGS =-I.-std=C11.-Wall.-c
LIBS =-lm

OBJECTS = hello_function_mapper.o hello_function_mapping.o hello_function_mapper_test.o
				
all : $(OBJECTS)
		$(CC) $(CFLAGS) -o hello_function_mapper $(OBJECTS)
		
hello_function_mapper_test : hello_function_mapper.o
		
hello_function_mapper : hello_function_mapping.o
		

		
	
.PHONY : clean
clean :
		rm -rvf run.out $(OBJECTS)