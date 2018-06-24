//WAP to print a triangle of stars as follows (take number of lines from user):
//      *
//     ***
//    *****
//   *******
//  *********

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n,k;
	cout<<"Enter n:";
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++)		//outer loop for number of lines
	{    cout<<setw(k--);
		for(int j=1;j<=i;j++)		//innerloops for printing *
		cout<<"*";
		if(i>1)
		for(int j=1;j<=i-1;j++)
		cout<<"*";
		cout<<"\n";
	}
	return 0;
}
