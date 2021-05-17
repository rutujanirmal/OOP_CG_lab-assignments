#include <iostream>
#include <graphics.h>

using namespace std;

class pattern{
	private:
		int x,y,r_i,r_e,a1,b1,a2,b2,a3,b3,h,side;
	public:
		void read();
		void incircle();
		void excircle();
		void triangele();
		void cal();
		void brecircle(int x,int y,int r_i);
		void DDA(int X0, int Y0, int X1, int Y1);
};

void pattern::read(){
	cout<<"Enter the center x y :: ";
	cin>>x>>y;
	cout<<"\nEnter the radius of inner circle ::";
	cin>>r_i;
}

void pattern::cal(){
	side=(6*r_i)/(1.732);
	h=(side*1.732)/2;
	r_e=h-r_i;
	a1=x;
	b1=y-(h-r_i);
	a2=x-(side/2);
	a3=x+(side/2);
	b2=b3=y+r_i;
}

void pattern::brecircle(int x1,int y1,int r) 
	{
		float x=0, y=r, pn;
		pn=3-(2*r);
		while (x<=y) 
		{
			putpixel(x1+x,y1+y,RED);
			putpixel(x1-x,y1+y,YELLOW);
			putpixel(x1+x,y1-y,BLUE);
			putpixel(x1-x,y1-y,GREEN);
			putpixel(x1+y,y1+x,GREEN);
			putpixel(x1+y,y1-x,YELLOW);
			putpixel(x1-y,y1+x,BLUE);
			putpixel(x1-y,y1-x,RED);
			x=x+1;
			if (pn<0) 
				{
				pn=pn+4*(x)+6;
				}
			else
				{
				pn=pn+4*(x-y)+10;
				y=y-1;
				}
			delay(20);
		}
	}

void pattern::DDA(int X0, int Y0, int X1, int Y1) 
{ 

    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        putpixel (X,Y,CYAN);  
        X += Xinc;           
        Y += Yinc;           
        delay(5);
    } 
} 

void pattern::incircle(){
	brecircle(x,y,r_i);
}

void pattern::excircle(){
	brecircle(x,y,r_e);
}

void pattern::triangele(){
	DDA(a1,b1,a2,b2);
	DDA(a2,b2,a3,b3);
	DDA(a3,b3,a1,b1);
}

int main(){
	initwindow(500,500);
	pattern p;
	p.read();
	p.cal();
	p.incircle();
	p.excircle();
	p.triangele();
	getch();
	return 0;
}

/*
INPUT

Enter the center x y :: 250
250

Enter the radius of inner circle ::100
*/
