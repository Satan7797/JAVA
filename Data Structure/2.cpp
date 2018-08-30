#include<iostream>
using namespace std;

double power(double b,int r)
{
	if(r==0)
	return 1.0;
	return b*power(b,r-1);
}

int main()
{
	double b;
	int r;
	cout<<"\nEnter b and r: ";
	cin>>b>>r;
	if(r>=0)
	cout<<"\n"<<b<<"^("<<r<<")is:= "<<power(b,r);
	else
	cout<<"\n"<<b<<"^("<<r<<")is:= "<<1/power(b,-r);
	return 0;
}
