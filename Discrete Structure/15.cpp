/*Write a Program to store a function (polynomial/exponential), and then evaluate the
  polynomial.*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int numberOfConstants,highestDegree,sum=0,n;
	
	cout<<"\nEnter number of constants:";
	cin>>numberOfConstants;
	cout<<"\nEnter highest degree of function:";
	cin>>highestDegree;
	
	cout<<"\nEnter n:";
	cin>>n;
	int cons[numberOfConstants];
	cout<<"Enter the Constants";
	for(int i=0;i<numberOfConstants;i++)
	{
		cin>>cons[i];
		sum+= cons[i]*(pow( n, highestDegree--));
	}
	
	cout<<"\nf("<<n<<")="<<sum;
	return 0;
}
