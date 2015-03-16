#include "drawing.h"

void drawSquare (Frame *frm, Coord kiriAtas, Coord kananBawah, RGB color)
{
	//atas
	plotLine(frm, kiriAtas.x, kiriAtas.y, kananBawah.x, kiriAtas.y, color);
	//kanan
	plotLine(frm, kananBawah.x, kiriAtas.y, kananBawah.x, kananBawah.y, color);
	//kiri
	plotLine(frm, kiriAtas.x, kiriAtas.y, kiriAtas.x, kananBawah.y, color);
	//bawah
	plotLine(frm, kiriAtas.x, kananBawah.y, kananBawah.x, kananBawah.y, color);
}

void drawFreeSquare(Frame *frm, Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah, RGB color)
{
	plotLine(frm, kiriAtas.x, kiriAtas.y, kananAtas.x, kananAtas.y, color);
	plotLine(frm, kananAtas.x, kananAtas.y, kananBawah.x, kananBawah.y, color);
	plotLine(frm, kananBawah.x, kananBawah.y, kiriBawah.x, kiriBawah.y, color);
	plotLine(frm, kiriAtas.x, kiriAtas.y, kiriBawah.x, kiriBawah.y, color);
}

std::vector<Line> drawKapal(Frame *frm, Coord loc, RGB color){
	plotLine(frm,loc.x-15,loc.y-10,loc.x+15,loc.y-10,color);
	plotLine(frm,loc.x-15,loc.y+10,loc.x+15,loc.y+10,color);
	plotLine(frm,loc.x-15,loc.y-10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y-10,loc.x+20,loc.y,color); 	
	plotLine(frm,loc.x-15,loc.y+10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y+10,loc.x+20,loc.y,color);
	std::vector<Line> kapalLine;
	kapalLine.push_back(line(coord(loc.x-15,loc.y-10),coord(loc.x+15,loc.y-10)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y+10),coord(loc.x+15,loc.y+10)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y-10),coord(loc.x-20,loc.y)));
	kapalLine.push_back(line(coord(loc.x+15,loc.y-10),coord(loc.x+20,loc.y)));
	kapalLine.push_back(line(coord(loc.x-15,loc.y+10),coord(loc.x-20,loc.y)));
	kapalLine.push_back(line(coord(loc.x+15,loc.y+10),coord(loc.x+20,loc.y)));
	return kapalLine;
	}
	
std::vector<Line> drawKapalVertikal (Frame *frm, Coord loc, RGB color){
	plotLine(frm,loc.x-10,loc.y-15,loc.x-10,loc.y+15,color);
	plotLine(frm,loc.x+10,loc.y-15,loc.x+10,loc.y+15,color);
	plotLine(frm,loc.x,loc.y-20,loc.x-10,loc.y-15,color);
	plotLine(frm,loc.x,loc.y-20,loc.x+10,loc.y-15,color); 	
	plotLine(frm,loc.x,loc.y+20,loc.x-10,loc.y+15,color);
	plotLine(frm,loc.x,loc.y+20,loc.x+10,loc.y+15,color);
	std::vector<Line> kapalLine;
	kapalLine.push_back(line(coord(loc.x-10,loc.y-15),coord(loc.x-10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x+10,loc.y-15),coord(loc.x+10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x,loc.y-20),coord(loc.x-10,loc.y-15)));
	kapalLine.push_back(line(coord(loc.x,loc.y-20),coord(loc.x+10,loc.y-15)));
	kapalLine.push_back(line(coord(loc.x,loc.y+20),coord(loc.x-10,loc.y+15)));
	kapalLine.push_back(line(coord(loc.x,loc.y+20),coord(loc.x+10,loc.y+15)));
	return kapalLine;	
	}
	
