/*Given a full m-ary tree with i internal vertices, Write a Program to find the number of leaf
  nodes.*/

#include<iostream>
using namespace std;
int main()
{
	int m=0,i=0;
	cout<<"\nEnter m:";
	cin>>m;
	cout<<"\nEnter number of internal vertices:";
	cin>>i;
	cout<<"\nNumber of leaves="<<(m-1)*i+1;		//Number of Leaf node,l=(m-1)*i+1
	return 0;
}
