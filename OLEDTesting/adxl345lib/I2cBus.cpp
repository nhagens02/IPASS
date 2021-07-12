#include "adxl345lib.hpp"

void adxl345lib::I2cBus::write(hwlib::i2c_bus* bus, uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	auto i2cWriting = bus->write(deviceAddress);
	i2cWriting.write(registerAddress);
	i2cWriting.write(value);
	adxl345lib::Logging::writeToLog("Written value to device.");
	adxl345lib::Logging::writeNewLine();
}

uint8_t adxl345lib::I2cBus::read(hwlib::i2c_bus* bus, uint8_t deviceAddress, uint8_t registerAddress){
	adxl345lib::Logging::writeToLog("Read byte from device.");
	adxl345lib::Logging::writeNewLine();
	bus->write(deviceAddress).write(registerAddress);
	uint8_t returnValue = bus->read(deviceAddress).read_byte();
	return returnValue;
}

void adxl345lib::I2cBus::write(uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	this->write(adxl345lib::I2cBus::rawBus, deviceAddress, registerAddress, value);
}

uint8_t adxl345lib::I2cBus::read(uint8_t deviceAddress, uint8_t registerAddress){
	return this->read(adxl345lib::I2cBus::rawBus, deviceAddress, registerAddress);
}

adxl345lib::I2cBus::I2cBus(hwlib::i2c_bus* bus)
{
	rawBus = bus;
	adxl345lib::Logging::writeToLog("Succesfully created I2CBus object.");
	adxl345lib::Logging::writeNewLine();
}