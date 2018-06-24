//Write a macro that swaps two numbers. WAP to use it.

#include<iostream>
#define swap(a,b) int temp; temp=a,a=b,b=temp		//Macro to swap two numbers
using namespace std;

int main()
{
	int a,b;
	
	cout<<"Enter two numbers(A & B):";
	cin>>a>>b;
	
	swap(a,b);
	
	cout<<"A:"<<a<<"\nB:"<<b;
	
	return 0;
}
