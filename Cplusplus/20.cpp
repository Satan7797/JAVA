//WAP to calculate GCD of two numbers (i) with recursion (ii) without recursion.

#include<iostream>
using namespace std;

int gcd(int,int);

int main()
{
	int m,n;
	cout<<"Enter two number:";
	cin>>m>>n;
	
	while(m!=n)		//loop to find GCD of two numbers
	{
		if(m>n)
		m-=n;
		else
		n-=m;
	}
	cout<<"\nGDC of two numbers using Loop:"<<m;
	
	cout<<"\nGCD of two numbers using recursion:"<<gcd(m,n);
	return 0;
}

int gcd(int m,int n)		//function to find the GCD of two number using recursion
{
	if(m>=n&&m%n==0)
	return n;
	else
	gcd(n,m%n);
}