std::vector<Line> drawPeta(Frame *frame, Coord center, RGB color) {
	std::vector<Line> sumatera;
	Coord offset = coord(30, 10);
	sumatera.push_back(line(offset, coord(offset.x+20, offset.y+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+45, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+35, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())+8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-3, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-25)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+8, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-7)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), offset));

	std::vector<Line> jawa;
	Coord offsetJawa = coord(offset.x+180, offset.y+350);
	jawa.push_back(line(offsetJawa, coord(offsetJawa.x+15, offsetJawa.y-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+25, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-1)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())+6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+30, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+2, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+6, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+4, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())-6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-45, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-35, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-40, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-8, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-3, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back()), EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), offsetJawa));

	std::vector<Line> kalimantan;
	Coord offsetKalimantan = coord(offset.x+230, offset.y+150);
	kalimantan.push_back(line(offsetKalimantan, coord(offsetKalimantan.x+5, offsetKalimantan.y-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-6)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+8, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+35)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-4, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-2, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-8, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-+2, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-20, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-30, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+2, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+7, EndY(kalimantan.back())-7)));
	kalimantan.push_back(line(End(kalimantan.back()), offsetKalimantan));


	std::vector<Line> sulawesi;
	Coord offsetSulawesi = coord(offset.x+520, offset.y+170);
	sulawesi.push_back(line(offsetSulawesi, coord(offsetSulawesi.x+2, offsetSulawesi.y-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+30, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+25, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-6)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+9, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+6, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-11, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+18, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-20, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-1, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), offsetSulawesi));

	std::vector<Line> papua;
	Coord offsetPapua = coord(offset.x+900, offset.y+170);
	papua.push_back(line(offsetPapua, coord(offsetPapua.x+5, offsetPapua.y-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back()), EndY(papua.back())+150)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-9)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-13)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-18, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-20, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+9, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-9, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), offsetPapua));
	//papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	
	std::vector<Line> petaLines;
	for(int i=0;i<sumatera.size();++i)  
	{
		petaLines.push_back(sumatera.at(i));
		//cohen_sutherland(frame, StartX(sumatera.at(i)), StartY(sumatera.at(i)), EndX(sumatera.at(i)), EndY(sumatera.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sumatera.at(i), color);
	}
	
	for(int i=0;i<jawa.size();++i)
	{
		petaLines.push_back(jawa.at(i));
		plotLine(frame, jawa.at(i), color);
		//cohen_sutherland(frame, StartX(jawa.at(i)), StartY(jawa.at(i)), EndX(jawa.at(i)), EndY(jawa.at(i)), 400, 300, 800, 600, rgb(100,100,100));
	}
	for(int i=0;i<kalimantan.size();++i)
	{
		petaLines.push_back(kalimantan.at(i));
		//cohen_sutherland(frame, StartX(kalimantan.at(i)), StartY(kalimantan.at(i)), EndX(kalimantan.at(i)), EndY(kalimantan.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, kalimantan.at(i), color);
	}
	for(int i=0;i<sulawesi.size();++i)
	{
		petaLines.push_back(sulawesi.at(i));
		//cohen_sutherland(frame, StartX(sulawesi.at(i)), StartY(sulawesi.at(i)), EndX(sulawesi.at(i)), EndY(sulawesi.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sulawesi.at(i), color);
	}
	for(int i=0;i<papua.size();++i)
	{
		petaLines.push_back(papua.at(i));
		plotLine(frame, papua.at(i), color);
	}
	
	//~ printf("Ukuran Sumatera = %d\n", sumatera.size());
	//~ printf("Ukuran jawa = %d\n", jawa.size());
	//~ printf("Ukuran kalimantan = %d\n", kalimantan.size());
	//~ printf("Ukuran sulawesi = %d\n", sulawesi.size());
	//~ printf("Ukuran papua = %d\n", papua.size());
	return petaLines;
}

