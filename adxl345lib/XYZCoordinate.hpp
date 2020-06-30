/// @file

/// \brief
/// Coordinate object.
/// \details
/// This object can store an x, y and z value, that can later be used and changed.


#ifndef XYZCOORDINATE_HPP
#define XYZCOORDINATE_HPP

class XYZCoordinate {
public:
	XYZCoordinate(int, int, int);
	int x;
	int y;
	int z;
};

#endif // XYZCOORDINATE_HPP