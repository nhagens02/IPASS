#include "adxl345lib.hpp"

void adxl345lib::I2cBus::write(hwlib::i2c_bus & bus, uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	auto i2cWriting = bus.write(deviceAddress);
	i2cWriting.write(registerAddress);
	i2cWriting.write(value);
	char log[] = "Written value to device.";
	adxl345lib::Logging::writeToLog(log);
	adxl345lib::Logging::writeNewLine();
}

uint8_t adxl345lib::I2cBus::read(hwlib::i2c_bus & bus, uint8_t deviceAddress, uint8_t registerAddress){
	char log[] = "Read byte from device.";
	adxl345lib::Logging::writeToLog(log);
	adxl345lib::Logging::writeNewLine();
	bus.write(deviceAddress).write(registerAddress);
	uint8_t returnValue = bus.read(deviceAddress).read_byte();
	return returnValue;
}

void adxl345lib::I2cBus::write(uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	write(adxl345lib::I2cBus::rawBus, deviceAddress, registerAddress, value);
}

uint8_t adxl345lib::I2cBus::read(uint8_t deviceAddress, uint8_t registerAddress){
	return read(adxl345lib::I2cBus::rawBus, deviceAddress, registerAddress);
}

adxl345lib::I2cBus::I2cBus(uint8_t sclPort, uint8_t sclPin, uint8_t sdaPort, uint8_t sdaPin):
scl( hwlib::target::pin_oc(sclPort, sclPin) ),
sda( hwlib::target::pin_oc(sdaPort, sdaPin) ),
rawBus( hwlib::i2c_bus_bit_banged_scl_sda(scl, sda) )
{
	char log[] = "Succesfully created I2CBus object.";
	adxl345lib::Logging::writeToLog(log);
	adxl345lib::Logging::writeNewLine();
}