#ifndef XYZCOORDINATE_HPP
#define XYZCOORDINATE_HPP
/// @file
/// \brief
/// Coordinate object.
/// \details
/// This object can store an x, y and z value, that can later be used and changed.
class XYZCoordinate {
public:
/// \brief
/// Constructor for an XYZCoordinate object with coordinates
/// \details
/// This is the constructor for an XYZCoordinate object.
/// It must receive an X, Y and Z coordinate which will be stored inside.
	XYZCoordinate(int16_t, int16_t, int16_t);
/// \brief
/// Constructor for an XYZCoordinate object without coordionates
/// \details
/// Whis is the constructor for an XYZCoordinate object.
/// It does not need an X, Y or Z coordinate. These can be inserted later on.
	XYZCoordinate();
/// \brief
/// X coordinate
/// \details
/// An X coordinate to be stored inside the XYZCoordinate object.
	int16_t x;
/// \brief
/// Y coordinate
/// \details
/// An Y coordinate to be stored inside the XYZCoordinate object.
	int16_t y;
/// \brief
/// Z coordinate
/// \details
/// An Z coordinate to be stored inside the XYZCoordinate object.
	int16_t z;
};

#endif // XYZCOORDINATE_HPP