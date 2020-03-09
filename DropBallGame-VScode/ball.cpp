#include "ball.hpp"
#include "Point.hpp"
//#include "window.hpp"
#include <graphics.h>

Ball::Ball(Point _p, int _r,int _dx, int _dy , int _cOutline , int _cFill)
{
	set(_p, _r, _dx, _dy, _cOutline, _cFill);
}
Ball::Ball(int _x, int _y, int _r,int _dx, int _dy , int _cOutline , int _cFill)
{
	set(Point(_x,_y) , _r, _dx, _dy, _cOutline, _cFill);	
}
Ball::~Ball() { "this is a destructor " ;}



void Ball::setPoint(Point value)
{
	p = value;
}
void Ball::setPoint(int x, int y)
{
	p.setPoint(x, y);	
}
void Ball::set(Point _p, int _r, int _dx, int _dy, int _cOutline, int _cFill)
{
	p = _p;
	r = _r;
	dx = _dx;
	dy = _dy;
	cOutline = _cOutline;
	cFill = _cFill;
}
void Ball::setX(int _x) { x = _x; } void Ball::setY(int _y) { y = _y; }
void Ball::setR(int _r) { r = _r; }
void Ball::setMove(int _dx, int _dy)
{
	dx = _dx;
	dy = _dy;
}
void Ball::setCout(int _cOutline) { cOutline = _cOutline; }
void Ball::setCFill(int _cFill) { cFill = _cFill; }
void Ball::setColor(int _cOutline, int _cFill) { cOutline = _cOutline, cFill = _cFill; }


Point Ball::getPoint() const { return p; }
int Ball::getX() const { return x; }
int Ball::getY() const { return y; }
int Ball::getR() const { return r; }
int Ball::getDx() const { return dx; }
int Ball::getDy() const { return dy; }
int Ball::getCOut() const { return cOutline; }
int Ball::getCFill() const { return cFill; }
int Ball::getBottom() const
{
	return p.getY() + r;	
}
int Ball::getLeft() const
{
	return p.getX() - r;	
}
int Ball::getRight() const
{
	return p.getX() + r;	
}

void Ball::draw() const 
{
	setcolor(cOutline);
	setfillstyle(SOLID_FILL, cFill);
	fillellipse(p.getX(), p.getY(), r, r);
}

void Ball::unDraw() const
{
    setcolor(0);
    setfillstyle(SOLID_FILL, 0);
	fillellipse(p.getX(), p.getY(), r, r);
}

void Ball::drawBasket() const 
{
    setcolor(cOutline);
    circle(p.getX(), p.getY(), r);
}

void Ball::unDrawBasket() const 
{
    setcolor(0);
    circle(p.getX(), p.getY(), r);
}

void Ball::move()
{
	unDraw();
	p.move(dx,dy);
	draw();
}

void Ball::moveBasket(int dx, int dy)
{
	x += dx;
	y += dy;
}