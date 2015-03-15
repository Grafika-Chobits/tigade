#include "clip3d.h"

//xmin = sisi kiri dari clip
//ymin = sisi atas dari clip
//xmax = sisi kanan dari clip
//ymax = sisi bawah dari clip

//TOP = 	1000
//BOTTOM = 	0100
//LEFT = 	0001
//RIGHT = 	0010
//outcode compute(int x, int y , int xmin1, int ymin1, int xmax1, int ymin2, int xmax2, int ymax2, int xmin2, int ymax1)
outcode compute(int x, int y , Coord kiriAtas, Coord kananAtas, Coord kiriBawah, Coord kananBawah)
{
	float m;
	outcode oc=0;
	int xmin, ymin, xmax, ymax;
	// printf("kiriAtas.x = %d\n", kiriAtas.x);
	// printf("kiriBawah.x = %d\n", kiriBawah.x);

	//mengatur kiri
	if(kiriAtas.x == kiriBawah.x)
	{
		xmin = kiriAtas.x;
		if(x<xmin)
			oc|=LEFT;
	}
	else
	{
		xmin = kiriAtas.x > kiriBawah.x? kiriAtas.x:kiriBawah.x;
		ymin = kiriAtas.x > kiriBawah.x? kiriAtas.y:kiriBawah.y;
		if(x < xmin)
		{
			m = (kiriBawah.y - kiriAtas.y) / (kiriBawah.x - kiriAtas.x);
			// printf("m dengan x < xmin = %f\n", m);
			// cari xPotong
			int xPotong = round((y - ymin) / m + xmin);
			if(x < xPotong)
				oc|=LEFT;
		}
	}

	if(kananAtas.x == kananBawah.x)
	{
		xmax = kananAtas.x;
		if(x>xmax)
			oc|=RIGHT;
	}
	else
	{
		xmax = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
		ymax = kananAtas.x < kananBawah.x? kananAtas.y:kananBawah.y;
		if(x > xmax)
		{
			m = (kananBawah.y - kananAtas.y) / (kananBawah.x - kananAtas.x);
			// printf("m dengan x > xmax = %f\n", m);
			// int xPotong = round(m * (y - ymax) + xmax);
			int xPotong = round( ((y - ymax) / m) + xmax );
			// printf("y = %d\n", y);
			// printf("ymax = %d\n", ymax);
			// printf("xmax = %d\n", xmax);
			// printf("xPotong = %d\n", xPotong);
			if(x > xPotong) // xPotong = 1200, x = 700
			{
				oc|=RIGHT;
			}
		}
	}
	
	//ymin
	if(kiriAtas.y == kananAtas.y)
	{
		// printf("MASUK  kiriAtas.y == kananAtas.y\n");
		ymin = kiriAtas.y;
		if(y<ymin)
			oc|=TOP;
	}
	else
	{
		ymin = kiriAtas.y > kananAtas.y? kiriAtas.y:kananAtas.y;
		xmin = kiriAtas.y > kananAtas.y? kiriAtas.x:kananAtas.x;
		if(y < ymin) 
		{
			// printf("MASUK Y < YMIN\n");
			m = (kananAtas.y - kiriAtas.y) / (kananAtas.x - kiriAtas.x);
			//cari titik potong
			int yPotong = round(m * (x - xmin) + ymin);

			//Cek ada dimana y dilihat dari titik potong.
			//Apakah ada di atas yPotong
			if(y < yPotong)
			{
				// printf("Masuk y < yPotong dengan oc = %d\n", oc);
				oc|=TOP;
			}
		}
	}

	//Ngurus y max
	if(kiriBawah.y == kananBawah.y)
	{
		ymax = kiriBawah.y;
		
		if(y>ymax)
			oc|=BOTTOM;
	}
	else
	{
		ymax = kiriBawah.y < kananBawah.y? kiriBawah.y:kananBawah.y;
		xmax = kiriBawah.y < kananBawah.y? kiriBawah.x:kananBawah.x;
		
		if(y > ymax)
		{
			// printf("MASUK Y > YMAX\n");
			m = (kananBawah.y - kiriBawah.y) / (kananBawah.x - kiriBawah.x);
			//Cari titik potong
			int yPotong = round(m * (x - xmax) + ymax);

			//Cek ada dimana y dilihat dari titik potong y.
			//Apakah y ada di bawah yPotong
			if(y > yPotong)
			{
				// printf("Masuk y > yPotong dengan oc = %d\n", oc);
				oc|=BOTTOM;
			}
		}
	}

	// printf("oc = %d\n", oc);
	return oc;
}

