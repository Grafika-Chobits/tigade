#include "clip3d.h"

//xmin = sisi kiri dari clip
//ymin = sisi atas dari clip
//xmax = sisi kanan dari clip
//ymax = sisi bawah dari clip

//TOP = 	1000
//BOTTOM = 	0100
//LEFT = 	0001
//RIGHT = 	0010
outcode compute(int x, int y , int xmin1, int ymin1, int xmax1, int ymin2, int xmax2, int ymax2, int xmin2, int ymax1)
{
	float m;
	outcode oc=0;
	
	if(xmin1 == xmin2 && xmin1 == xmin2){
		if(x<xmin1)
			oc|=LEFT;
		else if(x>xmax1)
			oc|=RIGHT;
	}
	else
	{
		int xmin = xmin1 > xmin2? xmin1:xmin2;
		int ymin = xmin1 > xmin2? ymin1:ymin2;
		int xmax = xmax1 < xmax2? xmax1:xmax2;
		int ymax = xmax1 < xmax2? ymax1:ymax2;
		if(x < xmin)
		{
			m = (xmin2 - xmin1) / (ymax1 - ymin1);
			//cari xPotong
			int xPotong = round(m * (y - ymin) + xmin);
			if(x < xPotong)
				oc|=LEFT;
		}
		else if(x > xmax)
		{
			m = (xmax2 - xmax1) / (ymax2 - ymin2);
			int xPotong = round(m * (y - ymax) + xmax);
			if(x > xPotong)
			{
				oc|=RIGHT;
			}
		}
	}
	
	if(ymin1 == ymin2 && ymax1 == ymax2)
	{
		if(y<ymin1)
			oc|=TOP;
		else if(y>ymax1)
			oc|=BOTTOM;
	}
	else
	{
		int ymin = ymin1 > ymin2? ymin1:ymin2;
		int xmin = ymin1 > ymin2? xmin1:xmin2;
		int ymax = ymax1 < ymax2? ymax1:ymax2;
		int xmax = ymax1 < ymax2? xmax1:xmax2;
		if(y < ymin) 
		{
			m = (xmax1 - xmin1) / (ymin2 - ymin1);
			//cari titik potong
			int yPotong = round(m * (x - xmin) + ymin);

			//Cek ada dimana y dilihat dari titik potong.
			//Apakah ada di atas yPotong
			if(y < yPotong)
				oc|=TOP;
		}
		else if(y > ymax)
		{
			m = (xmax2 - xmin2) / (ymax2 - ymax1);
			//Cari titik potong
			int yPotong = round(m * (x - xmax) + ymax);

			//Cek ada dimana y dilihat dari titik potong y.
			//Apakah y ada di bawah yPotong
			if(y > yPotong)
				oc|=BOTTOM;
		}
		
	}

	return oc;
}

//Urutan kotaknya: KiriAtas, kananAtas, kiriBawah, kananBawah
std::vector<Line> cohen_sutherland(Frame *canvas, std::vector<Line> lines, Coord kiriAtas, Coord kananAtas, 
																			Coord kiriBawah, Coord kananBawah, RGB color)
{
	int xmin1 = kiriAtas.x;
	int xmin2 = kiriBawah.x;
	int ymin1 = kiriAtas.y;
	int ymin2 = kananAtas.y;
	int xmax1 = kananAtas.x;
	int xmax2 = kananBawah.x;
	int ymax1 = kiriBawah.y;
	int ymax2 = kananBawah.y;
	
	int x1, y1, x2, y2;

	std::vector<Line> clippedLines;
	for (int i = 0; i < lines.size(); i++)
	{
		x1 = StartX(lines.at(i));
		y1 = StartY(lines.at(i));
		x2 = EndX(lines.at(i));
		y2 = EndY(lines.at(i));
		bool accept = false, done=false;double m;
		outcode o1,o2,ot;
		o1=compute(x1,y1, xmin1, ymin1, xmin2, ymin2, xmax1, ymax1, xmax2, ymax2);
		o2=compute(x2,y2, xmin1, ymin1, xmin2, ymin2, xmax1, ymax1, xmax2, ymax2);
		do{

			if(!(o1 | o2))
			{
				done=true;
				accept=true;
			}
			else if(o1&o2)
			{
				done=true;
			}
			else
			{
				int x,y;
				ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
				if(ot & TOP)			// point is above the clip rectangle
				{
					y=ymin1;
					x = x1 + (ymin1 - y1) * (x2-x1) / (y2-y1);
				} 
				else if(ot & BOTTOM) 	// point is below the clip rectangle
				{
					y=ymax1;
					x = x1 + (ymax1 - y1) * (x2 - x1) / (y2-y1);
				}
				else if(ot & RIGHT)		// point is to the right of clip rectangle
				{
					x=xmax1;
					y = y1 + (xmax1 - x1) * (y2 - y1) / (x2 - x1);
				}
				else if(ot & LEFT)		// point is to the left of clip rectangle
				{
					x=xmin1;
					//x = x1 + (ymin1 - y1) * (x2 - x1) / (y2 - y1);
					y = y1 + (xmin1 - x1) * (y2 - y1) / (x2 - x1);
				}
				if(ot==o1)
				{
					x1=x;
					y1=y;
					o1=compute(x1,y1,xmin1, ymin1, xmin2, ymin2, xmax1, ymax1, xmax2, ymax2);
				}
				else
				{
					x2=x;
					y2=y;
					o2=compute(x2,y2,xmin1, ymin1, xmin2, ymin2, xmax1, ymax1, xmax2, ymax2);
				}
			}
		}while(done==false);

		if(accept==true)
		{
			clippedLines.push_back(line(coord(x1 - xmin1, y1 - ymin1),coord(x2 - xmin1,y2 - ymin1)));
		}
		drawFreeSquare(canvas, coord(xmin1, ymin1), coord(xmax1, ymin2), coord(xmin2, ymax1), coord(xmax2,ymax2), rgb(255,255,0));
	}
	return clippedLines;
}


