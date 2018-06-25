/*Given a graph G, Write a Program to find the number of paths of length n between the
  source and destination entered by the user.*/

#include<iostream>
using namespace std;
int main()
{
	int arr[10][10];
	int a[10][10],b[10][10];
	int n,l;
	char x,y;

	cout<<"Enter number of vertices:";
	cin>>n;

	cout<<"Enter matrix:\n";

	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	cin>>a[i][j];
	b[i][j]=a[i][j];
	}
	cout<<"\nEnter source and destination:";
	cin>>x>>y;
	cout<<"\nEnter length of paths:";
	cin>>l;

	for(int i=l;i>1;i--)
	{	
	
		//loops for multiplication of two matrices
		for(int m=0;m<n;m++)
			for(int j=0;j<n;j++)
			{
				arr[m][j]=0;
				for(int k=0;k<n;k++)
					arr[m][j]+=a[m][k]*b[k][j];
			}

		for(int m=0;m<n;m++)
		for(int j=0;j<n;j++)
		b[m][j]=arr[m][j];
	}
	
	cout<<"\n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<arr[i][j]<<"\t";
		cout<<endl;
	}
	
	cout<<"\nNumber of paths between "<<x<<" and "<<y<<":"<<b[x-97][y-97];

	return 0;
}
