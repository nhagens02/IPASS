#ifndef OLED_HPP
#define OLED_HPP

#include "adxl345lib/adxl345lib.hpp"

class Oled {
private:
	adxl345lib::I2cBus& bus;
	hwlib::glcd_oled_i2c_128x64_fast_buffered display;
public:
	Oled(adxl345lib::I2cBus& bus);

	void clear();

	void flush();

	void write(hwlib::xy writeValue, hwlib::color writingColor = hwlib::color(255, 255, 255));
};

#endif // OLED_HPP