//Urutan kotaknya: kiriAtas, kananAtas, kiriBawah, kananBawah
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
		printf("Mulai operasi garis ke %d\n", i);
		x1 = StartX(lines.at(i));
		y1 = StartY(lines.at(i));
		x2 = EndX(lines.at(i));
		y2 = EndY(lines.at(i));
		bool accept = false, done=false;double m;
		outcode o1,o2,ot;
		o1=compute(x1,y1, kiriAtas, kananAtas, kiriBawah, kananBawah);
		o2=compute(x2,y2, kiriAtas, kananAtas, kiriBawah, kananBawah);
		printf("oc2 = %d\n", o2);
		if(o1&o2) //kalo garisnya sama sekali gak berpotongan
		{
			clippedLines.push_back(line(coord(x1,y1),coord(x2,y2)));
		}
		else if(o1 == 0 && o2 != 0 || o1 != 0 && o2 == 0) //Jika salah satu berpotongan
		{
			int x,y;
			ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
							//Jika o1 != 0, ot = o1, else ot = o2
							//Titik yang diluar udah ketemu
			if(ot == TOP)
				//Cari titik potong dengan garis atas
			{
				if(kiriAtas.y == kananAtas.y)
				{
					y=ymin1;
					x = x1 + (y - y1) * (x2-x1) / (y2-y1);
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
					if(x1 != x2) //Jika garisnya tidak tegak lurus
					{
						x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
					else //Jika garisnya tegak lurus
					{
						x = x1;
						y = (float)kananAtas.y + m2 * ((float)x - (float)kananAtas.x);
					}
					
				}
			}
			else if(ot == RIGHT)
				//Cari titik potong dengan garis kanan
			{
				if(kananAtas.x == kananBawah.x)
				{
					x=xmax1;
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
				}
				y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
				
			}
			else if(ot == BOTTOM)
				//Cari titik potong dengan garis bawah
			{
				if(kiriBawah.y == kananBawah.y)
				{
					y=ymax1;
					x = x1 + (ymax1 - y1) * (x2 - x1) / (y2-y1);
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);

					if(x1 != x2) //Jika garisnya tidak tegak lurus
					{
						x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananBawah.x + (float)kananBawah.y) / (m1 - m2) ); 
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
					else //Jika garisnya tegak lurus
					{
						x = x1;
						y = (float)kananBawah.y + m2 * ((float)x - (float)kananBawah.x);
					}

					
				}
			}
			else if(ot == LEFT)
				//Cari titik potong dengan garis kiri
			{
				if(kiriAtas.x == kiriBawah.x)
					x=xmin1;
				else
				{
					double m1 = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
					double m2 = ((double)kiriBawah.y - (double)kiriAtas.y) / ((double)kiriBawah.x - (double)kiriAtas.x);
					x = round( (m1*(double)x1 - (double)y1 - m2 * (double)kiriAtas.x + (double)kiriAtas.y) / (m1 - m2) );
				}
				y = round((double)y1 + ((double)x - (double)x1) * ((double)y2 - (double)y1) / ((double)x2 - (double)x1));
			}
			else if(ot == TOPRIGHT)
			{
				printf("masuk top right\n");
				float mKanan = 0, mAtas = 0, xRight = 0, yRight = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kananAtas.x != kananBawah.x) //Jika sisi kanannya tidak tegak lurus
				{
					mKanan = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananAtas.x + (float)kananAtas.y) / (m1 - mKanan));
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
					int ymin = kananAtas.y < kananBawah.y? kananAtas.y:kananBawah.y;
					int xmax = kananAtas.x > kananBawah.x? kananAtas.x:kananBawah.x;
					int ymax = kananAtas.y > kananBawah.y? kananAtas.y:kananBawah.y;

					if(xRight > xmin && xRight < xmax && yRight > ymin && yRight < ymax)
						//Berpotongan dengan kanan
					{
						x = xRight;
						y = yRight;
					}
					else //berpotongan dengan atas
					{
						mAtas= ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
						x = round( (m1*(float)x1 - (float)y1 - mAtas * (float)kananAtas.x + (float)kananAtas.y) / (m1 - mAtas));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kanannya tegak lurus
				{
					
					xRight =xmax1;
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yRight > kananAtas.y && yRight < kananBawah.y) //jika garis memotong kanan
					{
						x = xRight;
						y = yRight;
					}
					else //jika garis memotong atas
					{
						if(kiriAtas.y == kananAtas.y)
						{
							y=ymin1;
							x = round((float)x1 + ((float)ymin1 - (float)y1) * ((float)x2-(float)x1) / ((float)y2-(float)y1));
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
							x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
				
			}

			else if(ot == BOTTOMRIGHT)
			{
				printf("Masuk BOTTOMRIGHT\n");
				float mKanan = 0, mBawah = 0, xRight = 0, yRight = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kananAtas.x != kananBawah.x) //Jika sisi kanannya tidak tegak lurus
				{
					mKanan = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mKanan));
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
					int ymin = kananAtas.y < kananBawah.y? kananAtas.y:kananBawah.y;
					int xmax = kananAtas.x > kananBawah.x? kananAtas.x:kananBawah.x;
					int ymax = kananAtas.y > kananBawah.y? kananAtas.y:kananBawah.y;

					if(xRight > xmin && xRight < xmax && yRight > ymin && yRight < ymax)
						//Berpotongan dengan kanan
					{
						printf("Berpotongan dengan kanan\n");
						x = xRight;
						y = yRight;
					}
					else //berpotongan dengan bawah
					{
						printf("Berpotongan dengan bawah\n");
						mBawah = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
						x = round( (m1*(float)x1 - (float)y1 - mBawah * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mBawah));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kanannya tegak lurus
				{
					
					xRight =xmax1;
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yRight > kananAtas.y && yRight < kananBawah.y) //jika garis memotong kanan
					{
						x = xRight;
						y = yRight;
					}
					else //jika garis memotong bawah
					{
						if(kiriBawah.y == kananBawah.y) //Jika garis bawahnya sejajar sumbu x
						{
							y=ymax1;
							x = round((float)x1 + ((float)y - (float)y1) * ((float)x2-(float)x1) / ((float)y2-(float)y1));
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
							//x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
			}

			else if(ot == BOTTOMLEFT)
			{
				float mLeft = 0, mBawah = 0, xLeft = 0, yLeft = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kiriAtas.x != kiriBawah.x) //Jika sisi kirinya tidak tegak lurus
				{
					mLeft = ((float)kiriBawah.y - (float)kiriAtas.y) / ((float)kiriBawah.x - (float)kiriAtas.x);
					//xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mKanan));
					xLeft  = round( (m1*(float)x1 - (float)y1 - mLeft * (float)kiriBawah.x + (float)kiriBawah.y) / (m1 - mLeft));
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kiriAtas.x < kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymin = kiriAtas.y < kiriBawah.y? kiriAtas.y:kiriBawah.y;
					int xmax = kiriAtas.x > kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymax = kiriAtas.y > kiriBawah.y? kiriAtas.y:kiriBawah.y;
					printf("xmin = %d\n", xmin);
					printf("xmax = %d\n", xmax);
					printf("xLEFT = %f\n", xLeft);
					printf("ymin = %d\n", ymin);
					printf("ymax = %d\n", ymax);
					printf("yLEFT = %f\n", yLeft);

					if(xLeft > xmin && xLeft < xmax && yLeft > ymin && yLeft < ymax)
						//Berpotongan dengan kiri
					{
						printf("Berpotongan dengan kiri\n");
						x = xLeft;
						y = yLeft;
					}
					else //berpotongan dengan bawah
					{
						printf("Berpotongan dengan bawah\n");
						mBawah = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
						x = round( (m1*(float)x1 - (float)y1 - mBawah * (float)kiriBawah.x + (float)kiriBawah.y) / (m1 - mBawah));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kirinya tegak lurus
				{
					
					xLeft =xmin1;
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yLeft > kiriAtas.y && yLeft < kiriBawah.y) //jika garis memotong kiri
					{
						x = xLeft;
						y = yLeft;
					}
					else //jika garis memotong bawah
					{
						if(kiriBawah.y == kananBawah.y) //Jika garis bawahnya sejajar sumbu x
						{
							y=ymax1;
							x = round((float)x1 + ((float)y - (float)y1) * ((float)x2-(float)x1) / ((float)y2-(float)y1));
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
							//x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
			}

			else if(ot == TOPLEFT)
			{
				float mLeft = 0, mAtas = 0, xLeft = 0, yLeft = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kiriAtas.x != kiriBawah.x) //Jika sisi kirinya tidak tegak lurus
				{
					mLeft = ((float)kiriBawah.y - (float)kiriAtas.y) / ((float)kiriBawah.x - (float)kiriAtas.x);
					//xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mKanan));
					xLeft  = round( (m1*(float)x1 - (float)y1 - mLeft * (float)kiriAtas.x + (float)kiriAtas.y) / (m1 - mLeft));
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kiriAtas.x < kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymin = kiriAtas.y < kiriBawah.y? kiriAtas.y:kiriBawah.y;
					int xmax = kiriAtas.x > kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymax = kiriAtas.y > kiriBawah.y? kiriAtas.y:kiriBawah.y;
					printf("xmin = %d\n", xmin);
					printf("xmax = %d\n", xmax);
					printf("xLEFT = %f\n", xLeft);
					printf("ymin = %d\n", ymin);
					printf("ymax = %d\n", ymax);
					printf("yLEFT = %f\n", yLeft);

					if(xLeft > xmin && xLeft < xmax && yLeft > ymin && yLeft < ymax)
						//Berpotongan dengan kiri
					{
						printf("Berpotongan dengan kiri\n");
						x = xLeft;
						y = yLeft;
					}
					else //berpotongan dengan atas
					{
						printf("Berpotongan dengan bawah\n");
						mAtas = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
						x = round( (m1*(float)x1 - (float)y1 - mAtas * (float)kiriAtas.x + (float)kiriAtas.y) / (m1 - mAtas));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kirinya tegak lurus
				{
					
					xLeft =xmin1;
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yLeft > kiriAtas.y && yLeft < kiriBawah.y) //jika garis memotong kiri
					{
						x = xLeft;
						y = yLeft;
					}
					else //jika garis memotong atas
					{
						if(kiriAtas.y == kananAtas.y) //Jika garis atasnya sejajar sumbu x
						{
							y=ymin1;
							x =round ((float)x1 + ((float)y - (float)y1) * ((float)x2-(float)x1) / ((float)y2-(float)y1));
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
							//x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
			}

			if(ot==o1) //Jika yang diluar adalah o1
			{
				x2=x;
				y2=y;
				// printf("x = %d\n", x2);
				// printf("y = %d\n", y2);
				// o1=compute(x1,y1,kiriAtas, kananAtas, kiriBawah, kananBawah);
			}
			else
			{
				x1=x;
				y1=y;
				// o2=compute(x2,y2,kiriAtas, kananAtas, kiriBawah, kananBawah);
			}
			clippedLines.push_back(line(coord(x1, y1),coord(x2,y2)));
		}
		else //2 titik diluar kotak, tapi garisnya memotong kotak
		{

		}

		// do{

		// 	if(!(o1 | o2))
		// 	{
		// 		done=true;
		// 		accept=true;
		// 	}
		// 	else if(o1&o2) //ini kalo garisnya sama sekali gak berpotongan
		// 	{
		// 		done=true;
		// 	}
		// 	else
		// 	{
		// 		int x,y;
		// 		ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
		// 		if(ot & TOP)			// point is above the clip rectangle
		// 		{
		// 			y=ymin1;
		// 			x = x1 + (ymin1 - y1) * (x2-x1) / (y2-y1);
		// 		} 
		// 		else if(ot & BOTTOM) 	// point is below the clip rectangle
		// 		{
		// 			y=ymax1;
		// 			x = x1 + (ymax1 - y1) * (x2 - x1) / (y2-y1);
		// 		}
		// 		else if(ot & RIGHT)		// point is to the right of clip rectangle //jika ot & RIGHT != 0
		// 		{
		// 			if(kiriAtas.x == kiriBawah.x && kananAtas.x == kananBawah.x)
		// 				x=xmax1;
		// 			else
		// 			{
		// 				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
		// 				float m2 = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
		// 				x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
		// 				printf("x = %d\n", x);
		// 			}
		// 			y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
		// 		}
		// 		else if(ot & LEFT)		// point is to the left of clip rectangle
		// 		{
		// 			x=xmin1;
		// 			//x = x1 + (ymin1 - y1) * (x2 - x1) / (y2 - y1);
		// 			y = y1 + (xmin1 - x1) * (y2 - y1) / (x2 - x1);
		// 		}
		// 		if(ot==o1) //Jika yang diluar adalah o1
		// 		{
		// 			x1=x;
		// 			y1=y;
		// 			o1=compute(x1,y1,kiriAtas, kananAtas, kiriBawah, kananBawah);
		// 		}
		// 		else
		// 		{
		// 			x2=x;
		// 			y2=y;
		// 			o2=compute(x2,y2,kiriAtas, kananAtas, kiriBawah, kananBawah);
		// 		}
		// 	}
		// }while(done==false);

		// if(accept==true)
		// {
		// 	clippedLines.push_back(line(coord(x1, y1),coord(x2,y2)));
		// }
		printf("Selesai memproses garis ke %d\n", i);
	}
	drawFreeSquare(canvas, kiriAtas, kananAtas, kiriBawah, kananBawah, rgb(255,255,0));
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

//Urutan kotaknya: kiriAtas, kananAtas, kiriBawah, kananBawah
std::vector<Line> cohen_sutherland(std::vector<Line> lines, Coord kiriAtas, Coord kananAtas, 
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
	clippedLines.push_back(line(kiriAtas, kananAtas));
	clippedLines.push_back(line(kiriBawah, kananBawah));
	clippedLines.push_back(line(kiriAtas, kiriBawah));
	clippedLines.push_back(line(kananAtas, kananBawah));
	
	for (int i = 0; i < lines.size(); i++)
	{
		printf("Mulai operasi garis ke %d\n", i);
		x1 = StartX(lines.at(i));
		y1 = StartY(lines.at(i));
		x2 = EndX(lines.at(i));
		y2 = EndY(lines.at(i));
		bool accept = false, done=false;double m;
		outcode o1,o2,ot;
		o1=compute(x1,y1, kiriAtas, kananAtas, kiriBawah, kananBawah);
		o2=compute(x2,y2, kiriAtas, kananAtas, kiriBawah, kananBawah);
		printf("oc2 = %d\n", o2);
		if(o1&o2) //kalo garisnya sama sekali gak berpotongan
		{
			clippedLines.push_back(line(coord(x1,y1),coord(x2,y2)));
		}
		else if(o1 == 0 && o2 != 0 || o1 != 0 && o2 == 0) //Jika salah satu berpotongan
		{
			int x,y;
			ot=o1?o1:o2; //Nyari point mana yang ada di luar kotak, kemudian masukin ke ot
							//Jika o1 != 0, ot = o1, else ot = o2
							//Titik yang diluar udah ketemu
			if(ot == TOP)
				//Cari titik potong dengan garis atas
			{
				if(kiriAtas.y == kananAtas.y)
				{
					y=ymin1;
					x = x1 + (y - y1) * (x2-x1) / (y2-y1);
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
					if(x1 != x2) //Jika garisnya tidak tegak lurus
					{
						x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
					else //Jika garisnya tegak lurus
					{
						x = x1;
						y = (float)kananAtas.y + m2 * ((float)x - (float)kananAtas.x);
					}
					
				}
			}
			else if(ot == RIGHT)
				//Cari titik potong dengan garis kanan
			{
				if(kananAtas.x == kananBawah.x)
				{
					x=xmax1;
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
				}
				y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
				
			}
			else if(ot == BOTTOM)
				//Cari titik potong dengan garis bawah
			{
				if(kiriBawah.y == kananBawah.y)
				{
					y=ymax1;
					x = x1 + (ymax1 - y1) * (x2 - x1) / (y2-y1);
				}
				else
				{
					float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
					float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);

					if(x1 != x2) //Jika garisnya tidak tegak lurus
					{
						x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananBawah.x + (float)kananBawah.y) / (m1 - m2) ); 
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
					else //Jika garisnya tegak lurus
					{
						x = x1;
						y = (float)kananBawah.y + m2 * ((float)x - (float)kananBawah.x);
					}

					
				}
			}
			else if(ot == LEFT)
				//Cari titik potong dengan garis kiri
			{
				if(kiriAtas.x == kiriBawah.x)
					x=xmin1;
				else
				{
					double m1 = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
					double m2 = ((double)kiriBawah.y - (double)kiriAtas.y) / ((double)kiriBawah.x - (double)kiriAtas.x);
					x = round( (m1*(double)x1 - (double)y1 - m2 * (double)kiriAtas.x + (double)kiriAtas.y) / (m1 - m2) );
				}
				y = round((double)y1 + ((double)x - (double)x1) * ((double)y2 - (double)y1) / ((double)x2 - (double)x1));
			}
			else if(ot == TOPRIGHT)
			{
				printf("masuk top right\n");
				float mKanan = 0, mAtas = 0, xRight = 0, yRight = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kananAtas.x != kananBawah.x) //Jika sisi kanannya tidak tegak lurus
				{
					mKanan = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananAtas.x + (float)kananAtas.y) / (m1 - mKanan));
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
					int ymin = kananAtas.y < kananBawah.y? kananAtas.y:kananBawah.y;
					int xmax = kananAtas.x > kananBawah.x? kananAtas.x:kananBawah.x;
					int ymax = kananAtas.y > kananBawah.y? kananAtas.y:kananBawah.y;

					if(xRight > xmin && xRight < xmax && yRight > ymin && yRight < ymax)
						//Berpotongan dengan kanan
					{
						x = xRight;
						y = yRight;
					}
					else //berpotongan dengan atas
					{
						mAtas= ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
						x = round( (m1*(float)x1 - (float)y1 - mAtas * (float)kananAtas.x + (float)kananAtas.y) / (m1 - mAtas));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kanannya tegak lurus
				{
					
					xRight =xmax1;
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yRight > kananAtas.y && yRight < kananBawah.y) //jika garis memotong kanan
					{
						x = xRight;
						y = yRight;
					}
					else //jika garis memotong atas
					{
						if(kiriAtas.y == kananAtas.y)
						{
							y=ymin1;
							x = x1 + (ymin1 - y1) * (x2-x1) / (y2-y1);
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriAtas.y - (float)kananAtas.y) / ((float)kiriAtas.x - (float)kananAtas.x);
							x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
				
			}

			else if(ot == BOTTOMRIGHT)
			{
				printf("Masuk BOTTOMRIGHT\n");
				float mKanan = 0, mBawah = 0, xRight = 0, yRight = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kananAtas.x != kananBawah.x) //Jika sisi kanannya tidak tegak lurus
				{
					mKanan = ((float)kananBawah.y - (float)kananAtas.y) / ((float)kananBawah.x - (float)kananAtas.x);
					xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mKanan));
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kananAtas.x < kananBawah.x? kananAtas.x:kananBawah.x;
					int ymin = kananAtas.y < kananBawah.y? kananAtas.y:kananBawah.y;
					int xmax = kananAtas.x > kananBawah.x? kananAtas.x:kananBawah.x;
					int ymax = kananAtas.y > kananBawah.y? kananAtas.y:kananBawah.y;

					if(xRight > xmin && xRight < xmax && yRight > ymin && yRight < ymax)
						//Berpotongan dengan kanan
					{
						printf("Berpotongan dengan kanan\n");
						x = xRight;
						y = yRight;
					}
					else //berpotongan dengan bawah
					{
						printf("Berpotongan dengan bawah\n");
						mBawah = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
						x = round( (m1*(float)x1 - (float)y1 - mBawah * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mBawah));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kanannya tegak lurus
				{
					
					xRight =xmax1;
					yRight = round((float)y1 + ((float)xRight - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yRight > kananAtas.y && yRight < kananBawah.y) //jika garis memotong kanan
					{
						x = xRight;
						y = yRight;
					}
					else //jika garis memotong bawah
					{
						if(kiriBawah.y == kananBawah.y) //Jika garis bawahnya sejajar sumbu x
						{
							y=ymax1;
							x = x1 + (y - y1) * (x2-x1) / (y2-y1);
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
							//x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
			}

			else if(ot == BOTTOMLEFT)
			{
				float mLeft = 0, mBawah = 0, xLeft = 0, yLeft = 0;
				float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
				if(kiriAtas.x != kiriBawah.x) //Jika sisi kirinya tidak tegak lurus
				{
					mLeft = ((float)kiriBawah.y - (float)kiriAtas.y) / ((float)kiriBawah.x - (float)kiriAtas.x);
					//xRight = round( (m1*(float)x1 - (float)y1 - mKanan * (float)kananBawah.x + (float)kananBawah.y) / (m1 - mKanan));
					xLeft  = round( (m1*(float)x1 - (float)y1 - mLeft * (float)kiriBawah.x + (float)kiriBawah.y) / (m1 - mLeft));
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));

					int xmin = kiriAtas.x < kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymin = kiriAtas.y < kiriBawah.y? kiriAtas.y:kiriBawah.y;
					int xmax = kiriAtas.x > kiriBawah.x? kiriAtas.x:kiriBawah.x;
					int ymax = kiriAtas.y > kiriBawah.y? kiriAtas.y:kiriBawah.y;
					printf("xmin = %d\n", xmin);
					printf("xmax = %d\n", xmax);
					printf("xLEFT = %f\n", xLeft);
					printf("ymin = %d\n", ymin);
					printf("ymax = %d\n", ymax);
					printf("yLEFT = %f\n", yLeft);

					if(xLeft > xmin && xLeft < xmax && yLeft > ymin && yLeft < ymax)
						//Berpotongan dengan kiri
					{
						printf("Berpotongan dengan kiri\n");
						x = xLeft;
						y = yLeft;
					}
					else //berpotongan dengan bawah
					{
						printf("Berpotongan dengan bawah\n");
						mBawah = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
						x = round( (m1*(float)x1 - (float)y1 - mBawah * (float)kiriBawah.x + (float)kiriBawah.y) / (m1 - mBawah));
						y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					}
				}
				else //Sisi kirinya tegak lurus
				{
					
					xLeft =xmin1;
					yLeft = round((float)y1 + ((float)xLeft - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
					if(yLeft > kiriAtas.y && yLeft < kiriBawah.y) //jika garis memotong kiri
					{
						x = xLeft;
						y = yLeft;
					}
					else //jika garis memotong bawah
					{
						if(kiriBawah.y == kananBawah.y) //Jika garis bawahnya sejajar sumbu x
						{
							y=ymax1;
							x = x1 + (y - y1) * (x2-x1) / (y2-y1);
						}
						else
						{
							float m1 = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
							float m2 = ((float)kiriBawah.y - (float)kananBawah.y) / ((float)kiriBawah.x - (float)kananBawah.x);
							//x = round( (m1*(float)x1 - (float)y1 - m2 * (float)kananAtas.x + (float)kananAtas.y) / (m1 - m2) ); 
							y = round((float)y1 + ((float)x - (float)x1) * ((float)y2 - (float)y1) / ((float)x2 - (float)x1));
						}
					}

				}
			}

			else if(ot == TOPLEFT)
			{

			}

			if(ot==o1) //Jika yang diluar adalah o1
			{
				x2=x;
				y2=y;
				// printf("x = %d\n", x2);
				// printf("y = %d\n", y2);
				// o1=compute(x1,y1,kiriAtas, kananAtas, kiriBawah, kananBawah);
			}
			else
			{
				x1=x;
				y1=y;
				// o2=compute(x2,y2,kiriAtas, kananAtas, kiriBawah, kananBawah);
			}
			clippedLines.push_back(line(coord(x1, y1),coord(x2,y2)));
		}
		else //2 titik diluar kotak, tapi garisnya memotong kotak
		{

		}

		printf("Selesai memproses garis ke %d\n", i);
	}

	return clippedLines;
}
