#include "adxl345lib/adxl345lib.hpp"
#include "OledCoordinateDisplay.hpp"

void isLoggingEnabled(bool status) {
	adxl345lib::Logging::isLoggingEnabled = status;
}

int16_t * calculateAverage(adxl345lib::XYZCoordinate values[], unsigned int valueAmount){
	int valueAmountSigned = valueAmount;
	int16_t xSum = 0;
	int16_t ySum = 0;
	int16_t zSum = 0;
	for(unsigned int i = 0; i < valueAmount; i++){
		xSum += values[i].x;
		ySum += values[i].y;
		zSum += values[i].z;
	}
	static int16_t returnValues[3] = {};
	returnValues[0] = xSum/valueAmountSigned;
	returnValues[1] = ySum/valueAmountSigned;
	returnValues[2] = zSum/valueAmountSigned;
	return returnValues;
}


int main(){

	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(1000);
	isLoggingEnabled(false);
	auto oledVcc = hwlib::target::pin_out(1, 14);
	oledVcc.write(1);
	auto ADXLVcc = hwlib::target::pin_out(1, 21);
	ADXLVcc.write(1);
	auto sclAdxl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sdaAdxl = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto adxlBus_ = hwlib::i2c_bus_bit_banged_scl_sda(sclAdxl, sdaAdxl);
	adxl345lib::I2cBus adxlBus(&adxlBus_);
	adxl345lib::Adxl345 adxl(adxlBus);
	auto sclOled = hwlib::target::pin_oc(hwlib::target::pins::d51);
	auto sdaOled = hwlib::target::pin_oc(hwlib::target::pins::d49);
	auto oledBus_ = hwlib::i2c_bus_bit_banged_scl_sda(sclOled, sdaOled);
	adxl345lib::I2cBus oledBus(&oledBus_);
	Oled oledDisplay = Oled(oledBus);
	OledCoordinateDisplay coordinateDisplay(oledDisplay);

	const unsigned int readAmount = 16;
	adxl345lib::XYZCoordinate values[readAmount];
	unsigned int currentIndex = 0;
	while (true) {
		for (unsigned int i = 0; i < readAmount; i++) {
			values[i] = adxl.readXYZCoordinate();
		}
		int16_t* averages = calculateAverage(values, readAmount);
		adxl345lib::XYZCoordinate readCoords(averages[0], averages[1], averages[2]);
		coordinateDisplay.printCoords(readCoords, currentIndex);
		isLoggingEnabled(false);
		adxl345lib::Logging::writeToLog(readCoords.x);
		adxl345lib::Logging::writeToLog(",");
		adxl345lib::Logging::writeToLog(readCoords.y);
		adxl345lib::Logging::writeToLog(",");
		adxl345lib::Logging::writeToLog(readCoords.z);
		adxl345lib::Logging::writeNewLine();
		isLoggingEnabled(false);
		if (currentIndex >= 63) {
			currentIndex = 0;
		}
		else {
			currentIndex++;
		}
	}
}