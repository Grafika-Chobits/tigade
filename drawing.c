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

void drawBalingBesar(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color){
	int xOffset = loc.x-x1;
	int yOffset = loc.y-y1;

	plotCircle(frm,loc.x,loc.y,15,color);
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
	//fillShape(frm, loc.x, loc.y, loc.y-40, balingHeight, balingCoordinates, color);

	// plotLine(frm,loc.x,loc.y,x1,y1,color);
	// plotLine(frm,loc.x,loc.y,x2,y2,color);
	// plotLine(frm,x1,y1,x2,y2,color);
	
	// plotLine(frm,loc.x,loc.y,x3,y3,rgb(255,0,0));
	// plotLine(frm,loc.x,loc.y,x4,y4,color);
	// plotLine(frm,x3,y3,x4,y4,color);
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

void rotateBalingBesar(Frame *frm,Coord loc, RGB col ,int counter ){
	int x1=loc.x+40; int y1=loc.y+5;
	int x2=loc.x+40; int y2=loc.y-5;
	int x3=loc.x-40; int y3=loc.y+5;
	int x4=loc.x-40; int y4=loc.y-5;
	
	
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
	drawBalingBesar(frm,loc,x1,x2,x3,x4,y1,y2,y3,y4,col);
	}


void drawAmmunition(Frame *frame, Coord upperBoundPosition, int ammunitionWidth, int ammunitionLength, RGB color){
	plotLine(frame, upperBoundPosition.x, upperBoundPosition.y, upperBoundPosition.x, upperBoundPosition.y + ammunitionLength, color);
	
	int i;
	for(i = 0; i < ammunitionWidth; i++){
		plotLine(frame, upperBoundPosition.x + i, upperBoundPosition.y, upperBoundPosition.x + i, upperBoundPosition.y + ammunitionLength, color);
		plotLine(frame, upperBoundPosition.x - i, upperBoundPosition.y, upperBoundPosition.x - i, upperBoundPosition.y + ammunitionLength, color);
	}	
}

void drawPeluru(Frame *frame, Coord center, RGB color)
{
	int panjangPeluru = 10;
	//DrawKiri
	plotLine(frame, center.x - 3, center.y + panjangPeluru / 2, center.x -3, center.y - panjangPeluru / 2, color); 
	
	//DrawKanan
	plotLine(frame, center.x + 3, center.y + panjangPeluru / 2, center.x + 3, center.y - panjangPeluru / 2, color);
	
	//DrawBawah
	plotLine(frame, center.x - 3, center.y + panjangPeluru / 2, center.x +3, center.y + panjangPeluru / 2, color);
	
	//DrawUjungKiri
	plotLine(frame, center.x - 3, center.y - panjangPeluru / 2, center.x, center.y - (panjangPeluru / 2 + 4), color);
	
	//DrawUjungKanan
	plotLine(frame, center.x + 3, center.y - panjangPeluru / 2, center.x, center.y - (panjangPeluru / 2 + 4), color);
}

void drawPlane(Frame *frame, Coord position, RGB color) {

	// Ship's relative coordinate to canvas, ship's actuator
	int xPlaneCoordinate = position.x;
	int yPlaneCoordinate = position.y;
	
	// Ship's border coordinates
	vector<Coord>  planeCoordinates;
	planeCoordinates.push_back(coord(0,0));
	planeCoordinates.push_back(coord(planeCoordinates.at(0).x + 15, planeCoordinates.at(0).y-5));
	planeCoordinates.push_back(coord(planeCoordinates.at(1).x + 30, planeCoordinates.at(1).y-3));
	planeCoordinates.push_back(coord(planeCoordinates.at(2).x + 13, planeCoordinates.at(2).y-4));
	planeCoordinates.push_back(coord(planeCoordinates.at(3).x + 13, planeCoordinates.at(3).y-3));
	planeCoordinates.push_back(coord(planeCoordinates.at(4).x + 13, planeCoordinates.at(4).y+3));
	planeCoordinates.push_back(coord(planeCoordinates.at(5).x + 13, planeCoordinates.at(5).y+4));
	planeCoordinates.push_back(coord(planeCoordinates.at(6).x + 50, planeCoordinates.at(6).y-3));
	planeCoordinates.push_back(coord(planeCoordinates.at(7).x + 5, planeCoordinates.at(7).y-18));
	planeCoordinates.push_back(coord(planeCoordinates.at(8).x + 10, planeCoordinates.at(8).y-4));
	planeCoordinates.push_back(coord(planeCoordinates.at(9).x + 3, planeCoordinates.at(9).y+27));
	planeCoordinates.push_back(coord(planeCoordinates.at(10).x - 1, planeCoordinates.at(10).y+5));
	planeCoordinates.push_back(coord(planeCoordinates.at(11).x + 1, planeCoordinates.at(11).y+5));
	planeCoordinates.push_back(coord(planeCoordinates.at(12).x - 67, planeCoordinates.at(12).y+3));
	planeCoordinates.push_back(coord(planeCoordinates.at(13).x + 13, planeCoordinates.at(13).y+25));
	planeCoordinates.push_back(coord(planeCoordinates.at(14).x - 10, planeCoordinates.at(14).y-6));
	planeCoordinates.push_back(coord(planeCoordinates.at(15).x - 17, planeCoordinates.at(15).y-18));
	planeCoordinates.push_back(coord(planeCoordinates.at(16).x - 37, planeCoordinates.at(16).y-1));
	planeCoordinates.push_back(coord(planeCoordinates.at(17).x - 27, planeCoordinates.at(17).y-3));
	

	// Draw ship's border relative to canvas
	for(int i = 0; i < planeCoordinates.size(); i++){
		int x0, y0, x1, y1;
		
		if(i < planeCoordinates.size() - 1){
			x0 = planeCoordinates.at(i).x + xPlaneCoordinate;
			y0 = planeCoordinates.at(i).y + yPlaneCoordinate;
			x1 = planeCoordinates.at(i + 1).x + xPlaneCoordinate;
			y1 = planeCoordinates.at(i + 1).y + yPlaneCoordinate;
		}else{
			x0 = planeCoordinates.at(planeCoordinates.size() - 1).x + xPlaneCoordinate;
			y0 = planeCoordinates.at(planeCoordinates.size() - 1).y + yPlaneCoordinate;
			x1 = planeCoordinates.at(0).x + xPlaneCoordinate;
			y1 = planeCoordinates.at(0).y + yPlaneCoordinate;
		}
		
		plotLine(frame, x0, y0, x1, y1, color);
	}
	
	// Pattern's coordinate
	vector<Coord> patternCoordinates = getBirdCoordinate(coord(50,-10));
	
}

void drawBird(Frame* frm, Coord loc,RGB color){
	plotHalfCircle(frm,loc.x,loc.y,10,color);
	plotHalfCircle(frm,loc.x+20,loc.y,10,color);
	plotHalfCircle(frm,loc.x,loc.y,5,color);
	plotHalfCircle(frm,loc.x+20,loc.y,5,color);
	plotLine(frm,loc.x+10,loc.y,loc.x+5,loc.y,color);
	plotLine(frm,loc.x-10,loc.y,loc.x-5,loc.y,color);
	plotLine(frm,loc.x+15,loc.y,loc.x+10,loc.y,color);
	plotLine(frm,loc.x+25,loc.y,loc.x+30,loc.y,color);
	}

void drawExplosion(Frame *frame, Coord loc, int mult, RGB color){	
	plotLine(frame,loc.x+10*mult,loc.y +10*mult,loc.x+20*mult,loc.y+20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y -10*mult,loc.x-20*mult,loc.y-20*mult,color);
	plotLine(frame,loc.x+10*mult,loc.y -10*mult,loc.x+20*mult,loc.y-20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y +10*mult,loc.x-20*mult,loc.y+20*mult,color);
	plotLine(frame,loc.x,loc.y -10*mult,loc.x,loc.y-20*mult,color);
	plotLine(frame,loc.x-10*mult,loc.y,loc.x-20*mult,loc.y,color);
	plotLine(frame,loc.x+10*mult,loc.y ,loc.x+20*mult,loc.y,color);
	plotLine(frame,loc.x,loc.y +10*mult,loc.x,loc.y+20*mult,color);
}

void drawBomb(Frame *frame, Coord center, RGB color)
{
	int panjangBomb = 10;
	//DrawKiri
	plotLine(frame, center.x - 3, center.y + panjangBomb / 2, center.x -3, center.y - panjangBomb / 2, color); 
	
	//DrawKanan
	plotLine(frame, center.x + 3, center.y + panjangBomb / 2, center.x + 3, center.y - panjangBomb / 2, color);
	
	//DrawAtas
	plotLine(frame, center.x - 3, center.y - panjangBomb / 2, center.x +3, center.y - panjangBomb / 2, color);
	
	//DrawUjungKiri
	plotLine(frame, center.x - 3, center.y + panjangBomb / 2, center.x, center.y + (panjangBomb / 2 + 4), color);
	
	//DrawUjungKanan
	plotLine(frame, center.x + 3, center.y + panjangBomb / 2, center.x, center.y + (panjangBomb / 2 + 4), color);
}

void drawShip(Frame *frame, Coord center, RGB color)
{
	// Ship's attributes
	int panjangDekBawah = 100;
	int deltaDekAtasBawah = 60;
	int height = 40;
	int jarakKeUjung = panjangDekBawah / 2 + deltaDekAtasBawah / 2;
	
	// Ship's relative coordinate to canvas, ship's actuator
	int xShipCoordinate = center.x - jarakKeUjung;
	int yShipCoordinate = center.y - height;
	
	// Ship's border coordinates
	vector<Coord>  shipCoordinates;
	
	shipCoordinates.push_back(coord(0, 0));
	shipCoordinates.push_back(coord(0 + jarakKeUjung + jarakKeUjung, 0));
	shipCoordinates.push_back(coord(panjangDekBawah / 2 + panjangDekBawah / 2 + deltaDekAtasBawah/2, height));
	shipCoordinates.push_back(coord(deltaDekAtasBawah/2, height));
		
	// Draw ship's border relative to canvas
	for(int i = 0; i < shipCoordinates.size(); i++){
		int x0, y0, x1, y1;
		
		if(i < shipCoordinates.size() - 1){
			x0 = shipCoordinates.at(i).x + xShipCoordinate;
			y0 = shipCoordinates.at(i).y + yShipCoordinate;
			x1 = shipCoordinates.at(i + 1).x + xShipCoordinate;
			y1 = shipCoordinates.at(i + 1).y + yShipCoordinate;
		}else{
			x0 = shipCoordinates.at(shipCoordinates.size() - 1).x + xShipCoordinate;
			y0 = shipCoordinates.at(shipCoordinates.size() - 1).y + yShipCoordinate;
			x1 = shipCoordinates.at(0).x + xShipCoordinate;
			y1 = shipCoordinates.at(0).y + yShipCoordinate;
		}
		
		plotLine(frame, x0, y0, x1, y1, color);
	}
	
	// Coloring ship using scanline algorithm
	//~ for(int i = 1; i <= height; i++){
		//~ vector<Coord> shipIntersectionPoint = intersectionGenerator(i, shipCoordinates);
//~ 
		//~ if(shipIntersectionPoint.size() % 2 != 0){
			//~ unique(shipIntersectionPoint.begin(), shipIntersectionPoint.end(), compareSameAxis);
			//~ shipIntersectionPoint.erase(shipIntersectionPoint.end() - 1);
		//~ }
		//~ 
		//~ for(int j = 0; j < shipIntersectionPoint.size() - 1; j++){
			//~ if(j % 2 == 0){
				//~ int x0 = shipIntersectionPoint.at(j).x + xShipCoordinate;
				//~ int y0 = shipIntersectionPoint.at(j).y + yShipCoordinate;
				//~ int x1 = shipIntersectionPoint.at(j + 1).x + xShipCoordinate;
				//~ int y1 = shipIntersectionPoint.at(j + 1).y + yShipCoordinate;
				//~ 
				//~ plotLine(frame, x0, y0, x1, y1, color);
			//~ }
		//~ }		
	//~ }	

}

void drawParachute(Frame *frame, Coord center, RGB color, int size){
	int parachuteRadius = size;
	int parachuteDiameter = parachuteRadius * 2;
	
	// parachute upper border
	plotHalfCircle(frame, center.x, center.y, parachuteRadius, color);
	
	// parachute bottom border
	plotHalfCircle(frame, center.x - parachuteDiameter / 3, center.y, parachuteRadius / 3, color);
	plotHalfCircle(frame, center.x, center.y, parachuteRadius / 3, color);
	plotHalfCircle(frame, center.x + parachuteDiameter / 3, center.y, parachuteRadius / 3, color);
	
	// parachute string
	plotLine(frame, center.x - parachuteRadius, center.y, center.x - parachuteRadius / 6, center.y + parachuteRadius, color); // left
	plotLine(frame, center.x + parachuteRadius, center.y, center.x + parachuteRadius / 6, center.y + parachuteRadius, color); // right
	
	// stickman
	plotCircle(frame, center.x, center.y + parachuteRadius - parachuteRadius / 12, parachuteRadius / 12, color); //head
	
	int bodyStartingPoint = center.y + parachuteRadius - parachuteRadius / 10 + parachuteRadius / 10;
	plotLine(frame, center.x, bodyStartingPoint, center.x, bodyStartingPoint + parachuteRadius / 5, color); // body
	
	int legStartingPoint = bodyStartingPoint + parachuteRadius / 5;
	plotLine(frame, center.x, legStartingPoint, center.x + parachuteRadius / 13, legStartingPoint + parachuteRadius / 10, color); // right leg
	plotLine(frame, center.x, legStartingPoint, center.x - parachuteRadius / 13, legStartingPoint + parachuteRadius / 10, color); // left leg
	
	plotLine(frame, center.x, bodyStartingPoint, center.x - parachuteRadius / 10, bodyStartingPoint + parachuteRadius / 10, color);
	plotLine(frame, center.x, bodyStartingPoint, center.x + parachuteRadius / 10, bodyStartingPoint + parachuteRadius / 10, color);
	plotLine(frame, center.x - parachuteRadius / 10, bodyStartingPoint + parachuteRadius / 10, center.x - parachuteRadius / 6, center.y + parachuteRadius, color);
	plotLine(frame, center.x + parachuteRadius / 10, bodyStartingPoint + parachuteRadius / 10, center.x + parachuteRadius / 6, center.y + parachuteRadius, color);
}

void drawFish(Frame  *frame, Coord center, RGB color) {
	vector<Coord> fishCoord = getFishCoordinate(coord(center.x-30,center.y-20));
	for(int i=0;i<fishCoord.size();++i) {
		if(i!=fishCoord.size()-1)
			plotLine(frame,fishCoord.at(i).x, fishCoord.at(i).y ,fishCoord.at(i+1).x, fishCoord.at(i+1).y, color);
		else
			plotLine(frame, fishCoord.at(i).x, fishCoord.at(i).y ,fishCoord.at(0).x, fishCoord.at(0).y, color);
	}
}

vector<Coord> getBirdCoordinate(Coord center) {
	vector<Coord> birdCoord;

	birdCoord.push_back(coord(center.x, center.y));
	birdCoord.push_back(coord(birdCoord.at(0).x+10, birdCoord.at(0).y-5));
	birdCoord.push_back(coord(birdCoord.at(1).x+10, birdCoord.at(1).y+5));
	birdCoord.push_back(coord(birdCoord.at(2).x+5, birdCoord.at(2).y+5));
	birdCoord.push_back(coord(birdCoord.at(3).x+20, birdCoord.at(3).y+5));
	birdCoord.push_back(coord(birdCoord.at(4).x+5, birdCoord.at(4).y));
	birdCoord.push_back(coord(birdCoord.at(5).x-10, birdCoord.at(5).y+5));
	birdCoord.push_back(coord(birdCoord.at(6).x-10, birdCoord.at(6).y));
	birdCoord.push_back(coord(birdCoord.at(7).x-10, birdCoord.at(7).y-2));
	birdCoord.push_back(coord(birdCoord.at(8).x-10, birdCoord.at(8).y-2));
	birdCoord.push_back(coord(birdCoord.at(9).x-10, birdCoord.at(9).y-2));
	birdCoord.push_back(coord(birdCoord.at(10).x-10, birdCoord.at(10).y-2));

	return birdCoord;
}

vector<Coord> getFishCoordinate(Coord center) {
	vector<Coord> fishCoord;

	int xHeight = 72;
	int yHeight = 12;
	

	fishCoord.push_back(coord(center.x, center.y));
	fishCoord.push_back(coord(fishCoord.at(0).x + 7, fishCoord.at(0).y - 3));
	fishCoord.push_back(coord(fishCoord.at(1).x + 10, fishCoord.at(1).y - 2));
	fishCoord.push_back(coord(fishCoord.at(2).x + 15, fishCoord.at(2).y - 1));
	fishCoord.push_back(coord(fishCoord.at(3).x + 15, fishCoord.at(3).y + 1));
	fishCoord.push_back(coord(fishCoord.at(4).x + 12, fishCoord.at(4).y + 3));
	fishCoord.push_back(coord(fishCoord.at(5).x + 7, fishCoord.at(5).y));
	fishCoord.push_back(coord(fishCoord.at(6).x + 6, fishCoord.at(6).y - 6));
	fishCoord.push_back(coord(fishCoord.at(7).x, fishCoord.at(7).y + 12));
	fishCoord.push_back(coord(fishCoord.at(8).x - 6, fishCoord.at(8).y - 5)); 
	fishCoord.push_back(coord(fishCoord.at(9).x - 7, fishCoord.at(9).y + 2));
	fishCoord.push_back(coord(fishCoord.at(10).x - 12, fishCoord.at(10).y + 3));
	fishCoord.push_back(coord(fishCoord.at(11).x - 15, fishCoord.at(11).y + 1));
	fishCoord.push_back(coord(fishCoord.at(12).x - 15, fishCoord.at(12).y - 1));
	fishCoord.push_back(coord(fishCoord.at(13).x - 10, fishCoord.at(13).y - 2));

	return fishCoord;

}

void colorFlood(Frame* frm,int x, int y,RGB color){	
if ((isColorEqual(frm->px[x][y],color)==1)|| x<1 || x>1199 || y<1 || y>599 ){
	//do nothing
	} 
else{
	insertPixel(frm,coord(x,y),color);
	colorFlood(frm,x+1,y,color);
	colorFlood(frm,x,y+1,color);
	colorFlood(frm,x-1,y,color);
	colorFlood(frm,x,y-1,color);
	}	
}

int isColorEqual(RGB color1, RGB color2){
if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b){return 1;}
else {return 0;}
	}

