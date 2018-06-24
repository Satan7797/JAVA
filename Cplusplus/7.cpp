//WAP to compute the factors of a given number.

#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Enter a number:";
	cin>>a;
	cout<<"\nFactors are:";
	
	for(int i=1;i<=a;i++)	//loop to print the factors of a number
	  if(a%i==0)
		cout<<i<<" ";
		
	return 0;
}

