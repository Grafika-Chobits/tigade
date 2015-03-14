#ifndef CLIP3D_H
#define CLIP3D_H

//http://electrofriends.com/source-codes/software-programs/c/graphics/c-program-to-implement-the-cohen-sutherland-line-clipping-algorithm/

#include <stdio.h>
#include <vector>
#include <math.h>
#include "allstruct.h"
#include "drawing.h"

const int TOP=4,BOTTOM=8,RIGHT=2,LEFT=1;

typedef int outcode;

Line line(int x1, int y1, int x2, int y2);

outcode compute(int x, int y , int xmin1, int ymin1, int xmin2, int ymin2, int xmax1, int ymax1, int xmax2, int ymax2);

std::vector<Line> cohen_sutherland(Frame *canvas, std::vector<Line> lines, int xmin1, int ymin1, int xmax1, int ymin2,
																			int xmin2, int ymax1, int xmax2, int ymax2);

void cohen_sutherland (Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color);

void cohen_sutherland (int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax);
#endif
