#ifndef BALL_H
#define BALL_H
#include "Point.h"
#include "Paddle.h"
#include "Score.h"


class Ball{
	protected:
		
		Point center;
		Paddle *paddle;
		
		Score score;
		int radius, color, dx, dy;
		int x1,x2,y1,y2;
	
	public:
		Ball(int _x=0, int _y=0, int r=50, int c=WHITE, int _dx=0, int _dy=0):center(_x,_y), radius(r), color(c)
		{setDirection(_dx, _dy);}
		
		void setDirection(int _dx=0, int _dy=0){
			dx = _dx; dy=_dy;
		}
		void setPosition(int _x, int _y){
			center.set(_x,_y);
		}
		
		
		void pointerP(Paddle *p)  {paddle = p;}
	
		int getX() const {return center.getX();}
		int getY() const {return center.getY();}
		
		
		
		void setColor(int c){
			color = c;
		}
		
		void changeHorizontalDirection(){
			dx = -dx;
		}
		
		void changeVerticalDirection(){
			dy = -dy;
		}
		
		void display(int color1) const{ 
			setcolor(color1);
		  	setfillstyle(SOLID_FILL, color1);
		  	fillellipse(center.getX(),center.getY(),radius,radius);
		}
		
		void draw() const { display(color); }
		void undraw() const { display(BLACK); }
		
		void move(int dx, int dy){
			undraw();
			center.set(center.getX()+dx,center.getY()+dy);
			draw();
			delay(70);
		}
		
		void move(){
			move(dx, dy);
		}
		
		bool intersect(int cx1, int cy1, int rx1, int ry1, int cx2, int cy2, int rx2, int ry2)
		{
			int dx = abs(cx2-cx1);
			int dy = abs(cy2-cy1);
			int sum_rx = rx1+rx2;
			int sum_ry = ry1+ry2;
	
			return ( (dx <=sum_rx) && (dy<=sum_ry) );
		}
		
		int intersectSide(int cx1, int cy1, int rx1, int ry1, int cx2, int cy2, int rx2, int ry2)
		{
			int dx = abs(cx2-cx1);
			int dy = abs(cy2-cy1);
			int sum_rx = rx1+rx2;
			int sum_ry = ry1+ry2;
	
			return abs(dy/dx);
		}
		
		bool sideWindow(){
			int screenRight = getmaxwidth()-40;
			int screenLeft  = 40;
			int ballRight = center.getX() + radius;
			int ballLeft = center.getX() - radius;
			
			return (ballLeft < screenLeft) || (ballRight > screenRight); 
		}

		bool upperWindow(){
			int screenTop    = 40;
			int ballTop   = center.getY() - radius;
						
			return (ballTop < screenTop); 
		}
		
	
		bool lowerWindow(){
			int screenBottom    = getmaxheight()-40;
			int ballBottom = center.getY() + radius;
						
			return (ballBottom < screenBottom); 
		}
		
		bool isHitPaddle(){
			int topPaddle = paddle->getTop();
			int bottomPaddle = paddle->getBott();
			int leftPaddle = paddle->getLeft();
			int rightPaddle = paddle->getRight();
			int width = abs(rightPaddle - leftPaddle);
			int height = abs(bottomPaddle - topPaddle);
			int ballVer = center.getY();
			int ballHorz = center.getX();
			
			return intersect(leftPaddle + width/2, topPaddle + height/2, width/2, height/2, ballHorz,ballVer,radius, radius);
		}
		
		
		
		void Action(){
			
			if ( sideWindow())
    			{changeHorizontalDirection();}
			
    		if( isHitPaddle() )
    			{changeVerticalDirection();}
			
			if ( upperWindow() )
    			{changeVerticalDirection();}
			
			move();
			
		}

		
};
#endif
