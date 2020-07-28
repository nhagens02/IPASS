#include "adxl345lib.hpp"

adxl345lib::Adxl345::Adxl345(adxl345lib::I2cBus & bus, uint8_t address):
bus( bus ),
address( address )
{
	bus.write(address, 0x2d, 8); // To keep the chip on and working
	bus.write(address, 0x38, 40); // To enable the 32 stage register.
	char log[] = "Succesfully created Adxl345 object.";
	adxl345lib::Logging::writeToLog(log);
	adxl345lib::Logging::writeNewLine();
}

int16_t adxl345lib::Adxl345::combineCoordinates(uint8_t mostSignificant, uint8_t leastSignificant){
	int16_t combinedValue = 0;
	combinedValue = mostSignificant*256+leastSignificant;
	return combinedValue;
}

int16_t adxl345lib::Adxl345::readValue(uint8_t leastSignificantReg, uint8_t mostSignificantReg){
	uint8_t leastSignificant = bus.read(adxl345lib::Adxl345::address, leastSignificantReg);
	uint8_t mostSignificant = bus.read(adxl345lib::Adxl345::address, mostSignificantReg);
	return Adxl345::combineCoordinates(mostSignificant, leastSignificant);
}

int16_t adxl345lib::Adxl345::readX(){
	int16_t xValue = adxl345lib::Adxl345::readValue(0x32, 0x33);
	return xValue;
}

int16_t adxl345lib::Adxl345::readY(){
	int16_t yValue = adxl345lib::Adxl345::readValue(0x34, 0x35);
	return yValue;
}

int16_t adxl345lib::Adxl345::readZ(){
	int16_t zValue = adxl345lib::Adxl345::readValue(0x36, 0x37);
	return zValue;
}

adxl345lib::XYZCoordinate adxl345lib::Adxl345::readXYZCoordinate(){
	int16_t xCoordinate = readX();
	int16_t yCoordinate = readY();
	int16_t zCoordinate = readZ();
	return XYZCoordinate(xCoordinate, yCoordinate, zCoordinate);
}