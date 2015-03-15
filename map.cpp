#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include "allstruct.h"
#include "video.h"
#include "plotting.h"
#include "rotasi.h"
#include "drawing.h"
#include "clip.h"
#include <pthread.h>

using namespace std;

/* FUNCTIONS FOR SCANLINE ALGORITHM ---------------------------------------------------- */

bool isSlopeEqualsZero(int y0, int y1){
	if(y0 == y1){
		return true;
	}else{
		return false;
	}
}

bool isInBetween(int y0, int y1, int yTest){
	if((yTest >= y0 && yTest <= y1 || yTest >= y1 && yTest <= y0) && !isSlopeEqualsZero(y0, y1)){
		return true;
	}else{
		return false;
	}
}

/* Function to calculate intersection between line (a,b) and line with slope 0 */
Coord intersection(Coord a, Coord b, int y){
	int x;
	double slope;
	
	if(b.x == a.x){
		x = a.x;
	}else{
		slope = (double)(b.y - a.y) / (double)(b.x - a.x);
		x = round(((double)(y - a.y) / slope) + (double)a.x);
	}
	
	return coord(x, y);
}

bool compareByAxis(const s_coord &a, const s_coord &b){
	return a.x <= b.x;
}

bool compareSameAxis(const s_coord &a, const s_coord &b){
	return a.x == b.x;
}

bool operator==(const Coord& lhs, const Coord& rhs) {
	if(lhs.x==rhs.x && lhs.y==rhs.y)
		return true;
	return false;
}

bool isLocalMaxima(const Coord& a, const Coord& b, const Coord& titikPotong) {
	return ((titikPotong.y<a.y && titikPotong.y<b.y) || (titikPotong.y>a.y && titikPotong.y>b.y));
}

vector<Coord> intersectionGenerator(int y, vector<Coord> polygon){
	vector<Coord> intersectionPoint;
	Coord prevTipot = coord(-9999,-9999);
	for(int i = 0; i < polygon.size(); i++){
		if(i == polygon.size() - 1){
			if(isInBetween(polygon.at(i).y, polygon.at(0).y, y)){				
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(0).x, polygon.at(0).y);
						
				Coord titikPotong = intersection(a, b, y);

				if(titikPotong==b){
					if(isLocalMaxima(polygon.at(i), polygon.at(1), titikPotong))
						intersectionPoint.push_back(titikPotong);
				}
				else {
					if(prevTipot==titikPotong){
						if(isLocalMaxima(polygon.at(i-1), polygon.at(0), titikPotong))
							intersectionPoint.push_back(titikPotong);
					}
					else
						intersectionPoint.push_back(titikPotong);
				}
			}
		}else{
			if(isInBetween(polygon.at(i).y, polygon.at(i + 1).y, y)){
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(i + 1).x, polygon.at(i + 1).y);
				
				Coord titikPotong = intersection(a, b, y);

				// Jika sama dgn tipot sebelumnya, cek apakah local minima/maxima
				if(titikPotong==prevTipot) {
					Coord z = coord(polygon.at(i-1).x, polygon.at(i-1).y);
					if(isLocalMaxima(z, b, titikPotong)) {
						intersectionPoint.push_back(titikPotong);
					}
				}
				else {
					intersectionPoint.push_back(titikPotong);
				}
				prevTipot = intersectionPoint.back();
			}
		}
	}
	
	sort(intersectionPoint.begin(), intersectionPoint.end(), compareByAxis);
	
	return intersectionPoint;
}
vector<Coord> combineIntersection(vector<Coord> a, vector<Coord> b){
	for(int i = 0; i < b.size(); i++){
		a.push_back(b.at(i));
	}
	
	sort(a.begin(), a.end(), compareByAxis);
	
	return a;
}

void fillShape(Frame *frame, int xOffset, int yOffset, int startY, int shapeHeight, std::vector<Coord> shapeCoord, RGB color) {
	for(int i = startY; i <= shapeHeight; i++){
		vector<Coord> shapeIntersectionPoint = intersectionGenerator(i, shapeCoord);	
		for(int j = 0; j < shapeIntersectionPoint.size() - 1; j++){
			if(j % 2 == 0){
				int x0 = shapeIntersectionPoint.at(j).x + xOffset;
				int y0 = shapeIntersectionPoint.at(j).y + yOffset;
				int x1 = shapeIntersectionPoint.at(j + 1).x + xOffset;
				int y1 = shapeIntersectionPoint.at(j + 1).y + yOffset;
				
				plotLine(frame, x0, y0, x1, y1, color);
			}
		}		
	}
}

