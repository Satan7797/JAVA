//WAP to compute the sum of the first n terms of the following series
//S = 1+1/2+1/3+1/4+……

#include<iostream>
using namespace std;
int main()
{
	float n;
	float s=0.0,p;
	cout<<"Enter n:";
	cin>>n;

	for(float i=1;i<=n;i++)	 //loop to calculate the sum of series
	{
		p=1/i;
		s+=p;
	}
	cout<<"Sum of series:"<<s;
	return 0;
}
