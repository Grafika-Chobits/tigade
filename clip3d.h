#ifndef CLIP3D_H
#define CLIP3D_H

//http://electrofriends.com/source-codes/software-programs/c/graphics/c-program-to-implement-the-cohen-sutherland-line-clipping-algorithm/

#include <stdio.h>
#include <vector>
#include <math.h>
#include "allstruct.h"
#include "drawing.h"

//			8421
//TOP = 	0100
//BOTTOM = 	1000
//LEFT = 	0001
//RIGHT = 	0010

const int TOP=4,BOTTOM=8,RIGHT=2,LEFT=1,TOPRIGHT=6, BOTTOMRIGHT=10, BOTTOMLEFT = 9, TOPLEFT = 5;

typedef int outcode;

Line line(int x1, int y1, int x2, int y2);

outcode compute(int x, int y , Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah);

std::vector<Line> cohen_sutherland(Frame *canvas, std::vector<Line> lines, Coord kiriAtas, Coord kananAtas, 
																			Coord kiriBawah, Coord kananBawah, RGB color);
																			
std::vector<Line> cohen_sutherland(std::vector<Line> lines, Coord kiriAtas, Coord kananAtas, 
																			Coord kiriBawah, Coord kananBawah, RGB color);																	

void cohen_sutherland (Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color);

void cohen_sutherland (int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax);
#endif
