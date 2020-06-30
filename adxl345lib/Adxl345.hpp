#ifndef ADXL345_HPP
#define ADXL345_HPP

class Adxl345 {
private:
	uint8_t address;
	uint16_t combineCoordinates(uint8_t, uint8_t);
	uint16_t readValue(int, int);
public:
	Adxl345(uint8_t address);
	uint16_t readX();
	uint16_t readY();
	uint16_t readZ();
};

#endif // ADXL345_HPP