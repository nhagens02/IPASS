#include "adxl345lib/adxl345lib.hpp"
//#include "hwlib.hpp"

int main(){
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(100);
	//I2cBus::createBus();
	//I2cBus::write(0x53, 0x2d, 0);
}