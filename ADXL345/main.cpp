#include "adxl345lib/adxl345lib.hpp"
//#include "hwlib.hpp"

int16_t * calculateAverage(XYZCoordinate values[], unsigned int valueAmount){
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

void checkOrientation(Adxl345 chip){
	unsigned int readAmount = 10;
	XYZCoordinate values[readAmount];
	while(true){
		Logging::isLoggingEnabled = false;
		for(unsigned int i = 0; i < readAmount; i++){
			values[i] = chip.readXYZCoordinate();
		}
		Logging::isLoggingEnabled = true;
		int16_t * averages = calculateAverage(values, readAmount);
		if( averages[0] >= -255 and averages[0] < -240 and averages[1] > -20 and averages[1] < 0 and averages[2] > -25 and averages[2] < -5 ){
			char toWrite[] = "De chip staat rechtop en is niet omgedraaid.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else if( averages[0] > -5 and averages[0] < 10 and averages[1] > -270 and averages[1] < -255 ){
			char toWrite[] = "De chip staat rechtop en is een kwartslag naar rechts gedraaid.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else if( averages[0] > -5 and averages[0] < 10 and averages[2] > 240 and averages[2] < 255 ){
			char toWrite[] = "De chip ligt plat.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else if( averages[0] > 220 and averages[0] < 280 and averages[2] > -30 and averages[2] < 20 ){
			char toWrite[] = "De chip staat rechtop en ondersteboven.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else if( averages[1] > 250 and averages[1] < 256 and averages[2] > -15 and averages[2] < 0 ){
			char toWrite[] = "De chip staat rechtop en is een kwartslag naar links gedraaid.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else if( averages[0] > 0 and averages[0] < 10 and averages[2] > -265 and averages[2] < -250 ){
			char toWrite[] = "De chip ligt ondersteboven.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}else{
			char toWrite[] = "De chip weet het even niet.";
			Logging::writeToLog(toWrite);
			Logging::writeNewLine();
		}
		hwlib::wait_ms(1000);
	}
}

int main(){
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms(100);
	Logging::isLoggingEnabled = false;
	const uint8_t deviceAddress = 0x53;
	I2cBus bus;
	Adxl345 chip(bus, deviceAddress);
	chip.readXYZCoordinate();
	Logging::isLoggingEnabled = true;
	checkOrientation(chip);
}