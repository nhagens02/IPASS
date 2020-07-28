#include "adxl345lib.hpp"

void adxl345lib::UsbBus::waitForInput(){
	char uselessInput;
	char pressEnter[] = "Press enter to continue.";
	adxl345lib::Logging::writeToLog(pressEnter);
	adxl345lib::Logging::writeNewLine();
	hwlib::cin >> uselessInput;
}

void adxl345lib::UsbBus::sendDataToHost(int16_t input){
	hwlib::cout << input;
}

void adxl345lib::UsbBus::sendDataToHost(char input[50]){
	hwlib::cout << input;
}

