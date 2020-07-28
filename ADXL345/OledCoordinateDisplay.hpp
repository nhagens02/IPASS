#ifndef OLEDCOORDINATEDISPLAY_HPP
#define OLEDCOORDINATEDISPLAY_HPP

#include "Oled.hpp"

class OledCoordinateDisplay {
private:
	Oled& display;
	adxl345lib::XYZCoordinate previousWrittenCoords[64];
	unsigned int gapPos;
	int dividerValue;
	adxl345lib::XYZCoordinate convertValueToOledCoord(adxl345lib::XYZCoordinate readCoords);
public:
	void printCoords(adxl345lib::XYZCoordinate rawCoords, int index);

	void printCoords(int rawX, int rawY, int rawZ, int index);

	OledCoordinateDisplay(Oled & display, int gapSize = 5, int dividerValue = 25);
};

#endif // OLEDCOORDINATEDISPLAY_HPP