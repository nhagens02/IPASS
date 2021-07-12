#include "Oled.hpp"

Oled::Oled(adxl345lib::I2cBus& bus) :
	bus(bus),
	display(hwlib::glcd_oled_i2c_128x64_fast_buffered(*bus.rawBus))
{}
void Oled::clear() {
	display.clear();
}

void Oled::flush() {
	display.flush();
}

void Oled::write(hwlib::xy writeValue, hwlib::color writingColor) {
	display.write(writeValue, writingColor);
}