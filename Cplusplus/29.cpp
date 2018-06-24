//Write a program that will read 10 integers from user and store them in an array. Implement array using pointers. 
//The program will print the array elements in ascending and descending order.

#include<iostream>
using namespace std;

int main()
{
	int ar[100],n;
	int *p=ar;
	cout<<"Enter size of array:";
	cin>>n;
	cout<<"Enter array:";
	for(int i=0;i<n;i++)
	cin>>*(p+i);
	
	int pos;
	for(int i=0;i<(n-1);i++)		//loop for sorting array in ascending order
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		if(p[pos]>p[j])
		pos=j;
		
		if(pos!=i)
		{
			int temp=p[i];
			p[i]=p[pos];
			p[pos]=temp;
		}
	}
	
	cout<<"\nSorted array in ascending order:";
	for(int i=0;i<n;i++)				//loop to print array in ascending order
	cout<<*(p+i)<<" ";
	
	cout<<"\n\nSorted array in descending order:";
	for(int i=n-1;i>0;i--)				//loop to print array in descending order
	cout<<*(p+i)<<" ";
	
	return 0;
}