void drawStickman(Frame* frm,Coord loc,int sel,RGB color,int counter){
	plotCircle(frm,loc.x,loc.y,15,color);
	plotLine(frm,loc.x,loc.y+15,loc.x,loc.y+50,color);
	
	if(counter % 2 == 0){
		plotLine(frm,loc.x,loc.y+30,loc.x+20,loc.y+sel-3,color);
		plotLine(frm,loc.x,loc.y+30,loc.x+25,loc.y+(sel+10)-3,color);
	}else{
		plotLine(frm,loc.x,loc.y+30,loc.x+20,loc.y+sel,color);
		plotLine(frm,loc.x,loc.y+30,loc.x+25,loc.y+(sel+10),color);
	}
	
	
}

void drawCannon(Frame* frm,Coord loc,RGB color){
	plotLine(frm,loc.x-10,loc.y-10,loc.x-10,loc.y+30,color);
	plotLine(frm,loc.x-10,loc.y+30,loc.x+10,loc.y+30,color);
	plotLine(frm,loc.x+10,loc.y+30,loc.x+10,loc.y-10,color);
	plotLine(frm,loc.x+10,loc.y-10,loc.x-10,loc.y-10,color);	
	plotHalfCircle(frm,loc.x,loc.y-10,10,color);
	loc.y=loc.y-20;
	plotLine(frm,loc.x-5,loc.y-5,loc.x-5,loc.y+2,color);
	//plotLine(loc.x-5,loc.y+5,loc.x+5,loc.y+5);
	plotLine(frm,loc.x+5,loc.y+2,loc.x+5,loc.y-5,color);
	plotLine(frm,loc.x+5,loc.y-5,loc.x-5,loc.y-5,color);	
}

