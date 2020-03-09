#include "Point.hpp"

Point::Point(int _x,int _y) : x(_x), y(_y){}

int Point::getX() const {return x;}
int Point::getY() const {return y;}

void Point::setX(int value) { x = value ;}
void Point::setY(int value) { y = value ;}

void Point::setPoint( int _x, int _y)
{
    x = _x;
    y = _y;
}

void Point::move(int dx, int dy)
{
	x += dx;
	y += dy;
}