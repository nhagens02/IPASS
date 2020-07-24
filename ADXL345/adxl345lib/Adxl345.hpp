#ifndef ADXL345_HPP
#define ADXL345_HPP
/// @file
/// \brief
/// Main ADXL345 control class
/// \details
/// This class controls the use of the ADXL345 accelerator chip.
/// The Adxl345 class uses a hwlib i2c class for communication with the real-world device.
class Adxl345 {
private:
	I2cBus & bus;
	uint8_t address;
	int16_t combineCoordinates(uint8_t, uint8_t);
	int16_t readValue(uint8_t, uint8_t);
public:
/// \brief
/// Constructor for an Adxl345 object.
/// \details
/// This is the constructor that will be used to create one Adxl345 object.
/// You may create more than one instance of this object, if that fits your project.
/// This constructor needs a bus it can use and an address that identifies the real-world ADXL345 chip.
	Adxl345(I2cBus&, uint8_t);
/// \brief
/// Read an X coordinate
/// \details
/// This is the function used for reading the X value of the ADXL345 chip.
/// The two register values are automatically merged together so they can be used instantly.
	int16_t readX();
/// \brief
/// Read an Y coordinate
/// \details
/// This is the function used for reading the Y value of the ADXL345 chip.
/// The two register values are automatically merged together so they can be used instantly.
	int16_t readY();
/// \brief
/// Read an Z coordinate
/// \details
/// This is the function used for reading the Z value of the ADXL345 chip.
/// The two register values are automatically merged together so they can be used instantly.
	int16_t readZ();
/// \brief
/// Function for automaticcaly reading all 3 axes
/// \details
/// This function reads all the 3 axes and conveniently puts them in a XYZcoordinate object so they will always stay together.
	XYZCoordinate readXYZCoordinate();
};

#endif // ADXL345_HPP