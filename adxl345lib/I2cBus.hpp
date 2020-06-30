#ifndef I2CBUS_HPP
#define I2CBUS_HPP

class I2cBus {
public:
	static hwlib::i2c_bus_bit_banged_scl_sda i2cBusHwLib;
	static void createBus();
	static void write(int, int, int);
	static uint8_t read(int, int);
};

#endif // I2CBUS_HPP