std::vector<Line> drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color){
	int xOffset = loc.x-x1;
	int yOffset = loc.y-y1;

	std::vector<Line> balingLine;
	balingLine.push_back(line(coord(x1,y1),coord(x2,y2)));
	balingLine.push_back(line(coord(x2,y2),coord(x3,y3)));
	balingLine.push_back(line(coord(x3,y3),coord(x4,y4)));
	balingLine.push_back(line(coord(x4,y4),coord(x1,y1)));
	
	plotCircle(frm,loc.x,loc.y,2,color);
	plotLine(frm,loc.x-5,loc.y-3,loc.x+15,loc.y-3,color);
	plotLine(frm,loc.x+15,loc.y-3,loc.x+15,loc.y+3,color);
	plotLine(frm,loc.x+15,loc.y+3,loc.x-5,loc.y+3,color);
	plotLine(frm,loc.x-5,loc.y+3,loc.x-5,loc.y-3,color);
	
	balingLine.push_back(line(coord(loc.x-5,loc.y-3),coord(loc.x+15,loc.y-3)));
	balingLine.push_back(line(coord(loc.x+15,loc.y-3),coord(loc.x+15,loc.y+3)));
	balingLine.push_back(line(coord(loc.x-5,loc.y+3),coord(loc.x-5,loc.y-3)));
	balingLine.push_back(line(coord(loc.x+15,loc.y+3),coord(loc.x-5,loc.y+3)));
	
	std::vector<Coord> balingCoordinates;
	balingCoordinates.push_back(loc);
	balingCoordinates.push_back(coord(x1, y1));
	balingCoordinates.push_back(coord(x2, y2));
	balingCoordinates.push_back(coord(x3,y3));
	balingCoordinates.push_back(coord(x4,y4));

	// Gambar baling-baling
	for(int i = 0; i < balingCoordinates.size(); i++){
		int x0, y0, x1, y1;
		if(i < balingCoordinates.size() - 1){
			x0 = balingCoordinates.at(i).x;
			y0 = balingCoordinates.at(i).y;
			x1 = balingCoordinates.at(i + 1).x;
			y1 = balingCoordinates.at(i + 1).y;
		}else{
			x0 = balingCoordinates.at(balingCoordinates.size() - 1).x;
			y0 = balingCoordinates.at(balingCoordinates.size() - 1).y;
			x1 = balingCoordinates.at(0).x;
			y1 = balingCoordinates.at(0).y;
		}
		plotLine(frm, x0, y0, x1, y1, color);
	}

	int balingHeight = 80;
	return balingLine;
}

std::vector<Line> rotateBaling(Frame *frm,Coord loc, RGB col ,int counter ){
	int x1=loc.x+10; int y1=loc.y+2;
	int x2=loc.x+10; int y2=loc.y-2;
	int x3=loc.x-10; int y3=loc.y+2;
	int x4=loc.x-10; int y4=loc.y-2;
	
	std::vector<Line> balingLine;
	int temp;
	temp=rotasiX(x1,y1,loc,counter*10);
	y1=rotasiY(x1,y1,loc,counter*10);
	x1=temp;
	temp=rotasiX(x2,y2,loc,counter*10);
	y2=rotasiY(x2,y2,loc,counter*10);
	x2=temp;
	temp=rotasiX(x3,y3,loc,counter*10);	
	y3=rotasiY(x3,y3,loc,counter*10);
	x3=temp;
	temp=rotasiX(x4,y4,loc,counter*10);
	y4=rotasiY(x4,y4,loc,counter*10);
	x4=temp;
	balingLine=drawBaling(frm,loc,x1,x2,x3,x4,y1,y2,y3,y4,col);
	return balingLine;
}

void appendLines(std::vector<Line> *allLines, std::vector<Line> building){
	for(int i = 0; i < building.size(); i++){
		allLines->push_back(building.at(i));
	}
}

