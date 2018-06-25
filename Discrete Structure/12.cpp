/*For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + …+ xn
  = C, where C is a constant (C<=10) and x1, x2,x3,…,xn are nonnegative integers using brute
  force strategy.*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int findsol(int pos,int n)
{
	int sum=0;
	if(pos==1||n==0)
	  return 1;
	for(int i=n;i>0;i--)
	  sum += findsol(pos-1,i);

	return sum+1;
}

int main()
{
	cout<<"Enter total no of variables x1+x2+x3.....+xn = C\n";
	int pos;
	cin>>pos;
	cout<<"\nEnter your constant value i.e C\n";
	int n;
	cin>>n;
	cout<<"\nTotal no. of solutions given data = "<<findsol(pos,n)<<"\n\n";
	system("pause");
	return 0;
}