void drawStickmanAndCannon(Frame *frame, Coord shipPosition, RGB color, int counter){
	
	if(counter % 2 == 0){
		//Draw cannon
		drawCannon(frame, coord(shipPosition.x, shipPosition.y - 80 - 3), rgb(99,99,99));
	}else{
		//Draw cannon
		drawCannon(frame, coord(shipPosition.x, shipPosition.y - 80), rgb(99,99,99));
	}
		
	//Draw stickman
	drawStickman(frame, coord(shipPosition.x - 30, shipPosition.y - 90), 15, rgb(99,99,99),counter);
}
void animateBan(Frame *frm, Coord *loc, RGB color, float *bVel, float *bVelX) {
	int g = 1;
	int tV = 1500;
	float cB = 0.9;
	if (*bVel < tV) {
		*bVel = *bVel+g;
	}
	if (loc->y > 590) {
		*bVel = (*bVel*-1);
	}
	*bVel = *bVel-(*bVel*0.03);
	*bVelX = *bVelX-(*bVelX*0.03);
	loc->x = loc->x+*bVelX;
	loc->y = loc->y+*bVel;
	plotCircle(frm,loc->x,loc->y,5,color);
}
void drawWalkingStickman(Frame *frame, Coord center, RGB color){
	int bodyLength = 50;
	int rightUpperArmLength = 30;
	int rightLowerArmLength = 20;
	int leftUpperArmLength = 30;
	int leftLowerArmLength = 20;
	int rightUpperLegLength = 30;
	int rightLowerLegLength = 20;
	int leftUpperLegLength = 30;
	int leftLowerLegLength = 20;
	
	static int centerPositionY = center.y;
	
	// head
	plotCircle(frame, center.x, centerPositionY - 20, 20, color);
	
	// body	
	Coord bodyEndPoint = lengthEndPoint(coord(center.x, centerPositionY), 88, bodyLength);
	plotLine(frame, center.x, centerPositionY, bodyEndPoint.x, bodyEndPoint.y, color);
	
	// right upper arm
	Coord rightUpperArmEndPoint;
	static int rightUpperArmRotation = 125;
	{
		static int moveBackwardArm = 1;
		
		if(rightUpperArmRotation == 125){
			moveBackwardArm = 1;
		}
		if(rightUpperArmRotation == 65){
			moveBackwardArm = 0;
		}
		
		
		if(moveBackwardArm){
			rightUpperArmRotation -= 5;
		}else{
			rightUpperArmRotation += 5;
		}
		
		rightUpperArmEndPoint = lengthEndPoint(coord(center.x, centerPositionY), rightUpperArmRotation, rightUpperArmLength);
		plotLine(frame, center.x, centerPositionY, rightUpperArmEndPoint.x, rightUpperArmEndPoint.y, color);
	}
	
	// right lower arm
	Coord rightLowerArmEndPoint = lengthEndPoint(coord(rightUpperArmEndPoint.x, rightUpperArmEndPoint.y), rightUpperArmRotation + 50, rightLowerArmLength);
	plotLine(frame, rightUpperArmEndPoint.x, rightUpperArmEndPoint.y, rightLowerArmEndPoint.x, rightLowerArmEndPoint.y, color);
	
	// left upper arm
	Coord leftUpperArmEndPoint;
	static int leftUpperArmRotation = 65;
	{
		
		static int moveForwardArm = 1;
		
		if(leftUpperArmRotation == 65){
			moveForwardArm = 1;
		}
		if(leftUpperArmRotation == 125){
			moveForwardArm = 0;
		}
		
		if(moveForwardArm){
			leftUpperArmRotation += 5;
		}else{
			leftUpperArmRotation -= 5;
		}
		
		leftUpperArmEndPoint = lengthEndPoint(coord(center.x, centerPositionY), leftUpperArmRotation, leftUpperArmLength);
		plotLine(frame, center.x, centerPositionY, leftUpperArmEndPoint.x, leftUpperArmEndPoint.y, color);
	}
	
	// left lower arm
	Coord leftLowerArmEndPoint = lengthEndPoint(coord(leftUpperArmEndPoint.x, leftUpperArmEndPoint.y), leftUpperArmRotation + 30, leftLowerArmLength);
	plotLine(frame, leftUpperArmEndPoint.x, leftUpperArmEndPoint.y, leftLowerArmEndPoint.x, leftLowerArmEndPoint.y, color);
	
	// right upper leg
	Coord rightUpperLegEndPoint;
	static int rightUpperLegRotation = 125;
	{
		static int moveBackwardLeg = 1;
		
		if(rightUpperLegRotation == 125){
			moveBackwardLeg = 1;
		}
		if(rightUpperLegRotation == 65){
			moveBackwardLeg = 0;
		}
		
		if(moveBackwardLeg){
			rightUpperLegRotation -= 5;
		}else{
			rightUpperLegRotation += 5;
		}
		
		rightUpperLegEndPoint = lengthEndPoint(coord(bodyEndPoint.x, bodyEndPoint.y), rightUpperLegRotation, rightUpperLegLength);
		plotLine(frame, bodyEndPoint.x, bodyEndPoint.y, rightUpperLegEndPoint.x, rightUpperLegEndPoint.y, color);
	}
	
	// right lower leg
	{
		static int rightLowerLegRotation = 95;
		static int moveBackwardLeg = 1;
		
		if(rightUpperLegRotation == 125){
			moveBackwardLeg = 1;
			rightLowerLegRotation = 95;
		}
		if(rightUpperLegRotation == 65){
			moveBackwardLeg = 0;
			rightLowerLegRotation = 70;
		}
		
		if(rightUpperLegRotation <= 90 ){
			if(moveBackwardLeg){
				rightLowerLegRotation = rightUpperLegRotation;
			}else{
				rightLowerLegRotation -= 5;
			}
		}else{
			if(!moveBackwardLeg){
				rightLowerLegRotation += 10;
				if(centerPositionY <= center.y + 1){
					centerPositionY++;
				}
			}else{
				if(centerPositionY > center.y){
					centerPositionY--;
				}
			}
		}

		Coord rightLowerLegEndPoint = lengthEndPoint(coord(rightUpperLegEndPoint.x, rightUpperLegEndPoint.y), rightLowerLegRotation, rightLowerLegLength);
		plotLine(frame, rightUpperLegEndPoint.x, rightUpperLegEndPoint.y, rightLowerLegEndPoint.x, rightLowerLegEndPoint.y, color);
	}
	
	// left upper leg
	Coord leftUpperLegEndPoint;
	static int leftUpperLegRotation = 65;
	{
		static int moveForwardLeg = 1;
		
		if(leftUpperLegRotation == 125){
			moveForwardLeg = 0;
		}
		if(leftUpperLegRotation == 65){
			moveForwardLeg = 1;
		}
		
		if(moveForwardLeg){
			leftUpperLegRotation += 5;
		}else{
			leftUpperLegRotation -= 5;
		}
		
		leftUpperLegEndPoint = lengthEndPoint(coord(bodyEndPoint.x, bodyEndPoint.y), leftUpperLegRotation, leftUpperLegLength);
		plotLine(frame, bodyEndPoint.x, bodyEndPoint.y, leftUpperLegEndPoint.x, leftUpperLegEndPoint.y, color);
	}
	
	// left lower leg
	{
		static int leftLowerLegRotation = 70;
		static int moveForwardLeg = 1;
		
		if(leftUpperLegRotation == 125){
			moveForwardLeg = 0;
			leftLowerLegRotation = 95;
		}
		if(leftUpperLegRotation == 65){
			moveForwardLeg = 1;
			leftLowerLegRotation = 70;
		}
		
		if(leftUpperLegRotation <= 90 ){
			if(moveForwardLeg){
				leftLowerLegRotation -= 5;
			}else{
				leftLowerLegRotation = leftUpperLegRotation;
			}
		}else{
			if(moveForwardLeg){
				leftLowerLegRotation += 10;
				if(centerPositionY <= center.y + 1){
					centerPositionY++;
				}
			}else{
				if(centerPositionY > center.y){
					centerPositionY--;
				}
			}
		}
		
		Coord leftLowerLegEndPoint = lengthEndPoint(coord(leftUpperLegEndPoint.x, leftUpperLegEndPoint.y), leftLowerLegRotation, leftLowerLegLength);
		plotLine(frame, leftUpperLegEndPoint.x, leftUpperLegEndPoint.y, leftLowerLegEndPoint.x, leftLowerLegEndPoint.y, color);
	}
}



Coord lengthEndPoint(Coord startingPoint, int degree, int length){
	Coord endPoint;
	
	endPoint.x = int((double)length * cos((double)degree * PI / (double)180)) + startingPoint.x;
	endPoint.y = int((double)length * sin((double)degree * PI / (double)180)) + startingPoint.y;
	
	return endPoint;
}
