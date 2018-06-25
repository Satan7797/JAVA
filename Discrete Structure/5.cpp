//Write a Program to generate the Fibonacci Series using recursion.

#include<iostream>
using namespace std;

int Fibonacci(int n)			
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	
	return (Fibonacci(n-1)+Fibonacci(n-2));
}

int main()
{
	int n;
	cout<<"\nEnter n:";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	cout<<Fibonacci(i)<<" ";
		
	return 0;
}
