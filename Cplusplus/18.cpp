//WAP to display Fibonacci series (i)using recursion, (ii) using iteration

#include<iostream>
using namespace std;

int Fibonacci(int);		//function prototype 

int main()
{
	int n,first=0,second=1,next,c=0;
	
	cout<<"\nEnter the number of terms:";
	cin>>n;
	
	cout<<"\nFibonacci series using Recursion:";
	for(int i=0;i<n;i++)					//loop to print the series using Recursion
	cout<<Fibonacci(c++)<<" ";
	
	cout<<"\nFibonacci Series using iteration:";
	
	for(int i=0;i<n;i++)				//loop to print the series using iteration
	{
		if(i<=1)
		next=i;
		else							//to pass new values to variables first and second
		{
			next=first+second;
			first=second;
			second=next;
		}
		cout<<next<<" ";
	}
	return 0;
}

int Fibonacci(int n)			//function for recursion
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	return (Fibonacci(n-1)+Fibonacci(n-2));
}