//origin, pojok kiri atas viewPort
void viewPort(Frame *frame, Coord origin, int viewportSize, int windowSize, std::vector<Line> originalLines){
	// viewport frame
	plotLine(frame, origin.x, origin.y, origin.x + viewportSize, origin.y, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y, origin.x, origin.y + viewportSize, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y + viewportSize, origin.x + viewportSize, origin.y + viewportSize, rgb(255,255,255));
	plotLine(frame, origin.x + viewportSize, origin.y, origin.x + viewportSize, origin.y + viewportSize, rgb(255,255,255));
	
	// transform line, then draw
	std::vector<Line> transformedLines;
	for(int i = 0; i < originalLines.size(); i++){
		int startX = int((double)originalLines.at(i).start.x * (double)viewportSize / (double)windowSize) + origin.x;
		int startY = int((double)originalLines.at(i).start.y * (double)viewportSize / (double)windowSize) + origin.y;
		int endX = int((double)originalLines.at(i).end.x * (double)viewportSize / (double)windowSize) + origin.x;
		int endY = int((double)originalLines.at(i).end.y * (double)viewportSize / (double)windowSize) + origin.y;
		transformedLines.push_back(line(coord(startX, startY), coord(endX, endY)));
		plotLine(frame, transformedLines.at(i), rgb(50, 150, 0));
	}
}

void animateExplosion(Frame* frame, int explosionMul, Coord loc){
	int explosionR, explosionG, explosionB;
	explosionR = explosionG = explosionB = 255-explosionMul*12;	
	if(explosionR <= 0 || explosionG <= 0 || explosionB <= 0){
		explosionR = explosionG = explosionB = 0;
	}
	drawExplosion(frame, loc, explosionMul, rgb(explosionR, 0, 0));
}

/* GLOBALVAR DECLARATIONS ----------------------------------------------- */
 
Coord windowLocation = coord(500, 300);
int windowSize = 100;
int running = 1;
int xPlode = 0;
Coord xPlodeLocation = coord(0,0);


/* VIEW CONTROLLER ------------------------------------------------- */
void *threadFunc(void *arg)
{
	FILE *fmouse;
    char b[3];
	fmouse = fopen("/dev/input/mice","r");
    while(1){
                fread(b,sizeof(char),3,fmouse);
                if ((b[0]&1)>0) { //leftbutton
					windowSize += 20;
				}
				if ((b[0]&2)>0) { //rightbutton
					if (windowSize>0) {
						windowSize -= 20;
					}
				}
				if ((b[0]&4)>0) { //mmb
					xPlode = 1;
				}
				
				windowLocation = coord(windowLocation.x+b[1],windowLocation.y-b[2]);
        }
        fclose(fmouse);
	return NULL;
}

//fadeOut 
void fadeOut (Frame *frm, int lvl){
	for (int y = 0; y < 600; y++ ){
    for (int x = 0; x < 1100; x++ ) {
	//bagi per lvl
	frm->px[x][y].r=frm->px[x][y].r/lvl;
	frm->px[x][y].g=frm->px[x][y].g/lvl;
	frm->px[x][y].b=frm->px[x][y].b/lvl;
	insertPixel(frm,coord(x,y),rgb(frm->px[x][y].r,frm->px[x][y].g, frm->px[x][y].b));
		}
 	}
 }
 
