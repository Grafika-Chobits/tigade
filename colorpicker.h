#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <math.h>
#include <stdlib.h>
#include "allstruct.h"
#include "video.h"
#include "cursor.h"

RGB getColorValue(unsigned short hue, unsigned char saturation, unsigned char luminosity);
void insertSprite(Frame* frm, Coord loc, unsigned short type);
void showHueSelector(Frame* frm, Coord loc, unsigned short hueLoc);
void showSlSelector(Frame* frm, Coord loc, unsigned short hue, unsigned char sat, unsigned char lum);
void showSelectedColor(Frame* frm, Coord loc, RGB color);
void addBlob(Frame* cnvs, Coord loc, RGB color);

#endif