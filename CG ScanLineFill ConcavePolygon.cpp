// Program to Fill a concave Polygon Using Scan Line Fill Algorithm in C++.

#include <iostream>
#include <graphics.h>

using namespace std;

class point
{
    public:
    int x,y;
};

class poly
{
    private:
        point p[20];
        int inter[20],x,y;
        int v=5,xmin,ymin,xmax,ymax;
    public:
        int c;
        void set();
        void read();
        void calcs();
        void display();
        void ints(float);
        void sort(int);
};

//Set default
//(150,200,350,400);
//(350,400,450,150);
//(450,150,200,100);
//(200,100,300,200);
//(300,200,150,200);
void poly::set(){
	p[0].x=150;p[0].y=200;
	p[1].x=350;p[1].y=400;
	p[2].x=450;p[2].y=150;
	p[3].x=200;p[3].y=100;
	p[4].x=300;p[4].y=200;
	p[5].x=150;p[5].y=200;
	xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;
}


//to accept
void poly::read()
{
    int i;
    cout<<"\n\t SCAN_FILL ALGORITHM";
    cout<<"\n Enter the no of vertices of polygon:";
    cin>>v;
    if(v>2)
    {
        for(i=0;i<v; i++)
        {
            cout<<"\nEnter the co-ordinate no.- "<<i+1<<" : ";
            cout<<"\n\tx"<<(i+1)<<"=";
            cin>>p[i].x;
            cout<<"\n\ty"<<(i+1)<<"=";
            cin>>p[i].y;
        }
        p[i].x=p[0].x;
        p[i].y=p[0].y;
        xmin=xmax=p[0].x;
        ymin=ymax=p[0].y;
    }
    else
        cout<<"\n Enter valid no. of vertices.";
}

void poly::calcs()
{
    for(int i=0;i<5;i++)
    {
        if(xmin>p[i].x)
        	xmin=p[i].x;
        if(xmax<p[i].x)
        	xmax=p[i].x;
        if(ymin>p[i].y)
        	ymin=p[i].y;
        if(ymax<p[i].y)
        	ymax=p[i].y;
    }
}

void poly::display()
{
    int ch1;
    float s,s2;
    	s=ymin+0.01;
        delay(10);
        while(s<=ymax)
        {
            ints(s);
            sort(s);
            s++;
        }
}

void poly::ints(float z)
{
    int x1,x2,y1,y2,temp;
    c=0;
    for(int i=0;i<v;i++)
    {
        x1=p[i].x;
        y1=p[i].y;
        x2=p[i+1].x;
        y2=p[i+1].y;
        if(y2<y1)
        {
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0)
            x=x1;
            else
            {
                x=((x2-x1)*(z-y1))/(y2-y1);
                x=x+x1;
            }
            if(x<=xmax && x>=xmin)
            inter[c++]=x;
        }
    }
}

void poly::sort(int z)
{
    int temp,j,i;

        for(i=0;i<v;i++)
        {
            line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        }
        delay(100);
        for(i=0; i<c;i+=2)
        {
            delay(100);
            line(inter[i],z,inter[i+1],z);
        }
}

int main()
{
    int cl;
    initwindow(500,500);
    poly x;
    //x.read();	
    x.set();	//set default
    x.calcs();
    cleardevice();
    cout<<"BLACK                   0"<<endl
		<<"BLUE                    1"<<endl
		<<"GREEN                   2"<<endl
		<<"CYAN                    3"<<endl
		<<"RED                     4"<<endl
		<<"MAGENTA                 5"<<endl
		<<"BROWN                   6"<<endl
		<<"LIGHTGRAY               7"<<endl
		<<"DARKGRAY                8"<<endl
		<<"LIGHTBLUE               9"<<endl
		<<"LIGHTGREEN             10"<<endl
		<<"LIGHTCYAN              11"<<endl
		<<"LIGHTRED               12"<<endl
		<<"LIGHTMAGENTA           13"<<endl
		<<"YELLOW                 14"<<endl
		<<"WHITE                  15"<<endl;
    cout<<"\n\tEnter the colour u want:(0-15)->"; //Selecting colour
    cin>>cl;
    setcolor(cl);
    x.display();
    
    getch();
    return 0;
}

/*
Input vertices
Total = 5

100 , 200
350 , 400
450 , 150
200 , 100
300 , 200

*/