void warzone(FrameBuffer *fb, Frame *cF,Frame *frm , int canvasWidth , int canvasHeight ,Coord canvasPosition,RGB colorShip){
	
	// prepare plane & ship
	int planeVelocity = 10;
	int shipVelocity = 5; // velocity (pixel/ loop)
	
	int shipXPosition = canvasWidth - 80;
	int shipYPosition = 598;

	int planeXPosition = canvasWidth;
	int planeYPosition = 50;
	int balingXPosition = planeXPosition+120;
	int balingYPosition = planeYPosition + 10;
	int explosionMul = 0;
	
	// prepare ammunition
	Coord firstAmmunitionCoordinate;
	int isFirstAmmunitionReleased = 1;
	Coord secondAmmunitionCoordinate;
	int isSecondAmmunitionReleased = 0;
	int ammunitionVelocity = 5;
	int ammunitionLength = 20;
	
	firstAmmunitionCoordinate.x = shipXPosition;
	firstAmmunitionCoordinate.y = shipYPosition - 120;
	secondAmmunitionCoordinate.y = shipYPosition - 120;	
	
	int i; //for drawing.
	int MoveLeft = 1;
	int stickmanCounter = 0;
	
	int isXploded = 0;
	Coord coordXplosion;
	int balingCounter=0;
	
	int chuteX = 400;
	int chuteY = 50;
	int stickmanX = 1350;
	int stickmanEncounter = 0;
	int chutesize = 50;
	int deployed = 0;
	
	float bVel = -5;
	float bVelX = 5;
	Coord coordBan;
	coordBan.x = canvasWidth/2;
	coordBan.y = canvasHeight/2;
	
	int planeNotHit = 0 ; 
	
	while (planeNotHit<52) {
		// clean composition frame
		flushFrame(cF, rgb(33,33,33));
				
		showCanvas(cF, frm, canvasWidth, canvasHeight, canvasPosition, rgb(99,99,99), 1);
		
		// clean canvas
		flushFrame(frm, rgb(0,0,0));
		
		// draw ship
		drawShip(frm, coord(shipXPosition -= shipVelocity,shipYPosition),colorShip);
		
		//drawFish
		drawFish(frm, coord(shipXPosition, shipYPosition),colorShip);
		
		//colorFish
		colorFlood(frm,shipXPosition-15,shipYPosition-1,colorShip);
		colorFlood(frm,shipXPosition+15,shipYPosition-1,colorShip);
		
		// draw stickman and cannon
		drawStickmanAndCannon(frm, coord(shipXPosition,shipYPosition),colorShip, stickmanCounter++);
				
		// draw plane
		if(isXploded == 0){
			drawPlane(frm, coord(planeXPosition -= planeVelocity, planeYPosition), rgb(99, 99, 99));

		//draw Bird
		drawBird(frm,coord(planeXPosition+60,planeYPosition),rgb(99,99,99));
		
		colorFlood(frm,planeXPosition+19,planeYPosition,rgb(99,99,99)); // dpn pesawat (kiri)
		colorFlood(frm,planeXPosition+162,planeYPosition,rgb(99,99,99)); //belakangnya pesawat (kanan)
		colorFlood(frm,planeXPosition+35,planeYPosition-4,rgb(99,99,99)); //diatas gambar burung	
		}
		
		// draw parachute
		if(isXploded){
			deployed = 1;
		}
		if(deployed)
		{ 	
			if(chutesize <= 150){
				chutesize++;
			}
			drawParachute(frm, coord(chuteX+=4, chuteY+=1), rgb(99, 99, 99), chutesize);
			animateBan(frm, &coordBan, rgb(255, 99, 99), &bVel, &bVelX);
		}
		
		if(stickmanEncounter){
			drawWalkingStickman(frm, coord(stickmanX -= 4, 503), rgb(99, 99, 99));
		}
		if(deployed)
		{
			rotateBalingBesar(frm,coord(planeXPosition + 160,balingYPosition+=planeVelocity),rgb(255,255,255),balingCounter--);
		}
		else
		{
			rotateBalingBesar(frm,coord(planeXPosition + 160,planeYPosition+10),rgb(255,255,255),balingCounter--);
		}
	
		
		// stickman ammunition
		if(isFirstAmmunitionReleased && !deployed){
			firstAmmunitionCoordinate.y-=ammunitionVelocity;
			
			if(firstAmmunitionCoordinate.y <= canvasHeight/3 && !isSecondAmmunitionReleased){
				isSecondAmmunitionReleased = 1;
				secondAmmunitionCoordinate.x = shipXPosition;
				secondAmmunitionCoordinate.y = shipYPosition - 120;
			}
			
			if(firstAmmunitionCoordinate.y <= -ammunitionLength){
				isFirstAmmunitionReleased = 0;
			}
			
			drawPeluru(frm, firstAmmunitionCoordinate, rgb(99, 99, 99));
			drawAmmunition(frm, firstAmmunitionCoordinate, 3, ammunitionLength, rgb(99, 99, 99));
		}
		
		if(isSecondAmmunitionReleased && !deployed){
			secondAmmunitionCoordinate.y-=ammunitionVelocity;
			
			if(secondAmmunitionCoordinate.y <= canvasHeight/3 && !isFirstAmmunitionReleased){
				isFirstAmmunitionReleased = 1;
				firstAmmunitionCoordinate.x = shipXPosition;
				firstAmmunitionCoordinate.y = shipYPosition - 120;
			}
			
			if(secondAmmunitionCoordinate.y <= 0){
				isSecondAmmunitionReleased = 0;
			}
			
			drawPeluru(frm, secondAmmunitionCoordinate, rgb(99, 99, 99));
			drawAmmunition(frm, secondAmmunitionCoordinate, 3, ammunitionLength, rgb(99, 99, 99));
		}
			
		//explosion
		if (isInBound(coord(firstAmmunitionCoordinate.x, firstAmmunitionCoordinate.y), coord(planeXPosition-5, planeYPosition-15), coord(planeXPosition+170, planeYPosition+15))) {
			coordXplosion = firstAmmunitionCoordinate;
			isXploded = 1;
			//printf("boom");
		} else if (isInBound(coord(secondAmmunitionCoordinate.x, secondAmmunitionCoordinate.y), coord(planeXPosition-5, planeYPosition-15), coord(planeXPosition+170, planeYPosition+15))) {
			coordXplosion = secondAmmunitionCoordinate;
			isXploded = 1;
			//printf("boom");
		}
		if (isXploded == 1) {
			if(planeNotHit == 0){
				planeNotHit =1;}
			animateExplosion(frm, explosionMul, coordXplosion);
			explosionMul++;
			if(explosionMul >= 20){
				explosionMul = 0;
				//isXploded = 0;
			}			
		}
		
		if(planeXPosition <= -170){
			planeXPosition = canvasWidth;
			balingXPosition = canvasWidth + 120;
		}
		
		if(planeXPosition == screenX/2 - canvasWidth/2 - 165){
			planeXPosition = screenX/2 + canvasWidth/2;
		}
		
		if(shipXPosition <= -85){
			shipXPosition = canvasWidth + 80;
		}
		
		if(stickmanX <= -70){
			stickmanX = canvasWidth;
		}
		
		if(planeXPosition == screenX/2 - canvasWidth/2 - 165){
			planeXPosition = screenX/2 + canvasWidth/2;
		}
		
		if(chuteX >= canvasWidth + chutesize * 2){
			stickmanEncounter = 1;
		}

		if (planeNotHit>0){
			planeNotHit++;
			if(planeNotHit>35){
				fadeOut(frm,planeNotHit-35);
			}
		}
showFrame(cF,fb);	
}
}

