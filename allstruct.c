#include "allstruct.h"

/* MATH STUFF ---------------------------------------------------------- */
// construct coord
Coord coord(int x, int y) {
	Coord retval;
	
	retval.x = x;
	retval.y = y;
	
	return retval;
}

Coord3d coord3d(int x, int y, int z) {
	Coord3d retval;
	
	retval.x = x;
	retval.y = y;
	retval.z = z;
	
	return retval;
}


Line line(Coord start, Coord end) {
	Line retval;
	retval.start = start;
	retval.end = end;
	return retval;
}

Block block(Coord3d _origin, int _length, int _width, int _height){
	Block retval;
	
	retval.origin = _origin;
	
	retval.length = _length;
	retval.width = _width;
	retval.height = _height;
	
	return retval;
}

std::vector<Line> perspectiveProjection(Block block, Coord3d cameraPosition){
	std::vector<Coord3d> threeDimensionalCoordinates = createBlockCoordinates(block);
	std::vector<Coord3d> transformedCoordinates = perspectiveTransformation(threeDimensionalCoordinates, cameraPosition);
	std::vector<Coord> twoDimensionalCoordinates = worldToScreenCoordinates(transformedCoordinates, cameraPosition);
	std::vector<Line> blockLines = createBlockLines(twoDimensionalCoordinates);
	
	return blockLines;	
}

std::vector<Coord3d> perspectiveTransformation(std::vector<Coord3d> threeDimensionalCoordinates, Coord3d cameraPosition){
	std::vector<Coord3d> transformedCoordinates;
	
	for(int i = 0; i < threeDimensionalCoordinates.size(); i++){
		int x = threeDimensionalCoordinates.at(i).x - cameraPosition.x;
		int y = threeDimensionalCoordinates.at(i).y - cameraPosition.y;
		int z = threeDimensionalCoordinates.at(i).z - cameraPosition.z;
		transformedCoordinates.push_back(coord3d(x, y, z));
	}
	
	return transformedCoordinates;
}

std::vector<Coord3d> createBlockCoordinates(Block block){
	std::vector<Coord3d> threeDimensionalCoordinates;
	Coord3d origin = block.origin;
	int length = block.length;
	int width = block.width;
	int height = block.height;
	
	Coord3d a = coord3d(origin.x, origin.y, origin.z);
	Coord3d b = coord3d(origin.x + length, origin.y, origin.z);
	Coord3d c = coord3d(origin.x + length, origin.y + height, origin.z);
	Coord3d d = coord3d(origin.x, origin.y + height, origin.z);
	Coord3d e = coord3d(origin.x, origin.y, origin.z - width);
	Coord3d f = coord3d(origin.x + length, origin.y, origin.z - width);
	Coord3d g = coord3d(origin.x + length, origin.y + height, origin.z - width);
	Coord3d h = coord3d(origin.x, origin.y + height, origin.z - width);
	
	threeDimensionalCoordinates.push_back(a);
	threeDimensionalCoordinates.push_back(b);
	threeDimensionalCoordinates.push_back(c);
	threeDimensionalCoordinates.push_back(d);
	threeDimensionalCoordinates.push_back(e);
	threeDimensionalCoordinates.push_back(f);
	threeDimensionalCoordinates.push_back(g);
	threeDimensionalCoordinates.push_back(h);
	
	return threeDimensionalCoordinates;
}

std::vector<Coord> worldToScreenCoordinates(std::vector<Coord3d> threeDimensionalCoordinates, Coord3d cameraPosition){
	std::vector<Coord> twoDimensionalCoordinates;
	
	for(int i = 0; i < threeDimensionalCoordinates.size(); i++){
		int x, y;
		if(threeDimensionalCoordinates.at(i).z == 0){
			x = round(((double)threeDimensionalCoordinates.at(i).x) * (double)cameraPosition.z - (double)cameraPosition.x);
			y = -round(((double)threeDimensionalCoordinates.at(i).y) * (double)cameraPosition.z - (double)cameraPosition.y);
		}else{
			if(threeDimensionalCoordinates.at(i).z < 0){
				x = round(-((double)threeDimensionalCoordinates.at(i).x / (double)threeDimensionalCoordinates.at(i).z) * (double)cameraPosition.z - (double)cameraPosition.x);
				y = -round(-((double)threeDimensionalCoordinates.at(i).y / (double)threeDimensionalCoordinates.at(i).z) * (double)cameraPosition.z - (double)cameraPosition.y);
			}else{
				x = round(((double)threeDimensionalCoordinates.at(i).x / (double)threeDimensionalCoordinates.at(i).z) * (double)cameraPosition.z - (double)cameraPosition.x);
				y = -round(((double)threeDimensionalCoordinates.at(i).y / (double)threeDimensionalCoordinates.at(i).z) * (double)cameraPosition.z - (double)cameraPosition.y);
			}
		}
		twoDimensionalCoordinates.push_back(coord(x, y));
	}
	
	return twoDimensionalCoordinates;
}

std::vector<Line> createBlockLines(std::vector<Coord> twoDimensionalCoordinates){
	std::vector<Line> blockLines;
	
	blockLines.push_back(line(twoDimensionalCoordinates.at(0), twoDimensionalCoordinates.at(1)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(1), twoDimensionalCoordinates.at(2)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(2), twoDimensionalCoordinates.at(3)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(3), twoDimensionalCoordinates.at(0)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(4), twoDimensionalCoordinates.at(5)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(5), twoDimensionalCoordinates.at(6)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(6), twoDimensionalCoordinates.at(7)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(7), twoDimensionalCoordinates.at(4)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(0), twoDimensionalCoordinates.at(4)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(1), twoDimensionalCoordinates.at(5)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(2), twoDimensionalCoordinates.at(6)));
	blockLines.push_back(line(twoDimensionalCoordinates.at(3), twoDimensionalCoordinates.at(7)));

	return blockLines;
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


