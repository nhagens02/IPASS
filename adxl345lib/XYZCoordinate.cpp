#include "adxl345lib.hpp"

XYZCoordinate::XYZCoordinate(int16_t x, int16_t y, int16_t z):
x( x ),
y( y ),
z( z )
{}

XYZCoordinate::XYZCoordinate()
{}