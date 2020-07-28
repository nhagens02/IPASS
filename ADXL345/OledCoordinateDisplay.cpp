#include "OledCoordinateDisplay.hpp"

adxl345lib::XYZCoordinate OledCoordinateDisplay::convertValueToOledCoord(adxl345lib::XYZCoordinate readCoords) {
	adxl345lib::XYZCoordinate returnValue;
	returnValue.x = readCoords.x / dividerValue;
	returnValue.y = readCoords.y / dividerValue;
	returnValue.z = readCoords.z / dividerValue;
	return returnValue;
}

void OledCoordinateDisplay::printCoords(adxl345lib::XYZCoordinate rawCoords, int index) {
	adxl345lib::XYZCoordinate coordsToPrint = convertValueToOledCoord(rawCoords);
	if (gapPos >= 63) {
		gapPos = 0;
	}
	else {
		gapPos++;
	}

	display.write(hwlib::xy(previousWrittenCoords[gapPos].x, gapPos), hwlib::color(0, 0, 0));
	display.write(hwlib::xy(coordsToPrint.x + 86 + 21, index));

	display.write(hwlib::xy(previousWrittenCoords[gapPos].y, gapPos), hwlib::color(0, 0, 0));
	display.write(hwlib::xy(coordsToPrint.y + 43 + 21, index));

	display.write(hwlib::xy(previousWrittenCoords[gapPos].z, gapPos), hwlib::color(0, 0, 0));
	display.write(hwlib::xy(coordsToPrint.z + 21, index));

	display.flush();
	previousWrittenCoords[index].x = coordsToPrint.x + 86 + 21;
	previousWrittenCoords[index].y = coordsToPrint.y + 43 + 21;
	previousWrittenCoords[index].z = coordsToPrint.z + 21;
}
void OledCoordinateDisplay::printCoords(int rawX, int rawY, int rawZ, int index) {
	printCoords(adxl345lib::XYZCoordinate(rawX, rawY, rawZ), index);
}
OledCoordinateDisplay::OledCoordinateDisplay(Oled& display, int gapSize, int dividerValue) :
	display(display),
	gapPos(gapSize),
	dividerValue(dividerValue)
{
	display.clear();
	display.flush();
	for (unsigned int i = 0; i < 64; i++) {
		previousWrittenCoords[i] = adxl345lib::XYZCoordinate(0, 0, 0);
	}
}