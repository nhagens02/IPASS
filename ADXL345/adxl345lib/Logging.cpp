#include "adxl345lib.hpp"

bool Logging::isLoggingEnabled = true;

void Logging::writeToLog(char input[50]){
	if(Logging::isLoggingEnabled){
		UsbBus::sendDataToHost(input);
	}
}

void Logging::writeToLog(int16_t input){
	if(Logging::isLoggingEnabled){
		UsbBus::sendDataToHost(input);
	}
}

void Logging::writeToLog(int input){
	if(Logging::isLoggingEnabled){
		UsbBus::sendDataToHost(input);
	}
}

void Logging::writeNewLine(){
	if(Logging::isLoggingEnabled){
		char newLine[] = "\n";
		UsbBus::sendDataToHost(newLine);
	}
}

void Logging::writeTab(){
	if(Logging::isLoggingEnabled){
		char tab[] = "\t";
		UsbBus::sendDataToHost(tab);
	}
}