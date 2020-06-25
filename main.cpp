#include "hwlib.hpp"

using namespace std;


void write(hwlib::i2c_bus &i2c, int deviceAddress, int accelRegister, int value){
	auto i2c_writing = i2c.write(deviceAddress);
	i2c_writing.write(accelRegister);
	i2c_writing.write(value);
	return;
}

uint8_t * read(hwlib::i2c_bus &i2c, int deviceAddress, uint8_t registersToRead[6]){
	static uint8_t returnValues[6] = {};
	//uint8_t value;
	for(unsigned int i = 0; i < 6; i++){
	i2c.write(deviceAddress).write(registersToRead[i]);
    returnValues[i] =  i2c.read(deviceAddress).read_byte();
	}
	return returnValues;
}

uint16_t * combine(uint8_t uncombinedValues[6]){
	static uint16_t returnValues[3] = {};
	uint16_t valueToAdd;
	for(unsigned int i = 0; i < 3; i++){
		valueToAdd = 0;
		valueToAdd = valueToAdd || uncombinedValues[2*i];
		valueToAdd = valueToAdd << 8;
		valueToAdd = valueToAdd || uncombinedValues[2*i+1];
		returnValues[i] = valueToAdd;
	}
	return returnValues;
}

void loop(hwlib::i2c_bus &i2c, int deviceAddress, uint8_t registersToRead[6]){
	uint8_t * values;
	uint16_t * valuesCombined;
	unsigned int averageFactor = 10;
	uint16_t valuesToAverageX[averageFactor] = {};
	uint16_t valuesToAverageY[averageFactor] = {};
	uint16_t valuesToAverageZ[averageFactor] = {};
	uint16_t averageX;
	uint16_t averageY;
	uint16_t averageZ;
	uint16_t averageTotalX;
	uint16_t averageTotalY;
	uint16_t averageTotalZ;
	while(true){
		for(unsigned int i = 0; i < averageFactor; i++){
		//while(1){
			values = read(i2c, deviceAddress, registersToRead);
			valuesCombined = combine(values);
			valuesToAverageX[i] = valuesCombined[0];
			valuesToAverageY[i] = valuesCombined[1];
			valuesToAverageZ[i] = valuesCombined[2];
			averageTotalX =+ valuesCombined[0];
			averageTotalY =+ valuesCombined[1];
			averageTotalZ =+ valuesCombined[2];
			//hwlib::cout << "\n";
			//for(unsigned int i = 0; i < 3; i++){
			//hwlib::cout << values[i] << "\n";
			//}
			//hwlib::wait_ms(50);
		//}
		}
		//Calculate average of averageTotal.
		averageX = averageTotalX/averageFactor;
		averageY = averageTotalY/averageFactor;
		averageZ = averageTotalZ/averageFactor;
		hwlib::cout << values[0] << "\n";
		hwlib::cout << averageY << "\n";
		hwlib::cout << averageZ << "\n";
	}
}

int main(){
	//Kill the watchdog.
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	hwlib::wait_ms(100);
	
	namespace target = hwlib::target;
	
	auto scl = target::pin_oc(target::pins::scl);
	auto sda = target::pin_oc(target::pins::sda);
	
	auto i2c = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
	
	const int deviceAddress = 0x53;
	const int POWER_CTL = 0x2d;
	uint8_t DATAX0 = 0x32;
	uint8_t DATAX1 = 0x33;
	uint8_t DATAY0 = 0x34;
	uint8_t DATAY1 = 0x35;
	uint8_t DATAZ0 = 0x36;
	uint8_t DATAZ1 = 0x37;
	
	uint8_t registersToRead[6] = {DATAX0, DATAX1, DATAY0, DATAY1, DATAZ0, DATAZ1};
	
	write(i2c, deviceAddress, POWER_CTL, 0);
	write(i2c, deviceAddress, POWER_CTL, 16);
	write(i2c, deviceAddress, POWER_CTL, 8);
	
	loop(i2c, deviceAddress, registersToRead);
}