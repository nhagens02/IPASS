#include "adxl345lib.hpp"
#include "Adxl345.hpp"

Adxl345::Adxl345(I2cBus & bus, uint8_t address):
bus( bus ),
address( address )
{
	bus.write(address, 0x2d, 8);
	char log[] = "Succesfully created Adxl345 object.";
	Logging::writeToLog(log);
	Logging::writeNewLine();
}

int16_t Adxl345::combineCoordinates(uint8_t mostSignificant, uint8_t leastSignificant){
	int16_t combinedValue = 0;
	combinedValue = mostSignificant*256+leastSignificant;
	return combinedValue;
}

int16_t Adxl345::readValue(uint8_t leastSignificantReg, uint8_t mostSignificantReg){
	uint8_t leastSignificant = bus.read(Adxl345::address, leastSignificantReg);
	hwlib::wait_ms(10);
	uint8_t mostSignificant = bus.read(Adxl345::address, mostSignificantReg);
	hwlib::wait_ms(10);
	return Adxl345::combineCoordinates(mostSignificant, leastSignificant);
}

int16_t Adxl345::readX(){
	int16_t xValue = Adxl345::readValue(0x32, 0x33);
	return xValue;
}

int16_t Adxl345::readY(){
	int16_t yValue = Adxl345::readValue(0x34, 0x35);
	return yValue;
}

int16_t Adxl345::readZ(){
	int16_t zValue = Adxl345::readValue(0x36, 0x37);
	return zValue;
}

XYZCoordinate Adxl345::readXYZCoordinate(){
	int16_t xCoordinate = readX();
	int16_t yCoordinate = readY();
	int16_t zCoordinate = readZ();
	return XYZCoordinate(xCoordinate, yCoordinate, zCoordinate);
}