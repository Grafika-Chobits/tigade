#include "colorpicker.h"

//get RGB from HSL
RGB getColorValue(unsigned short hue, unsigned char saturation, unsigned char luminosity){
	RGB curH;
	float s,l;
	
	//get RGB from selected Hue
	if (hue < 128) {
		curH = rgb(255,2*hue,0);
	} else if (hue < 256) {
		curH = rgb(255-(2*hue),255,0);
	} else if (hue < 384) {
		curH = rgb(0,255,2*hue);
	} else if (hue < 512) {
		curH = rgb(0,255-(2*hue),255);
	} else if (hue < 640) {
		curH = rgb(2*hue,0,255);
	} else if (hue < 768) {
		curH = rgb(255,0,255-(2*hue));
	}
	
	//show RGB from SL selector
	s = (float)saturation/255;
	RGB curHS = rgb(curH.r+(255-curH.r)*s, 
					curH.g+(255-curH.g)*s, 
					curH.b+(255-curH.b)*s
					);
	l = (float)luminosity/255;
	RGB curHSL = rgb(curHS.r-(curHS.r)*l, 
					 curHS.g-(curHS.g)*l, 
					 curHS.b-(curHS.b)*l
					 );
	
	return curHSL;
}

// Sprite Controller
void insertSprite(Frame* frm, Coord loc, unsigned short type) {
	switch (type) {
		case 1 : { // the mouse sprite
			insertPixel(frm, loc, rgb(255,255,255));
			int i;
			for (i=5; i<10; i++) {
				insertPixel(frm, coord(loc.x-i, loc.y), rgb(0,0,0));
				insertPixel(frm, coord(loc.x+i, loc.y), rgb(0,0,0));
				insertPixel(frm, coord(loc.x, loc.y-i), rgb(0,0,0));
				insertPixel(frm, coord(loc.x, loc.y+i), rgb(0,0,0));
				
				insertPixel(frm, coord(loc.x-i, loc.y+1), rgb(255,255,255));
				insertPixel(frm, coord(loc.x-i, loc.y-1), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+i, loc.y+1), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+i, loc.y-1), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+1, loc.y-i), rgb(255,255,255));
				insertPixel(frm, coord(loc.x-1, loc.y-i), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+1, loc.y+i), rgb(255,255,255));
				insertPixel(frm, coord(loc.x-1, loc.y+i), rgb(255,255,255));
			}
		} break;
		case 2 : { // something?
			
		} break;
	}	
}

// Hue Selector
void showHueSelector(Frame* frm, Coord loc, unsigned short hueLoc) {
	int x,y;
	for ( y = 5; y < 45; y++ ) {
		for ( x = 0; x < 128; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(255,2*x,0));
		}
		for ( x = 128; x < 256; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(255-(2*x),255,0));
		}
		for ( x = 256; x < 384; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(0,255,2*x));
		}
		for ( x = 384; x < 512; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(0,255-(2*x),255));
		}
		for ( x = 512; x < 640; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(2*x,0,255));
		}
		for ( x = 640; x < 768; x++ ) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), rgb(255,0,255-(2*x)));
		}
	}
	
	//show border
	for (y=5; y<45; y++) {
		insertPixel(frm, coord(loc.x-1, loc.y+y), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+768, loc.y+y), rgb(255,255,255));
	}
	for (x=0; x<768; x++) {
		insertPixel(frm, coord(loc.x+x, loc.y+4), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+x, loc.y+45), rgb(255,255,255));
	}
	
	//show selected hue
	for (y=0; y<5;y++) {
		insertPixel(frm, coord(loc.x+hueLoc, loc.y+y), rgb(255,255,255));
		for (x=0; x<5-y; x++) {
			insertPixel(frm, coord(loc.x+hueLoc-x, loc.y+y), rgb(255,255,255));
			insertPixel(frm, coord(loc.x+hueLoc+x, loc.y+y), rgb(255,255,255));
		}
	}
	for (y=5; y<15;y++) {
		insertPixel(frm, coord(loc.x+hueLoc, loc.y+y), rgb(0,0,0));
	}
	for (y=45; y<50;y++) {
		insertPixel(frm, coord(loc.x+hueLoc, loc.y+y), rgb(255,255,255));
		for (x=0; x<y-44; x++) {
			insertPixel(frm, coord(loc.x+hueLoc-x, loc.y+y), rgb(255,255,255));
			insertPixel(frm, coord(loc.x+hueLoc+x, loc.y+y), rgb(255,255,255));
		}
	}
	for (y=35; y<45;y++) {
		insertPixel(frm, coord(loc.x+hueLoc, loc.y+y), rgb(0,0,0));
	}
}

