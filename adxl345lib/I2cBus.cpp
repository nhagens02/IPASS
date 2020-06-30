#include "adxl345lib.hpp"

void I2cBus::createBus(){
	
	auto sclPin = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sdaPin = hwlib::target::pin_oc(hwlib::target::pins::sda);
	
//	if(sdaPinInt == 20){
//		sdaPin = hwlib::target::pin_oc(hwlib::target::pins::sda);
//	}
//	if(sclPinInt == 21){
//		sclPin = hwlib::target::pin_oc(hwlib::target::pins::sda);
//	}
	auto i2cBusHwLib = hwlib::i2c_bus_bit_banged_scl_sda(sclPin, sdaPin);
	
	//return hwlib::i2c_bus_bit_banged_scl_sda(sclPin, sdaPin);
}

void I2cBus::write(int deviceAddress, int registerAddress, int value){
//	hwlib::i2c_bus &i2c = i2cBusHwLib;
	auto i2cWriting = I2cBus::i2cBusHwLib::i2c_bus.write(deviceAddress);
	i2cWriting.write(registerAddress);
	i2cWriting.write(value);
}

uint8_t I2cBus::read(int deviceAddress, int registerAddress){
	hwlib::i2c_bus &i2c = I2cBus::i2cBusHwLib;
	i2c.write(deviceAddress).write(registerAddress);
	return i2c.read(deviceAddress).read_byte();
}