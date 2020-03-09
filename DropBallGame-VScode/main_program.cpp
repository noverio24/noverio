#include "ball.hpp"
#include "box.hpp"
#include <graphics.h>
#include <ctime>
#include <string>

using namespace std;


class Score{
	private:
		int a, b, scr;
		char word[];
	public:
		Score (int _a=0, int _b=0) : a(_a), b(_b){
			scr =0;
		}
		
		void draw(){
			settextstyle(10,0,3); 
			setcolor(YELLOW);
			outtextxy(a+100, b+100, (char*)"SCORE= ");
			itoa(scr, word, 10);
			outtextxy(a+200, b+100, word);
		}
		
		void updateScore (int s){
			scr += s;
		}
		
		int getScore(){
			return scr;
		}

};


void menu()
{
	initwindow(getmaxwidth(), getmaxheight(), " Welcome ");
	string image = "main_menu.jpg";
	int imgwdth = 1366;
	int imghght = 758;
	readimagefile(image.c_str(),0,0,imgwdth,imghght);	
}

void display_border()
{
	srand(time(NULL));
	int left = 0, right = 0;

	initwindow(getmaxwidth(), getmaxheight(), " MatchMe! ");

	setfillstyle(SOLID_FILL, WHITE);
	bar(580, getmaxheight(), 595, 0); 		//left vertical 
	bar(765, getmaxheight(), 780, 0);		// rigth vertical
	bar(0, 548, 580, 558);					//left horizontal
	bar(775, 548, getmaxwidth(), 558);		//right horizontal

	for (int i=0; i<20; i++)
	{setfillstyle(SOLID_FILL, COLOR(rand()%256,rand()%256,rand()%256));
	bar(580, left+=20, 595, right+=30);  
	bar(765, left+=20, 780, right+=30);}

	Ball display[5] = {{Point(30,500),30,0,0,WHITE,YELLOW},
						{Point(110,500),30,0,0,WHITE,RED},
						{Point(190,500),30,0,0,WHITE,GREEN},
						{Point(270,500),30,0,0,WHITE,BLUE},
						{Point(350,500),30,0,0,WHITE,CYAN}};
	
	for (int i=0; i<5; i++)
	{
		display[i].draw();
	}
	
	settextstyle(4,0,2);
	setcolor(WHITE);
	outtextxy(20,490, "Z");
	outtextxy(100,490, "X");
	outtextxy(180,490, "C");
	outtextxy(260,490, "V");
	outtextxy(340,490, "B");
}

int main()
{	
	Score score(0,0);
	int w = getmaxwidth();  // max DPI 1360
	int h = getmaxheight(); // max DPI 760
	int color[5] = {YELLOW,RED,GREEN,BLUE,CYAN};
	bool gameOn = true;
	srand(time(NULL));

	menu();					//show the main menu
	getch();				//"press any key to continue"
	closegraph();			//close the main menu window and go to the game window
	display_border();

		Ball basket(Point (500,630),70);
		basket.setColor(WHITE,WHITE);	
	
		Ball ball[5] = {{Point(680,-120), 80,0,25, WHITE,color[rand() %5]},
					   {Point(680,-120), 80,0,25, WHITE,color[rand() %5]}, 
					   {Point(680,120), 80,0,25, WHITE,color[rand() %5]},
					   {Point(680,-120), 80,0,25, WHITE,color[rand() %5]},
					   {Point(680,-120), 80,0,25, WHITE,color[rand() %5]}};
		
	

		
		
	
		Box box(610,10,750,150,WHITE, color[rand() %5]);	
	int ci= 0;
	

	int i=0, triak=0;
	int ukur=0, j=0, warna= 0, trick =0,trick2=0, waka=0,warni=0;	
		
	while (gameOn != false)
    {	
		score.draw();
		basket.draw();
		
		ball[i].draw();
			delay(80);
			ball[i].move();
			

			
			
			if (ball[i].getBottom() >= h)
			{	
			    if(ball[i].getCFill() == RED    && ci == 1 && triak ==1)score.updateScore(1);
			    if(ball[i].getCFill() == BLUE   && ci == 2 && triak ==1)score.updateScore(1);
			    if(ball[i].getCFill() == YELLOW && ci == 3 && triak ==1)score.updateScore(1);
			    if(ball[i].getCFill() == CYAN   && ci == 4 && triak ==1)score.updateScore(1);
			    if(ball[i].getCFill() == GREEN  && ci == 5 && triak ==1)score.updateScore(1);
			   
				
				ball[i].unDraw();
				i++;
				ci=0;
				triak= 0;
				
			}	
		
		if ( kbhit() ){	
				char ch = 0;
				ch = getch();
		
			if (ch>0){ 
				ch = toupper(ch);

				if (ch=='Z') {
					basket.setCFill(YELLOW);
					ci = 3;}   
				else if (ch=='X') {
					basket.setCFill(RED);
					ci=1;}  
				else if (ch=='C') {
				basket.setCFill(GREEN);
				ci = 5;}   
				else if (ch=='V') {
					basket.setCFill(BLUE);
					ci =2 ;}
				else if (ch=='B') {
					basket.setCFill(CYAN);
					ci= 4;}  

		    }else{
			ch=getch();
			
			if (ch == 75){  //left
			basket.setMove(-200,0);
            basket.move();
			if(basket.getLeft() <= w) basket.setX(1280);
			if(basket.getRight() >= w) basket.setX(80);
			}
            //break;

           	else if(ch == 77){  //right
			basket.setMove(200,0);
           	basket.move();
			if(basket.getLeft() <= w) basket.setX(1280);
			if(basket.getRight() >= w) basket.setX(80);
			triak= 1;}
           	//break;
			   }
			

		
			
		
		}

	}
return 0;
}
