#include "box.hpp"
#include <graphics.h>

Box::Box(int _x,int _y, int _l,int _p, int _color,int _cFill)
{
    x = _x;
    y = _y;
    lebar = _l;
    panjang = _p;
    color =_color;
    cFill =_cFill;
}
Box::~Box(){ " this is a destructor ";}

int Box::getX() const { return x; }
int Box::getY() const { return y; }
int Box::getL() const { return lebar; }
int Box::getP() const { return panjang; }

int Box::getOutlineColor() const { return color; }
int Box::getFillColor() const { return cFill; }
int Box::getMaxX() const { return x + y; }
int Box::getMaxY() const { return lebar + panjang; }

void Box::setX(int _x) { x = _x; }
void Box::setY(int _y) { y = _y; }
void Box::setLebar(int _l) { lebar = _l; }
void Box::setPanjang(int _p) { panjang = _p; }

void Box::setXY(int _x, int _y){ x = _x; y = _y;}
void Box::setDimensi(int _l, int _p){ lebar = _l; panjang = _p;}

void Box::setOutlineColor(int _color) { color = _color; }
void Box::setFillColor(int _cFill) { cFill = _cFill; }
void Box::setColor(int _color, int _cFill) { color= _color, cFill = _cFill; }

void Box::drawRec(int color, int cFill) const
	{
		setcolor(color);
		setfillstyle(SOLID_FILL, cFill);
		bar(x,y,lebar,panjang);
	}

void Box::unDrawRec() const
    {
    	setcolor(0);
		setfillstyle(SOLID_FILL, 0);
    	bar(x,y,lebar,panjang);
    } 

void Box::show()const{drawRec(color,cFill);}
void Box::clear()const{unDrawRec();}

void Box::move(int dx,int dy)
{
    clear();
    x += dx;
	y += dy;
    show();
}