//Given two ordered arrays of integers, write a program to merge 
//the two-arrays to get an ordered array.

#include<iostream>
using namespace std;

void merge(int [],int,int [],int,int[]);
int main()
{
	int a[100],b[100],sorted[200];
	int m,n,c;

	cout<<"Enter size of first array:";
	cin>>m;

	cout<<"Enter array:";
	for(int i=0;i<m;i++)
	cin>>a[i];

	cout<<"Enter size of second array:";
	cin>>n;

	cout<<"Enter second array:";
	for(int i=0;i<n;i++)
	cin>>b[i];
	
	merge(a,m,b,n,sorted);
	
	cout<<"\nMerged Array:";
	for(int i=0;i<m+n;i++)
	cout<<sorted[i]<<" ";
		
	return 0;
}

void merge(int a[],int m,int b[],int n,int sorted[])
{
	int i,j,k;
	j=k=0;
	
	for(i=0;i<m+n;)
	{
		if(j<m&&k<n)
		{
			if(a[j]<b[k])
			{
			sorted[i]=a[j];
			j++;
			}
			else
			{
				sorted[i]=b[k];
				k++;
			}
			i++;
		}
		else if(j==m)
		{
			for(;i<m+n;)
			{
				sorted[i]=b[k];
				k++;
				i++;
			}
		}
		else
		{
			for(;i<m+n;)
			{
				sorted[i]=a[j];
				j++;
				i++;
			}
		}
	}
}

