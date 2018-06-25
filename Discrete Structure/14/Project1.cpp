/*Write a program to accept an input n from the user and graphically represent the values of
  T(n) where n varies from 0 to n for the recurrence relations. For e.g. T(n) = T(n-1) + n,
  T(0) = 1, T(n) = T(n-1) + n^2, T(0) =1, T(n) = 2*T(n)/2 + n, T(1)=1.*/

#include<iostream>
#include<graphics.h>
#include<math.h>

float f(int);

int main()
{
	int x,y,z,w;
	int gdriver =DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");
			
	settextstyle(4,0,2);
	outtextxy(305,306,"Y'");
	settextstyle(4,1,2);
	outtextxy(313,290,"<");
	
	settextstyle(4,0,2);
	outtextxy(300,15,"Y");
	settextstyle(4,1,2);
	outtextxy(313,43,">");

	line(300,300,300,50);
	settextstyle(4,0,2);
	outtextxy(70,164,"X'<");
	outtextxy(490,164,">X");	
	line(500,175,100,175);

	settextstyle(8,0,2);

	outtextxy(0,0,"Graph for T(n)=T(n-1)+n:");
	
	int n;
	std::cout<<"\nEnter n:";
	std::cin>>n;
	for(int x=0;x<n;x++)
	{
		z=f(x);
		putpixel(300+x,175-z,WHITE);
	}
	
	
	getch();
	closegraph();
	return 0;
}

//function for function T(n)=T(n-1)+n
float f(int x)
{
	if(x==0)
	return 1;
	else 
	return (f(x-1)+x);
}
