#ifndef BALL_H
#define BALL_H
#include <graphics.h>
#include "Point.hpp"
//#include "window.hpp"

class Ball
{
  private:
	Point p;
	int x,y,r;
    int dx, dy;
	int cOutline;
	int cFill;


  public:
    Ball(Point _p = Point(0, 0), int _r = 0,int _dx = 0, int _dy = 0, int _cOutline = COLOR(255, 255, 255), int _cFill = 0);
	Ball(int _x=0, int _y=0, int _r = 0,int _dx = 0, int _dy = 0, int _cOutline = COLOR(255, 255, 255), int _cFill = 0);
    ~Ball();

	void setPoint(Point _p);
	void setPoint(int x, int y);
	void set(Point _p, int _r, int _dx, int _dy, int _cOutline, int _cFill);
	void setX(int _x); void setY(int _y);
	void setR(int _r);
	void setDx(int _dx);
	void setDy(int _dy);
	void setMove(int _dx, int _dy);
	void setCout(int _cOutline);
	void setCFill(int _cFill);
	void setColor(int _cOutline, int _cFill);
	
	Point getPoint() const;
	int getX() const; 
	int getY() const;
	int getR() const;
	int getDx() const;
	int getDy() const;
	int getCOut() const;
	int getCFill() const;
	int getBottom() const; // to get the most bottom value because it moves downward
	int getLeft() const;
	int getRight() const;

	void draw() const;

    void unDraw() const;

	void drawBasket() const;

    void unDrawBasket() const;

	void move();

	void moveBasket(int dx=0,int dy=0);
}; 
#endif