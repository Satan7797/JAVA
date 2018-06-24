//WAP to compute the sum of the first n terms of the following series
//S =1-2+3-4+5…………….

#include<iostream>
using namespace std;
int main()
{
	int n,sum=0;
	cout<<"Enter number of terms:";
	cin>>n;
	for(int i=1;i<=n;i++)	//loop to calculate the sum of series
	{
		if(i%2==0)			//tto check if a number is either odd or even
		sum=sum-i;
		else
		sum=sum+i;
   }
	cout<<"Sum of the Series is "<<sum;
	return 0;
}

