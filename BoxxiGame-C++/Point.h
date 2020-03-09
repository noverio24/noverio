#ifndef POINT_H
#define POINT_H

class Point{
	private :
		int x, y;
	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y){}
		
		void set(int _x, int _y){x=_x;y=_y;}
		
		int getX() const {return x;}
		
		int getY() const {return y;}
};
#endif
