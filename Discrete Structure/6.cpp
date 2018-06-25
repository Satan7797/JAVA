//Write a Program to implement Tower of Hanoi using recursion.

#include<iostream>
using namespace std;

void towerOfHanoi(int n,char from,char aux,char to)
{
   if(n==1)
   {
	cout<<"\nMove "<<n<<" from "<<from<<" to "<<to;
	return;
   }

   towerOfHanoi(n-1,from,to,aux);
   cout<<"\nMove "<<n<<" from "<<from<<" to "<<to;
   towerOfHanoi(n-1,aux,from,to);
}

int main()
{
   int n;
   cout<<"\nEnter number of disk:";
   cin>>n;

   if(n>0)
     towerOfHanoi(n,'A','B','C');
   else
     cout<<"\nNumber of Disk cannot be zero.";
	
   return 0;
}

