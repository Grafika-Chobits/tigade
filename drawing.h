#ifndef DRAWING_H
#define DRAWING_H

#include "rotasi.h"
#include "plotting.h"
#include "allstruct.h"
#include "clip.h"
#include <vector>
#include <unistd.h>

std::vector<Line> drawPeta(Frame *frame, Coord center, RGB color);
std::vector<Line> drawKapal(Frame *frm, Coord loc, RGB color);
std::vector<Line> drawKapalVertikal(Frame *frm,Coord loc,RGB color);
std::vector<Line> drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color);
std::vector<Line> rotateBaling(Frame *frm,Coord loc, RGB col ,int counter );
void drawSquare (Frame *frm, Coord kiriAtas, Coord KananBawah, RGB color);

#endif
