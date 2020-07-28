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
	isLoggingEnabled(false);
	auto oledVcc = hwlib::target::pin_out(1, 14);
	oledVcc.write(1);
	adxl345lib::I2cBus adxlBus;
	adxl345lib::Adxl345 adxl(adxlBus);

	adxl345lib::I2cBus oledBus(2, 12, 2, 14);
	Oled oledDisplay = Oled(oledBus);
	OledCoordinateDisplay coordinateDisplay(oledDisplay);

	const unsigned int readAmount = 32;
	adxl345lib::XYZCoordinate values[readAmount];
	unsigned int currentIndex = 0;
	while (true) {
		for (unsigned int i = 0; i < readAmount; i++) {
			values[i] = adxl.readXYZCoordinate();
		}
		int16_t* averages = calculateAverage(values, readAmount);
		adxl345lib::XYZCoordinate readCoords(averages[0], averages[1], averages[2]);
		coordinateDisplay.printCoords(readCoords, currentIndex);
		if (currentIndex >= 63) {
			currentIndex = 0;
		}
		else {
			currentIndex++;
		}
	}
}