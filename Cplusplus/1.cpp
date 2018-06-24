//WAP to print the sum and product of digits of an integer.

#include<iostream>
using namespace std;
int main()
{
	int integer,sum=0,product=1;
	cout<<"Enter the number:";
	cin>>integer;
	while(integer!=0)		//loop to calculate the sum and product of digits
	{
		sum+=integer%10;		//stores the sum of ones digits
		product*=integer%10;	//stores the product of ones digit
		integer/=10;
	}
	cout<<"\nSum of digits:"<<sum;
	cout<<"\nProduct of digits:"<<product;
	return 0;
}

