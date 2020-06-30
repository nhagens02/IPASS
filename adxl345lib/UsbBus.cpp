#include "adxl345lib.hpp"

bool UsbBus::isFirstOutput = true;

void UsbBus::waitForInput(){
	char uselessInput;
	hwlib::cin >> uselessInput;
}

void UsbBus::sendDataToHost(int input){
	hwlib::cout << input;
}

void UsbBus::sendDataToHost(char input[50]){
	hwlib::cout << input;
}