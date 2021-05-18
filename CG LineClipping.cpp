//Cohen southerland Line Clipping
#include <iostream>
#include <graphics.h>
using namespace std;

class Cohen{
	private:
		int x[4],y[4];
		int x1,y1,x2,y2;
		int xmin,ymin,xmax,ymax;
		void DDA(int,int,int,int);
		void lineclip();
	public:
		void create();
};

void Cohen::DDA(int x1,int y1,int x2,int y2)
{
	float dx,dy,steps,xinc,yinc;
	int i;
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx-dy)
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	}
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	for(i=0;i<steps;i++)
	{
		delay(10);
		
		if(x1>xmin && x1<xmax && y1>ymin && y1<ymax)
		{
			putpixel(x1,y1,GREEN);
		}
		else
		{
			if(i%2==0)
				putpixel(x1,y1,GREEN);
		}
		x1+=xinc+0.5;
		y1+=yinc+0.5;
	}
}


void Cohen::lineclip()
{
	int i;
	char ans;
	xmin=ymin=999;
	xmax=ymax=0;
	
	for(i=0;i<4;i++)
	{
		if(xmin>x[i])
			xmin=x[i];
		if(ymin>y[i])
			ymin=y[i];
		if(xmax<x[i])
			xmax=x[i];
		if(ymax<y[i])
			ymax=y[i];	
	}
	
	do
	{
		cout<<"\nEnter the co-ordinates of line";
		cout<<"\nEnter co-ordinates x1 and y1 : ";
		cin>>x1>>y1;
		cout<<"\nEnter co-ordinates x2 and y2 : ";
		cin>>x2>>y2;
		
		DDA(x1,y1,x2,y2);
		
		cout<<"\nDo you want to clip more lines(y/n)?";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
}


void Cohen::create()
{
	int i;
	cout<<"\nEnter the co-ordinates for viewing window";
	
	for(i=0;i<4;i++){
		cout<<"\nEnter co-ordinate "<<i+1<<" for x :: ";
		cin>>x[i];
		cout<<"\nEnter co-ordinate "<<i+1<<" for y :: ";
		cin>>y[i];
	}
	
	for(i=0;i<3;i++){
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[3],y[3]);
	lineclip();
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	char ch;
	do
	{
		Cohen c;
		cleardevice();
		c.create();
		
		cout<<"\nDo you want to conitnue(y/n)?";
		cin>>ch;
	}while(ch=='Y' ||ch=='y');
	
	return 0;
}
/*

INPUT

100
100
100
400
400
400
400
100

50
300

*/
