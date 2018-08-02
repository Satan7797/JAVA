//Write a Program to implement binary search using recursion.

#include<iostream>
using namespace std;

int binary(int a[],int first,int last,int x)	//function for Binary Search
{
	if(x>=a[0]&&x<=a[last-1])
	{
	  int mid=(first+last)/2;
	  if(a[mid]==x)				//if value if found at mid then function will return mid
	   return mid;
	  else if(a[mid]>x)			//if value is less than value at mid then check in second half of array  
	   return binary(a,first,mid-1,x);
	  else if(a[mid]<x)			//if value is greater than value at mid then check in first half of array
	   return binary(a,mid+1,last,x);
	}
	else					//if number is not found than return -1
	  return -1;
}

int main()
{
	int n;

	cout<<"\nEnter Size of array:";
	cin>>n;

	int a[n];

	cout<<"\nEnter array:";
	for(int i=0;i<n;i++)			//loop to enter values in array
	cin>>a[i];
	
	int x;
	cout<<"\nElement to be searched:";
	cin>>x;

	int pos=binary(a,0,n,x);		

	if(pos==-1)
	cout<<"\nNumber not found";
	else 
	cout<<"\nNumber found at "<<pos+1;

	return 0;
}
