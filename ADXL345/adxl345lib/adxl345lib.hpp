#ifndef ADXL345LIB_HPP
#define ADXL345LIB_HPP
/// @file
/// \mainpage
/// Welcome to the adxl345lib documentation!
/// To find what you are looking for, check the 'classes' section.\n
/// If you are curious about the way this library is built, please check the 'files' section.
#include "hwlib.hpp"
namespace adxl345lib {
	#include "XYZCoordinate.hpp"
	#include "I2cBus.hpp"
	#include "Adxl345.hpp"
	#include "Logging.hpp"
	#include "UsbBus.hpp"
}
/// \brief
/// Main include file
/// \details
/// This is the main file to be included by the program.
/// This files includes all the neccesary files that are used by the library.
#endif // ADXL345LIB_HPP