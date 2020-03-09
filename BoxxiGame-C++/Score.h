#ifndef SCORE_H
#define SCORE_H

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
#endif
