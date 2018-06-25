/*Write a Program to implement Bubble Sort. Find the number of comparisons during each
  pass and display the intermediate result. Use the observed values to plot a graph to analyse
  the complexity of algorithm.
*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

float f(int);

int main()
{
	int n;
	cout<<"\nEnter n:";
	cin>>n;
	
	int a[n];
	cout<<"\nEnter array:";
	for(int i=0;i<n;i++)		//loop to enter values
	cin>>a[i];
	
	int count=0;
	for(int i=0;i<n-1;i++)		//outer loop for pass
	{
		count=0;
		for(int j=0;j<n-1-i;j++)
		if(a[j]>a[j+1])			//if element at j is greater than element at j+1 then swap the values
		{
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			count++;
		}
		
		if(count>0)
		{
			cout<<"\n\nNumber of comparisions "<<count;
			cout<<"\nPass "<<i+1<<":";
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
	
	outtextxy(0,0,"Graph for Bubble Sort:");
	for(int x=0;x<198;x++)
	{
		int y=f(x);
		putpixel(300+x,175-y,GREEN);
	}

	getch();
	closegraph();
	return 0;
}

//function for binary search  complexity
float f(int x)
{
	return 2*sqrt(4*x);
}

