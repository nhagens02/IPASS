#ifndef I2CBUS_HPP
#define I2CBUS_HPP
/// @file
/// \brief
/// Class for I²C communication.
/// \details
/// This class handles the communication with the I²C bus.
/// It creates a hwlib I²C bus that will be used to write to and read from the bus.
class I2cBus {
private:
	hwlib::target::pin_oc scl;
	hwlib::target::pin_oc sda;
	void write(hwlib::i2c_bus&, uint8_t, uint8_t, uint8_t);
	uint8_t read(hwlib::i2c_bus&, uint8_t, uint8_t);
public:
/// \brief
/// The created hwlib i2c bus implementation.
/// \details
/// This is the raw i2c bus that can be used for other devices. Must be passed by reference.
	hwlib::i2c_bus_bit_banged_scl_sda rawBus;
/// \brief
/// Creates a I2cBus object
/// \details
/// This is the constructor used to make a I2cBus object.
/// The object returned is to be used for an Adxl345 object, so it knows what bus to communicate with.
	I2cBus(uint8_t = 1, uint8_t = 13, uint8_t = 1, uint8_t = 12);
/// \brief
/// Write function for writing to registers
/// \details
/// This is the write function used by the Adxl345 for setting the real-world ADXL345 up.
/// It is not recommended using this command by yourself unless you know what you're doing.
	void write(uint8_t, uint8_t, uint8_t);
/// \brief
/// Read function for reading a single byte
/// \details
/// This is the read function used by the Adxl345 for reading the X, Y and Z values from the corresponding registers.
/// It is not recommended using this command by yourself unless you know what you're doing.
	uint8_t read(uint8_t, uint8_t);
};

#endif // I2CBUS_HPP