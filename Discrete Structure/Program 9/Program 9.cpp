/*Write a Program to implement Insertion Sort. Find the number of comparisons during each
  pass and display the intermediate result. Use the observed values to plot a graph to analyse
  the complexity of algorithm.*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

float h(int);
int main()
{
	int n;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	int a[n];
	
	cout<<"\nEnter array:";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int count=0;
	for(int c=1;c<=n-1;c++)		
	{
		count=0;
		int d=c;
		
		while(d>0&&a[d]<a[d-1])
		{
			int temp=a[d];
			a[d]=a[d-1];
			a[d-1]=temp;
			d--;
			count++;
		}
		
		if(count>0)
		{
			cout<<"\n\nNumber of comparisions "<<count;
			cout<<"\nPass "<<c<<":";
			for(int k=0;k<n;k++)			//loop to show intermediate result
			cout<<a[k]<<" ";
		}
		else
		break;
	}
	
	cout<<"\n\nSorted array:";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
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
	
	outtextxy(0,0,"Graph for Insertion Sort:");
	for(int x=0;x<35;x++)
	{
		int w=h(x);
		putpixel(300+x,175-w,YELLOW);
	}
	
	getch();
	closegraph();
	return 0;
}

//function for complexity of insertion sort
float h(int x)
{
	return x*log(x);
}