/* MAIN FUNCTION ------------------------------------------------------- */
int main() {	
	/* Preparations ---------------------------------------------------- */
	
	// get fb and screenInfos
	struct fb_var_screeninfo vInfo; // variable screen info
	struct fb_fix_screeninfo sInfo; // static screen info
	int fbFile;	 // frame buffer file descriptor
	fbFile = open("/dev/fb0",O_RDWR);
	if (!fbFile) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	if (ioctl (fbFile, FBIOGET_FSCREENINFO, &sInfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}
	if (ioctl (fbFile, FBIOGET_VSCREENINFO, &vInfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	
	// create the FrameBuffer struct with its important infos.
	FrameBuffer fb;
	fb.smemLen = sInfo.smem_len;
	fb.lineLen = sInfo.line_length;
	fb.bpp = vInfo.bits_per_pixel;
	
	// and map the framebuffer to the FB struct.
	fb.ptr = (char*)mmap(0, sInfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbFile, 0);
	if ((long int)fb.ptr == -1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	
	// prepare mouse controller
	FILE *fmouse;
	char mouseRaw[3];
	fmouse = fopen("/dev/input/mice","r");
	Coord mouse; // mouse internal counter
	mouse.x = 0;
	mouse.y = 0;
		
	// prepare environment controller
	unsigned char loop = 1; // frame loop controller
	Frame cFrame; // composition frame (Video RAM)
	
	// prepare canvas
	Frame canvas;
	flushFrame(&canvas, rgb(0,0,0));
	int canvasWidth = 1100;
	int canvasHeight = 600;
	Coord canvasPosition = coord(screenX/2,screenY/2);
	RGB colorShip = rgb(99,99,99);
	
	warzone(&fb,&cFrame,&canvas,canvasWidth,canvasHeight,canvasPosition,colorShip);
	
	
	/* Cleanup --------------------------------------------------------- */
	//~ int running= 0;
	//~ pthread_join(pth,NULL);
	munmap(fb.ptr, sInfo.smem_len);
	close(fbFile);
	fclose(fmouse);
	return 0;
}

