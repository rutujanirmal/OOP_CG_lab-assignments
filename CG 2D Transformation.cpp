//2D transformation
//Translation
//Scaling
//Rotation
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<iostream>

using namespace std;


class polygon
{
	float p[10][10], m , n;
public:
	void getpoly();
	void drawpoly();
	void displaypoly();
	polygon mat_mul(polygon);
	polygon operator+(polygon);		// Translation
	polygon operator*(polygon);		// Scaling
	polygon operator/(polygon);		// Clockwise rotation
	polygon operator-(polygon);		// Anticlockwise rotation
};

void polygon :: getpoly()
{
	int i,j;
	cout<<"Enter no of vertices :";
	cin>>m;
	n=3;
	cout<<"Enter polygon coordinates";
	for(i=0;i<m;i++)
	{
		cin>>p[i][0]>>p[i][1];
		p[i][2]=1;
	}

}

void polygon :: displaypoly()
{
	int i,j;
	cout<<"The polygon is as follows "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<p[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void polygon :: drawpoly()
{
int i;
line(320,2,320,438);
line(2,240,638,240);

for( i=0;i<m-1;i++)           // Display polgon.
    line(p[i][0]+320,240-p[i][1],p[i+1][0]+320,240-p[i+1][1]);
line(p[0][0]+320,240-p[0][1],+320+p[i][0],240-p[i][1]);
}

polygon polygon :: mat_mul(polygon p2)             // Matrix multiplication.
{
	int i,j,k;
	polygon p3;

	p3.m=this->m;
    p3.n=p2.n;
	cout<<endl;
	for(i=0;i<p3.m;i++)
		for(j=0;j<3;j++)
		{
			p3.p[i][j]=0;
			for(k=0;k<3;k++)
				p3.p[i][j]+=this->p[i][k]*p2.p[k][j];
		}

	 return p3;
}

polygon polygon :: operator+(polygon p2)
{
	polygon p3;
	int tx, ty;
	p3.m=this->m;
	p3.n=3;

	cout<<"Enter Translation factors : ";
	cin>>tx>>ty ;
	p2.p[0][0]=1; p2.p[0][1]=0; p2.p[0][2]=0;            // Translation matrix.
	p2.p[1][0]=0; p2.p[1][1]=1; p2.p[1][2]=0;
	p2.p[2][0]=tx; p2.p[2][1]=ty; p2.p[2][2]=1;

	p3=this->mat_mul(p2);
	return p3;
}


polygon polygon :: operator*(polygon p2)
{
	polygon p3;
	int sx, sy;
	p3.m=this->m;
	p3.n=3;

	cout<<"Enter Scaling factors : ";
	cin>>sx>>sy ;
	p2.p[0][0]=sx; p2.p[0][1]=0; p2.p[0][2]=0;            // Scaling matrix.
	p2.p[1][0]=0; p2.p[1][1]=sy; p2.p[1][2]=0;
	p2.p[2][0]=0; p2.p[2][1]=0; p2.p[2][2]=1;

	p3=this->mat_mul(p2);
	return p3;
}

polygon polygon :: operator/(polygon p2)
{
	polygon p3;
	float ang, radian;

	p3.m=this->m;
	p3.n=3;

	cout<<"   Angle : ";
	cin>>ang;
	radian=ang*(3.14/180);

	p2.p[0][0]=cos(radian); p2.p[0][1]=-sin(radian); p2.p[0][2]=0;            // Rotation matrix.
	p2.p[1][0]=sin(radian); p2.p[1][1]=cos(radian); p2.p[1][2]=0;
	p2.p[2][0]=0; p2.p[2][1]=0; p2.p[2][2]=1;

	p3=this->mat_mul(p2);
	return p3;
}


polygon polygon :: operator-(polygon p2)
{
	polygon p3;
	float ang, radian;

	p3.m=this->m;
	p3.n=3;

	cout<<"   Angle : ";
	cin>>ang;
	radian=ang*(3.14/180);

	p2.p[0][0]=cos(radian); p2.p[0][1]=sin(radian); p2.p[0][2]=0;            // Rotation matrix.
	p2.p[1][0]=-sin(radian); p2.p[1][1]=cos(radian); p2.p[1][2]=0;
	p2.p[2][0]=0; p2.p[2][1]=0; p2.p[2][2]=1;

	p3=this->mat_mul(p2);
	return p3;
}

int main()
{
	polygon p1, p2, p3;
	int gd=DETECT,gm, sw;


	p1.getpoly();
	p1.displaypoly();
	initgraph(&gd,&gm,NULL) ;
	p1.drawpoly();

	do{
			cout<<"\t\t * MENU *";
			cout<<"\n1. TRANSLATION";
			cout<<"\n2. SCALING";
			cout<<"\n3. CLOCKWISE ROTATION";
			cout<<"\n4. ANTICLOKWISE ROTATION";
			cout<<"\nPlease! Enter your choice : ";
			cin>>sw;
			switch(sw)
			{
			  case 1 :

					p3=p1+p2; // Translation
					p3.displaypoly();
					p3.drawpoly();

				    break ;
			  case 2 :
					p3=p1*p2; // Scaling
					p3.displaypoly();
					p3.drawpoly();

				    break;
			  case 3 :
					p3=p1/p2; // Clockwise rotation
					p3.displaypoly();
					p3.drawpoly();
				    break ;
			  case 4 :
					p3=p1-p2; // Anticlockwise rotation
					p3.displaypoly();
					p3.drawpoly();
				    break;
			}
			}while(sw!=5);

	getch();

	return 0;
}

/*
INPUT
vertices: 4
polygon Co-ordinates
0
0
0
50
50
50
50
0

1
60 60

2
2 2

3
45

4
45
*/
