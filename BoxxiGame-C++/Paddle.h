#ifndef PADDLE_H
#define PADDLE_H
#include "Point.h"

class Paddle{
	protected :
		Point kiriAtas, bawahKanan;
		int color, dx;
		
	public :
		Paddle(int x1=0, int y1=0, int x2=0, int y2=0, int c=WHITE, int _dx=0) : kiriAtas(x1,y1), bawahKanan(x2,y2), color(c)
		{setDirection(_dx);}
		
		void setDirection(int _dx=0){
			dx = _dx;
		}
		void setPosition(int _x, int _y){
			kiriAtas.set(_x,_y);
			bawahKanan.set(_x+200,_y+50);
		}
		
		
		void setColor(int c){
			color = c;
		}
		
		void changeHorizontalDirection(){
			dx = -dx;
		}
		
		void display(int color) const{ 
			setcolor(color);
		  	setfillstyle(SOLID_FILL, color);
		  	bar(kiriAtas.getX(),kiriAtas.getY(),bawahKanan.getX(),bawahKanan.getY());
		}
		
		void draw() const { display(color); }
		void undraw() const { display(BLACK); }
		
		
		void move(int dx){
			undraw();
			kiriAtas.set(kiriAtas.getX()+dx,kiriAtas.getY());
			bawahKanan.set(bawahKanan.getX()+dx,bawahKanan.getY());
			draw();
			delay(100);
		}
		
		
		int getTop() const {return kiriAtas.getY();}
		int getBott() const {return bawahKanan.getY(); }
		int getLeft() const {return kiriAtas.getX(); }
		int getRight() const {return bawahKanan.getX(); }		
};
#endif
