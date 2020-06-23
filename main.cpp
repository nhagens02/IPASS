#include "hwlib.hpp"
#include <vector>

using namespace std;

uint8_t createWriteAddress(uint8_t deviceAddress){
	return ((deviceAddress << 1)+1);
}

bool write(hwlib::i2c_bus_bit_banged_scl_sda &i2c_bus, uint8_t deviceAddress, vector<uint8_t> registers, vector<uint8_t> values){
	//write values to corresponding registers. Designed for use with the ADXL345.
	if(! (registers.size() == values.size())){
		hwlib::cout << "Register list not as long as Values list!\n";
		return false;
	}else{
		uint8_t writeAddress = createWriteAddress(deviceAddress);
		for(uint8_t i = 0; i < registers.size(); i++){
			i2c_bus.i2c_primitives::write_start();
			
			//Writing address + write bit.
			i2c_bus.i2c_primitives::write(writeAddress);
			bool ack = i2c_bus.i2c_primitives::read_ack();
			if(!ack){
				hwlib::cout << "No ack after writing address! Aborting.\n";
				return false;
			}
			
			//Writing register number.
			i2c_bus.i2c_primitives::write(registers[i]);
			ack = i2c_bus.i2c_primitives::read_ack();
			if(!ack){
				hwlib::cout << "No ack after writing register address! Aborting.\n";
				return false;
			}
			
			//Writing value to put into register.
			i2c_bus.i2c_primitives::write(values[i]);
			ack = i2c_bus.i2c_primitives::read_ack();
			if(!ack){
				hwlib::cout << "No ack after writing value address! Aborting.\n";
				return false;
			}
			i2c_bus.i2c_primitives::write_stop();
		}
	}
	return true;
}

int main(){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto scl = target::pin_oc(target::pins::scl);
	auto sda = target::pin_oc(target::pins::sda);
	
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
	
	bool succes = write(i2c_bus, 0x53, {0x2d, 0x2d, 0x2d}, {0, 16, 8});
	hwlib::cout << succes << "\n";
	
}