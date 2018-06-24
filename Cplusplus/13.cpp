//Write a program in which a function is passed address 
//of two variables and then alter its contents.

#include<iostream>
using namespace std;

void fun(int *a,int *b)
{
	int temp=*a;
	*a=*b*12;
	*b=temp*12;
}	

int main()
{
	int A=10,B=20;
	fun(&A,&B);
	cout<<"A and B after altering values:";
	cout<<A<<" "<<B;
	return 0;
}
