#include "adxl345lib.hpp"

bool adxl345lib::Logging::isLoggingEnabled = true;

void adxl345lib::Logging::writeToLog(const char input[50]){
	if(adxl345lib::Logging::isLoggingEnabled){
		adxl345lib::UsbBus::sendDataToHost(input);
	}
}

void adxl345lib::Logging::writeToLog(int16_t input){
	if(adxl345lib::Logging::isLoggingEnabled){
		adxl345lib::UsbBus::sendDataToHost(input);
	}
}

void adxl345lib::Logging::writeNewLine(){
	if(adxl345lib::Logging::isLoggingEnabled){
		char newLine[] = "\n";
		adxl345lib::UsbBus::sendDataToHost(newLine);
	}
}

void adxl345lib::Logging::writeTab(){
	if(adxl345lib::Logging::isLoggingEnabled){
		char tab[] = "\t";
		adxl345lib::UsbBus::sendDataToHost(tab);
	}
}