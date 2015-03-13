#ifndef ADDEDSTRUCT_H
#define ADDEDSTRUCT_H

#define min(X,Y) (((X) < (Y)) ? (X) : (Y))
#define max(X,Y) (((X) > (Y)) ? (X) : (Y))
#define End(Line) Line.end
#define EndX(Line) Line.end.x
#define EndY(Line) Line.end.y
#define StartX(Line) Line.start.x
#define StartY(Line) Line.start.y

#define PI 3.14159265

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

/* SETTINGS ------------------------------------------------------------ */
#define screenXstart 250
#define screenX 1366
#define screenY 768
#define mouseSensitivity 1

/* TYPEDEFS ------------------------------------------------------------ */
//RGB color
typedef struct s_rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

//Frame of RGBs
typedef struct s_frame {
	RGB px[screenX][screenY];
} Frame;

//Coordinate System
typedef struct s_coord {
	int x;
	int y;
} Coord;

//Line System
typedef struct s_line {
	Coord start;
	Coord end;
} Line;

//The integrated frame buffer plus info struct.
typedef struct s_frameBuffer {
	char* ptr;
	int smemLen;
	int lineLen;
	int bpp;
} FrameBuffer;

Coord coord(int x, int y);
Line line(Coord start, Coord end);
unsigned char isInBound(Coord position, Coord corner1, Coord corner2);

#endif
