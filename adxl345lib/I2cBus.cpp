#include "adxl345lib.hpp"

void I2cBus::write(hwlib::i2c_bus & bus, uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	auto i2cWriting = bus.write(deviceAddress);
	i2cWriting.write(registerAddress);
	i2cWriting.write(value);
	char log[] = "Written value to device.";
	Logging::writeToLog(log);
	Logging::writeNewLine();
}

uint8_t I2cBus::read(hwlib::i2c_bus & bus, uint8_t deviceAddress, uint8_t registerAddress){
	char log[] = "Read byte from device.";
	Logging::writeToLog(log);
	Logging::writeNewLine();
	bus.write(deviceAddress).write(registerAddress);
	uint8_t returnValue = bus.read(deviceAddress).read_byte();
	return returnValue;
}

void I2cBus::write(uint8_t deviceAddress, uint8_t registerAddress, uint8_t value){
	write(I2cBus::i2cBusHwLib, deviceAddress, registerAddress, value);
}

uint8_t I2cBus::read(uint8_t deviceAddress, uint8_t registerAddress){
	return read(I2cBus::i2cBusHwLib, deviceAddress, registerAddress);
}

I2cBus::I2cBus():
sclPin( hwlib::target::pin_oc(hwlib::target::pins::scl) ),
sdaPin( hwlib::target::pin_oc(hwlib::target::pins::sda) ),
i2cBusHwLib( hwlib::i2c_bus_bit_banged_scl_sda(sclPin, sdaPin) )
{
	char log[] = "Succesfully created I2CBus object.";
	Logging::writeToLog(log);
	Logging::writeNewLine();
}