void drawITB(Frame *frm, Coord3d cameraPosition, int angleX, int angleY, int screenWidth, int screenHeight, int xPosition, int yPosition, RGB color){
	vector<Block> buildings;
	vector<Line> allLines;
	vector<Line> clippedLinesLeft;
	vector<Line> clippedLinesRight;
	int halfScreenWidth = screenWidth / 2;
	int halfScreenHeight = screenHeight / 2;
				
	// GKU Barat
	buildings.push_back(block(coord3d(-170, 0, 75), 45, 45, 40));
	vector<Line> gkuBarat = perspectiveProjection(buildings[0], cameraPosition, angleX, angleY);
	
	// labtek
	buildings.push_back(block(coord3d(-95, 0, 90), 95, 30, 50));
	vector<Line> labtekV = perspectiveProjection(buildings[1], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(-100, 0, 40), 95, 30, 50));
	vector<Line> labtekVI = perspectiveProjection(buildings[2], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(20, 0, 90), 95, 30, 50));
	vector<Line> labtekVIII = perspectiveProjection(buildings[3], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(25, 0, 40), 95, 30, 50));
	vector<Line> labtekVII = perspectiveProjection(buildings[4], cameraPosition, angleX, angleY);
	
	// Oktagon, TVST
	buildings.push_back(block(coord3d(-40, 0, -10), 40, 40, 40));
	vector<Line> tvst = perspectiveProjection(buildings[5], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(-40, 0, -60), 40, 40, 40));
	vector<Line> oktagon = perspectiveProjection(buildings[6], cameraPosition, angleX, angleY);
		
	// Comlabs, PLN
	buildings.push_back(block(coord3d(20, 0, -10), 40, 30, 40));
	vector<Line> pln = perspectiveProjection(buildings[7], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(20, 0, -70), 40, 30, 40));
	vector<Line> comlabs = perspectiveProjection(buildings[8], cameraPosition, angleX, angleY);
	
	// PAU
	buildings.push_back(block(coord3d(-40, 0, -120), 40, 70, 80));
	vector<Line> pau = perspectiveProjection(buildings[9], cameraPosition, angleX, angleY);
	
	// Perpus
	buildings.push_back(block(coord3d(40, 0, -130), 40, 60, 40));
	vector<Line> perpus = perspectiveProjection(buildings[10], cameraPosition, angleX, angleY);
	
	// GKU Timur
	buildings.push_back(block(coord3d(155, 0, 65), 55, 25, 50));
	vector<Line> gkuTimur = perspectiveProjection(buildings[11], cameraPosition, angleX, angleY);
	
	// CC
	buildings.push_back(block(coord3d(-50, 0, 160), 50, 20, 30));
	vector<Line> ccBarat = perspectiveProjection(buildings[12], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(25, 0, 160), 50, 20, 30));
	vector<Line> ccTimur = perspectiveProjection(buildings[13], cameraPosition, angleX, angleY);
	
	// Aula
	buildings.push_back(block(coord3d(50, 0, 270), 60, 30, 20));
	vector<Line> aulaTimur = perspectiveProjection(buildings[14], cameraPosition, angleX, angleY);
	buildings.push_back(block(coord3d(-80, 0, 270), 60, 30, 20));
	vector<Line> aulaBarat = perspectiveProjection(buildings[15], cameraPosition, angleX, angleY);
	
	appendLines(&clippedLinesLeft, pau);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, pau.at(2).end, pau.at(2).start, pau.at(0).start, pau.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, pau.at(6).end, pau.at(6).start, pau.at(2).end, pau.at(2).start);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, pau.at(10).start, pau.at(10).end, pau.at(9).start, pau.at(9).end);
	
	appendLines(&clippedLinesLeft, oktagon);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, oktagon.at(2).end, oktagon.at(2).start, oktagon.at(0).start, oktagon.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, oktagon.at(6).end, oktagon.at(6).start, oktagon.at(2).end, oktagon.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, oktagon.at(10).start, oktagon.at(10).end, oktagon.at(9).start, oktagon.at(9).end);
	
	appendLines(&clippedLinesLeft, tvst);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, tvst.at(2).end, tvst.at(2).start, tvst.at(0).start, tvst.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, tvst.at(6).end, tvst.at(6).start, tvst.at(2).end, tvst.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, tvst.at(10).start, tvst.at(10).end, tvst.at(9).start, tvst.at(9).end);
	
	appendLines(&clippedLinesLeft, labtekVI);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekVI.at(2).end, labtekVI.at(2).start, labtekVI.at(0).start, labtekVI.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekVI.at(6).end, labtekVI.at(6).start, labtekVI.at(2).end, labtekVI.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekVI.at(10).start, labtekVI.at(10).end, labtekVI.at(9).start, labtekVI.at(9).end);
	
	appendLines(&clippedLinesLeft, labtekV);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekV.at(2).end, labtekV.at(2).start, labtekV.at(0).start, labtekV.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekV.at(6).end, labtekV.at(6).start, labtekV.at(2).end, labtekV.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, labtekVI.at(10).start, labtekVI.at(10).end, labtekVI.at(9).start, labtekVI.at(9).end);
	
	appendLines(&clippedLinesLeft, gkuBarat);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, gkuBarat.at(2).end, gkuBarat.at(2).start, gkuBarat.at(0).start, gkuBarat.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, gkuBarat.at(6).end, gkuBarat.at(6).start, gkuBarat.at(2).end, gkuBarat.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, gkuBarat.at(10).start, gkuBarat.at(10).end, gkuBarat.at(9).start, gkuBarat.at(9).end);
	
	appendLines(&clippedLinesLeft, ccBarat);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, ccBarat.at(2).end, ccBarat.at(2).start, ccBarat.at(0).start, ccBarat.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, ccBarat.at(6).end, ccBarat.at(6).start, ccBarat.at(2).end, ccBarat.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, ccBarat.at(10).start, ccBarat.at(10).end, ccBarat.at(9).start, ccBarat.at(9).end);
	
	appendLines(&clippedLinesLeft, aulaBarat);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, aulaBarat.at(2).end, aulaBarat.at(2).start, aulaBarat.at(0).start, aulaBarat.at(0).end);
	clippedLinesLeft = cohen_sutherland(clippedLinesLeft, aulaBarat.at(6).end, aulaBarat.at(6).start, aulaBarat.at(2).end, aulaBarat.at(2).start);
	//clippedLinesLeft = cohen_sutherland(clippedLinesLeft, aulaBarat.at(10).start, aulaBarat.at(10).end, aulaBarat.at(9).start, aulaBarat.at(9).end);
	
	appendLines(&clippedLinesRight, perpus);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, perpus.at(2).end, perpus.at(2).start, perpus.at(0).start, perpus.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, perpus.at(6).end, perpus.at(6).start, perpus.at(2).end, perpus.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, perpus.at(11).end, perpus.at(11).start, perpus.at(8).end, perpus.at(8).start);
	
	appendLines(&clippedLinesRight, comlabs);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, comlabs.at(2).end, comlabs.at(2).start, comlabs.at(0).start, comlabs.at(0).end);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, comlabs.at(6).end, comlabs.at(6).start, comlabs.at(2).end, comlabs.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, comlabs.at(11).end, comlabs.at(11).start, comlabs.at(8).end, comlabs.at(8).start);
	
	appendLines(&clippedLinesRight, pln);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, pln.at(2).end, pln.at(2).start, pln.at(0).start, pln.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, pln.at(6).end, pln.at(6).start, pln.at(2).end, pln.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, pln.at(11).end, pln.at(11).start, pln.at(8).end, pln.at(8).start);
	
	appendLines(&clippedLinesRight, labtekVII);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVII.at(2).end, labtekVII.at(2).start, labtekVII.at(0).start, labtekVII.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVII.at(6).end, labtekVII.at(6).start, labtekVII.at(2).end, labtekVII.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVII.at(11).end, labtekVII.at(11).start, labtekVII.at(8).end, labtekVII.at(8).start);
	
	appendLines(&clippedLinesRight, labtekVIII);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVIII.at(2).end, labtekVIII.at(2).start, labtekVIII.at(0).start, labtekVIII.at(0).end);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVIII.at(6).end, labtekVIII.at(6).start, labtekVIII.at(2).end, labtekVIII.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, labtekVIII.at(11).end, labtekVIII.at(11).start, labtekVIII.at(8).end, labtekVIII.at(8).start);
	
	appendLines(&clippedLinesRight, gkuTimur);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, gkuTimur.at(2).end, gkuTimur.at(2).start, gkuTimur.at(0).start, gkuTimur.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, gkuTimur.at(6).end, gkuTimur.at(6).start, gkuTimur.at(2).end, gkuTimur.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, gkuTimur.at(11).end, gkuTimur.at(11).start, gkuTimur.at(8).end, gkuTimur.at(8).start);
	
	appendLines(&clippedLinesRight, ccTimur);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, ccTimur.at(2).end, ccTimur.at(2).start, ccTimur.at(0).start, ccTimur.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, ccTimur.at(6).end, ccTimur.at(6).start, ccTimur.at(2).end, ccTimur.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, ccTimur.at(11).end, ccTimur.at(11).start, ccTimur.at(8).end, ccTimur.at(8).start);
	
	appendLines(&clippedLinesRight, aulaTimur);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, aulaTimur.at(2).end, aulaTimur.at(2).start, aulaTimur.at(0).start, aulaTimur.at(0).end);
	clippedLinesRight = cohen_sutherland(clippedLinesRight, aulaTimur.at(6).end, aulaTimur.at(6).start, aulaTimur.at(2).end, aulaTimur.at(2).start);
	//clippedLinesRight = cohen_sutherland(clippedLinesRight, aulaTimur.at(11).end, aulaTimur.at(11).start, aulaTimur.at(8).end, aulaTimur.at(8).start);
	
	/*appendLines(&allLines, perpus);
	appendLines(&allLines, pau);
	appendLines(&allLines, oktagon);
	appendLines(&allLines, comlabs);
	appendLines(&allLines, tvst);
	appendLines(&allLines, pln);
	appendLines(&allLines, labtekVI);
	appendLines(&allLines, labtekVII);
	appendLines(&allLines, labtekV);
	appendLines(&allLines, labtekVIII);
	appendLines(&allLines, ccBarat);
	appendLines(&allLines, ccTimur);
	appendLines(&allLines, gkuBarat);
	appendLines(&allLines, gkuTimur);
	appendLines(&allLines, aulaTimur);
	appendLines(&allLines, aulaBarat);*/

	
	for(int i = 0; i < allLines.size(); i++){
		int startX = allLines.at(i).start.x + halfScreenWidth + xPosition;
		int startY = allLines.at(i).start.y + halfScreenHeight + yPosition;
		int endX = allLines.at(i).end.x + halfScreenWidth + xPosition;
		int endY = allLines.at(i).end.y + halfScreenHeight + yPosition;
		
		plotLine(frm, startX, startY, endX, endY, color);
	}
	
	for(int i = 0; i < clippedLinesLeft.size(); i++){
		int startX = clippedLinesLeft.at(i).start.x + halfScreenWidth + xPosition;
		int startY = clippedLinesLeft.at(i).start.y + halfScreenHeight + yPosition;
		int endX = clippedLinesLeft.at(i).end.x + halfScreenWidth + xPosition;
		int endY = clippedLinesLeft.at(i).end.y + halfScreenHeight + yPosition;
		
		plotLine(frm, startX, startY, endX, endY, rgb(0, 255, 0));
	}
	
	for(int i = 0; i < clippedLinesRight.size(); i++){
		int startX = clippedLinesRight.at(i).start.x + halfScreenWidth + xPosition;
		int startY = clippedLinesRight.at(i).start.y + halfScreenHeight + yPosition;
		int endX = clippedLinesRight.at(i).end.x + halfScreenWidth + xPosition;
		int endY = clippedLinesRight.at(i).end.y + halfScreenHeight + yPosition;
		
		plotLine(frm, startX, startY, endX, endY, rgb(0, 255, 0));
	}
}


