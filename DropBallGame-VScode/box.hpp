#ifndef rectangle_H
#define rectangle_H
#include <graphics.h>

class Box
{
    private:
    int x,y,lebar,panjang,color,cFill;
    
    public:
    Box(int _x= 0,int _y= 0, int _l= 0,int _p= 0, int _color=COLOR(255,255,255),int _cFill= 0);
	~Box();

	int getX() const;
	int getY() const;
	int getL() const;
	int getP() const;

	int getOutlineColor() const;
	int getFillColor() const;
	int getMaxX() const;
	int getMaxY() const;

    void setX(int _x);
	void setY(int _y);
	void setLebar(int _l);
	void setPanjang(int _p);

    void setXY(int x, int y);
	void setDimensi(int l, int p);

	void setOutlineColor(int _color);
	void setFillColor(int _cFill);
	void setColor(int _color, int _cFill);
    
    void drawRec(int color, int cFill) const;

    void unDrawRec() const;

    void show()const;
    void clear()const;

    void move(int dx=0,int dy=0);
};

#endif