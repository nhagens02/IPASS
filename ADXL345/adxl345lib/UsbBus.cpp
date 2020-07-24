#include "adxl345lib.hpp"

void UsbBus::waitForInput(){
	char uselessInput;
	char pressEnter[] = "Press enter to continue.";
	Logging::writeToLog(pressEnter);
	Logging::writeNewLine();
	hwlib::cin >> uselessInput;
}

void UsbBus::sendDataToHost(int16_t input){
	hwlib::cout << input;
}

void UsbBus::sendDataToHost(char input[50]){
	hwlib::cout << input;
}

