#include "hwlib.hpp"
#include "adxl345lib/adxl345lib.hpp"
#include "Oled.hpp"

int main() {
	hwlib::wait_ms(1000);
	hwlib::cout << "Works!\n";
	auto oledVcc = hwlib::target::pin_out(hwlib::target::pins::d53);
	oledVcc.write(1);
	adxl345lib::Logging::isLoggingEnabled = false;
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::d51);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::d49);
	auto bus_ = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	adxl345lib::I2cBus bus(&bus_);
	Oled oled(bus);
	for (int_fast16_t i = 10; i < 25; i++) {
		for (int_fast16_t j = 10; j < 25; j++) {
			oled.write({ j, i });
		}
	}
	oled.flush();
}