#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cmath>
#include "Point.h"
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
using namespace std;




int main( )
{
	cout<< getmaxheight()<< getmaxwidth();
	srand (time(NULL));
	initwindow( getmaxwidth(), getmaxheight(), "BOXI");
	
	char w[200];
	Score score(0,0);
	int choice;
	bool gameOn = true;
	while (gameOn != false){
		settextstyle(3,0,10); 
		setcolor(WHITE);
		
		outtextxy(550, 100, "BOXI");
		outtextxy(550, 200, "BOXI");
		outtextxy(550, 300, "BOXI");
		outtextxy(550, 400, "BOXI");
		
		outtextxy(650, 100, "BOXI");
		outtextxy(650, 200, "BOXI");
		outtextxy(650, 300, "BOXI");
		outtextxy(650, 400, "BOXI");
		
		settextstyle(10,0,3); 
		setcolor(LIGHTBLUE);
		
		outtextxy(100, 350, "1 - Play the game ");
		outtextxy(100, 400, "2 - Exit ");
		
	
		
		if ( getch() == '1'){
		
			Ball balls;
			Paddle paddle;
			
			bool quit;
			int y = getmaxheight() * 0.85 -50; 
			int x = getmaxwidth()/2 ;   
			
			int dx;
			if(rand()%2==0) dx=-60;
			else dx=60;
			
			int dy = 60;   
			if (y > (getmaxheight() / 2) ) dy = -dy;
			
			
			//space
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			bar(40,40,getmaxwidth()-40,getmaxheight()-40);
		
		
		
			balls.pointerP(&paddle);
			balls.setDirection(dx, dy);
			balls.setPosition(x,y-150);
			balls.setColor(YELLOW);
			balls.draw();
			
			paddle.setPosition(getmaxwidth()*0.5-150,getmaxheight()*0.85);
			paddle.setColor(BLUE);
			paddle.draw();
			
			
			
			while(balls.lowerWindow())
			{	
				score.draw();
				int pdx;
				if(paddle.getLeft()<=0) pdx = 0;		
				else if(paddle.getRight()>=getmaxwidth()) pdx =0;
				else pdx = 200;
				if(GetAsyncKeyState(VK_LEFT)) 
				{
					if(paddle.getRight()>=getmaxwidth()) pdx =200;
					paddle.move(-pdx);
				}
				if(GetAsyncKeyState(VK_RIGHT))
				{
					if(paddle.getLeft()<=0) pdx = 200;	
					paddle.move(pdx);
				}
			
				balls.Action();
				score.updateScore(1);
				
				
			}	
		}
        if( getch() == '2'){
        
			//space
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			bar(60,60,getmaxwidth()-60,getmaxheight()-60);
			
        	settextstyle(3,0,10); 
			setcolor(WHITE);
			outtextxy(180, 280, "THANK YOU (^_^)");
			delay(500);
			gameOn = false;
		}	
	}
	
	return 0;
}