// Saturation and Lightness Selector
void showSlSelector(Frame* frm, Coord loc, unsigned short hue, unsigned char sat, unsigned char lum) {
	RGB curH;
	int x, y;
	float s,l;
	
	//get RGB from selected Hue
	if (hue < 128) {
		curH = rgb(255,2*hue,0);
	} else if (hue < 256) {
		curH = rgb(255-(2*hue),255,0);
	} else if (hue < 384) {
		curH = rgb(0,255,2*hue);
	} else if (hue < 512) {
		curH = rgb(0,255-(2*hue),255);
	} else if (hue < 640) {
		curH = rgb(2*hue,0,255);
	} else if (hue < 768) {
		curH = rgb(255,0,255-(2*hue));
	}
	
	//show SL selector
	for ( y = 0; y < 256; y++ ) {
		s = (float)y/255;
		RGB curHS = rgb(curH.r+(255-curH.r)*s, 
						curH.g+(255-curH.g)*s, 
						curH.b+(255-curH.b)*s
						);
		for ( x = 0; x < 256; x++ ) {
			l = (float)x/255;
			RGB curHSL = rgb(curHS.r-(curHS.r)*l, 
							 curHS.g-(curHS.g)*l, 
							 curHS.b-(curHS.b)*l
							 );
			insertPixel(frm, coord(loc.x+x, loc.y+y), curHSL);
		}
	}
	
	//show border
	for (y=0; y<256; y++) {
		insertPixel(frm, coord(loc.x-1, loc.y+y), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+256, loc.y+y), rgb(255,255,255));
	}
	for (x=0; x<256; x++) {
		insertPixel(frm, coord(loc.x+x, loc.y-1), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+x, loc.y+256), rgb(255,255,255));
	}
	
	//show selected SL
	for (y=0; y<10;y++) {
		for (x=0; x<10; x++) {
			float euclidDistance = sqrt(pow(x,2)+pow(y,2));
			if((int)euclidDistance == 9){
				insertPixel(frm, coord(loc.x+lum-x, loc.y+sat+y), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+lum+x, loc.y+sat+y), rgb(255,255,255));
			}
			if((int)euclidDistance == 8){
				insertPixel(frm, coord(loc.x+lum-x, loc.y+sat+y), rgb(0,0,0));
				insertPixel(frm, coord(loc.x+lum+x, loc.y+sat+y), rgb(0,0,0));
			}
		}
	}
	for (y=-10; y<0;y++) {
		for (x=0; x<10; x++) {
			float euclidDistance = sqrt(pow(x,2)+pow(y,2));
			insertPixel(frm, coord(loc.x+lum-2, loc.y+sat), rgb(0,0,0));
			insertPixel(frm, coord(loc.x+lum, loc.y+sat-2), rgb(0,0,0));
			insertPixel(frm, coord(loc.x+lum, loc.y+sat+2), rgb(0,0,0));
			insertPixel(frm, coord(loc.x+lum+2, loc.y+sat), rgb(0,0,0));
			insertPixel(frm, coord(loc.x+lum-3, loc.y+sat), rgb(255,255,255));
			insertPixel(frm, coord(loc.x+lum, loc.y+sat-3), rgb(255,255,255));
			insertPixel(frm, coord(loc.x+lum, loc.y+sat+3), rgb(255,255,255));
			insertPixel(frm, coord(loc.x+lum+3, loc.y+sat), rgb(255,255,255));
			if((int)euclidDistance == 9){
				insertPixel(frm, coord(loc.x+lum-x, loc.y+sat+y), rgb(255,255,255));
				insertPixel(frm, coord(loc.x+lum+x, loc.y+sat+y), rgb(255,255,255));
			}
			if((int)euclidDistance == 8){
				insertPixel(frm, coord(loc.x+lum-x, loc.y+sat+y), rgb(0,0,0));
				insertPixel(frm, coord(loc.x+lum+x, loc.y+sat+y), rgb(0,0,0));
			}
		}
	}
}

//show selected color
void showSelectedColor(Frame* frm, Coord loc, RGB color) {
	int x, y;
	for (y=0; y<50;y++) {
		for (x=0; x<256; x++) {
			insertPixel(frm, coord(loc.x+x, loc.y+y), color);
		}
	}
	//show border
	for (y=0; y<50; y++) {
		insertPixel(frm, coord(loc.x-1, loc.y+y), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+256, loc.y+y), rgb(255,255,255));
	}
	for (x=0; x<256; x++) {
		insertPixel(frm, coord(loc.x+x, loc.y-1), rgb(255,255,255));
		insertPixel(frm, coord(loc.x+x, loc.y+50), rgb(255,255,255));
	}
}

void addBlob(Frame* cnvs, Coord loc, RGB color) {
	int x,y;
	for (y=-2; y<3;y++) {
		for (x=-2; x<3; x++) {
			if (!(abs(x)==2 && abs(y)==2)) {
				insertPixel(cnvs, coord(loc.x+x, loc.y+y), color);
			}
		}
	}
}

