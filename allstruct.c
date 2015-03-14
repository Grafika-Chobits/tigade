#include "allstruct.h"

/* MATH STUFF ---------------------------------------------------------- */
// construct coord
Coord coord(int x, int y) {
	Coord retval;
	retval.x = x;
	retval.y = y;
	return retval;
}

Line line(Coord start, Coord end) {
	Line retval;
	retval.start = start;
	retval.end = end;
	return retval;
}

Balok balok(Coord _center, int _panjang, int _lebar, int _tinggi){
	Balok retval;
	retval.center.x = _center.x;
	retval.center.y = _center.y;
	retval.panjang = _panjang;
	retval.lebar = _lebar;
	retval.tinggi = _tinggi;
	return retval;
}

unsigned char isInBound(Coord position, Coord corner1, Coord corner2) {
	unsigned char xInBound = 0;
	unsigned char yInBound = 0;
	if (corner1.x < corner2.x) {
		xInBound = (position.x>corner1.x) && (position.x<corner2.x);
	} else if (corner1.x > corner2.x) {
		xInBound = (position.x>corner2.x) && (position.x<corner1.x);
	} else {
		return 0;
	}
	if (corner1.y < corner2.y) {
		yInBound = (position.y>corner1.y) && (position.y<corner2.y);
	} else if (corner1.y > corner2.y) {
		yInBound = (position.y>corner2.y) && (position.y<corner1.y);
	} else {
		return 0;
	}
	return xInBound&&yInBound;
}


