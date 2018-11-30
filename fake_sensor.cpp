#include "fake_sensor.h"

#include <iostream>   
#include <cstdlib> 
#include <string>
#include <stdio.h>
#include <string.h>



/**
char* MySensor::ReadMe()
{
  char* result = (char*) malloc(sizeof(char) * 100);
  int string_length = 0;

	 switch(this->th.Read()) {
    case 2:
      strcpy(result, "CRC Failed");
    
      
      Serial.println(result);
      break;
    case 1:
      strcpy(result, "Sensor Oflline");
    
      Serial.println(result);
      break;
    case 0:
      Serial.print(th.h);
      Serial.print("\t");
      Serial.print(th.t);
      Serial.print("\t");
      
      
    
      
      string_length = sprintf(result, "Temp: %f Humidity: %f", this->th.t, this->th.h);
      
      Serial.println(string_length);
      break;
  }
  
	return result;
	
}*/

char* MySensor::HelpMe()
{
  char* result = (char*) malloc(sizeof(char) * 100);
  strcpy(result, "FakeSensor help");
  
  return result;
  
}



