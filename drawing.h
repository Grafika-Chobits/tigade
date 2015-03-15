#ifndef DRAWING_H
#define DRAWING_H

#include "rotasi.h"
#include "plotting.h"
#include "allstruct.h"
#include "clip.h"
#include <unistd.h>
//~ #include <algorithm> 
#include <vector>
#include "clip3d.h"
#include <vector>
#include <unistd.h>
#include <stdio.h>

std::vector<Line> drawPeta(Frame *frame, Coord center, RGB color);
std::vector<Line> drawKapal(Frame *frm, Coord loc, RGB color);
std::vector<Line> drawKapalVertikal(Frame *frm,Coord loc,RGB color);
std::vector<Line> drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color);
void drawBalingBesar(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color);
void rotateBalingBesar(Frame *frm,Coord loc, RGB col ,int counter );
void drawSquare (Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);
void drawAmmunition(Frame *frame, Coord upperBoundPosition, int ammunitionWidth, int ammunitionLength, RGB color);
void drawPeluru(Frame *frame, Coord center, RGB color);
void drawPlane(Frame *frame, Coord position, RGB color);
void drawBird(Frame* frm, Coord loc,RGB color);
void drawExplosion(Frame *frame, Coord loc, int mult, RGB color);
void drawBomb(Frame *frame, Coord center, RGB color);
void drawShip(Frame *frame, Coord center, RGB color);
void drawFish(Frame  *frame, Coord center, RGB color);
vector<Coord> getBirdCoordinate(Coord center);
vector<Coord> getFishCoordinate(Coord center);
void colorFlood(Frame* frm,int x, int y,RGB color);
int isColorEqual(RGB color1, RGB color2);
void drawStickman(Frame* frm,Coord loc,int sel,RGB color,int counter);
void drawCannon(Frame* frm,Coord loc,RGB color);
void drawStickmanAndCannon(Frame *frame, Coord shipPosition, RGB color, int counter);
void animateBan(Frame *frm, Coord *loc, RGB color, float *bVel, float *bVelX);
void drawWalkingStickman(Frame *frame, Coord center, RGB color);
void drawParachute(Frame *frame, Coord center, RGB color, int size);
Coord lengthEndPoint(Coord startingPoint, int degree, int length);

void drawSquare (Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);
void drawFreeSquare(Frame *frm, Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah, RGB color);

void drawSquare(Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);
void drawBlock(Frame *frm, Block block, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color);

void drawITB(Frame *frm, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, RGB color);

#endif
