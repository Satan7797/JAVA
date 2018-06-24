//WAP to calculate Factorial of a number (i)using recursion, (ii) using iteration

#include<iostream>
using namespace std;

int Factorial(int);		//function prototype 

int main()
{
	int n,fac=1;
	
	cout<<"\nEnter the number:";
	cin>>n;
	if(n<0)
	cout<<"\nNegative number not allowed.";
	else
	{
		cout<<"\nFactorial of the number using Recursion:";
		cout<<Factorial(n);		//function call to calculate the factorial using recursion
	
		cout<<"\nFactorial of the using iteration:";
	
		for(int i=1;i<=n;i++)		//loop to caculate the factorial using iteration
			fac*=i;
		
		cout<<fac;
	}
	return 0;
}

int Factorial(int n)			//function for recursion
{
	if(n==0)
	return 1;
	else
	return (n*Factorial(n-1));
}

