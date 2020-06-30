#include "adxl345lib.hpp"

Adxl345::Adxl345(uint8_t address):
address( address )
{}

uint16_t Adxl345::combineCoordinates(uint8_t mostSignificant, uint8_t leastSignificant){
	uint16_t combinedValue = 0;
	combinedValue = mostSignificant*256+leastSignificant;
	return combinedValue;
}

uint16_t Adxl345::readValue(int leastSignificantReg, int mostSignificantReg){
	uint8_t leastSignificant = I2cBus::read(address, leastSignificantReg);
	uint8_t mostSignificant = I2cBus::read(address, mostSignificantReg);
	return Adxl345::combineCoordinates(mostSignificant, leastSignificant);
}

uint16_t Adxl345::readX(){
	return Adxl345::read(0x32, 0x33);
}

uint16_t Adxl345::readY(){
	return Adxl345::read(0x34, 0x35);
}

uint16_t Adxl345::readZ(){
	return Adxl345::read(0x36, 0x37);
}