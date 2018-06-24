//Write a program that swaps two numbers using pointers.

#include<iostream>
using namespace std;

int main()
{
	int a,b,*x,*y,temp;

	cout<<"Enter two numbers:";
	cin>>a>>b;

	x=&a;
	y=&b;

	temp=*x;				//to swap two numbers using pointers
	*x=*y;
	*y=temp;

	cout<<"\nA:"<<a;
	cout<<"\nB:"<<b;
	return 0;
}

