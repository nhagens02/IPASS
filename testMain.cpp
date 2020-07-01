#include "adxl345lib/adxl345lib.hpp"
//#include "hwlib.hpp"

void loop(Adxl345 chip){
	unsigned int readAmount = 100;
	XYZCoordinate values[readAmount];
	while(true){
		Logging::isLoggingEnabled = false;
		for(unsigned int i = 0; i < readAmount; i++){
			values[i] = chip.readXYZCoordinate();
		}
		Logging::isLoggingEnabled = true;
		for(unsigned int i = 0; i < readAmount; i++){
			Logging::writeToLog(values[i].x);
			Logging::writeTab();
			Logging::writeToLog(values[i].y);
			Logging::writeTab();
			Logging::writeToLog(values[i].z);
			Logging::writeNewLine();
		}
		UsbBus::waitForInput();
	}
}

int main(){
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(100);
	Logging::isLoggingEnabled = false;
	const uint8_t deviceAddress = 0x53;
	I2cBus bus;
	Adxl345 chip(bus, deviceAddress);
	chip.readXYZCoordinate();
	Logging::isLoggingEnabled = true;
	loop(chip);
}