//Fungsi cohen di bawah ini cuma menggambar line yang masuk ke dia, tergantung di accept atau gak
//~ void cohen_sutherland(Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color)
//~ {
	//~ bool accept = false, done=false;double m;
	//~ outcode o1,o2,ot;
	//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
	//~ do{
//~ 
		//~ if(!(o1 | o2))
		//~ {
			//~ done=true;
			//~ accept=true;
		//~ }
		//~ else if(o1&o2)
		//~ {
			//~ done=true;
		//~ }
		//~ else
		//~ {
			//~ int x,y;
			//~ ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
			//~ if(ot & TOP)			// point is above the clip rectangle
			//~ {
				//~ y=ymin;
				//~ x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			//~ } 
			//~ else if(ot & BOTTOM) 	// point is below the clip rectangle
			//~ {
				//~ y=ymax;
				//~ x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			//~ }
			//~ else if(ot & RIGHT)		// point is to the right of clip rectangle
			//~ {
				//~ x=xmax;
				//~ y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			//~ }
			//~ else if(ot & LEFT)		// point is to the left of clip rectangle
			//~ {
				//~ x=xmin;
				//~ y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
//~ 
			//~ }
			//~ if(ot==o1)
			//~ {
				//~ x1=x;
				//~ y1=y;
				//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			//~ }
			//~ else
			//~ {
				//~ x2=x;
				//~ y2=y;
				//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			//~ }
		//~ }
	//~ }while(done==false);
//~ 
	//~ if(accept==true)
	//~ {
		//~ plotLine(frm, line(coord(x1,y1),coord(x2,y2)), color);
	//~ }
//~ }
//~ 
//~ 
//~ void cohen_sutherland(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
//~ {
	//~ bool accept = false, done=false;double m;
	//~ outcode o1,o2,ot;
	//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
	//~ do{
//~ 
		//~ if(!(o1 | o2))
		//~ {
			//~ done=true;
			//~ accept=true;
		//~ }
		//~ else if(o1&o2)
		//~ {
			//~ done=true;
		//~ }
		//~ else
		//~ {
			//~ int x,y;
			//~ ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
			//~ if(ot & TOP)			// point is above the clip rectangle
			//~ {
				//~ y=ymin;
				//~ x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			//~ } 
			//~ else if(ot & BOTTOM) 	// point is below the clip rectangle
			//~ {
				//~ y=ymax;
				//~ x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			//~ }
			//~ else if(ot & RIGHT)		// point is to the right of clip rectangle
			//~ {
				//~ x=xmax;
				//~ y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			//~ }
			//~ else if(ot & LEFT)		// point is to the left of clip rectangle
			//~ {
				//~ x=xmin;
				//~ y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
//~ 
			//~ }
			//~ if(ot==o1)
			//~ {
				//~ x1=x;
				//~ y1=y;
				//~ o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			//~ }
			//~ else
			//~ {
				//~ x2=x;
				//~ y2=y;
				//~ o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			//~ }
		//~ }
	//~ }while(done==false);
//~ 
	//~ if(accept==true)
	//~ {
		//~ printf("Point 1 = (%d, %d)\n",x1, y1);
		//~ printf("Point 2 = (%d, %d)\n",x2, y2);
	//~ }
	//~ else
	//~ {
		//~ printf("Not accepted\n");
		//~ printf("Point 1 = (%d, %d)\n",x1, y1);
		//~ printf("Point 2 = (%d, %d)\n",x2, y2);
	//~ }
//~ }
