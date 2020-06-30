#include "adxl345lib.hpp"

bool Logging::isLoggingEnabled = true;

void Logging::writeToLog(char input[50]){
	if(Logging::isLoggingEnabled){
		char newLine[2] = "\n";
		UsbBus::sendDataToHost(input);
		UsbBus::sendDataToHost(newLine);
	}
}