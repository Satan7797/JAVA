//Write a function to find whether a given no. is prime or not. Use the same to generate
//the prime numbers less than 100.

#include<iostream>
using namespace std;

int prime(int a);
int main()
{
	int a;
	cout<<"Enter a number:";
	cin>>a;
	
	int check=prime(a);		//function call to check if the entered number is prime or not
	if(check==1)
	cout<<"Prime number";
	else
	cout<<"Not a prime number";

	cout<<"\n\nList of prime numbers:";
	for(int i=2;i<=100;i++)			//loop to print the prime numbers less than 100
	{
		check=prime(i);
		if(check==1)
		cout<<i<<" ";
	}	
	cout<<"\n";
	return 0;
}

int prime(int a)		//function definition 
{
	int pass=0;
	if(a==1||a==0)
	cout<<"Not a prime number";
	else
	{
		for(int i=2;i<=a/2;i++)		//loop for checking the divisibility of number
		if(a%i==0)
		{
			pass=1;
			return 2;
			break;
		}
	}
	if(pass==0)
	{
		return 1;
    }
}

