/*Write a Program to represent Graphs using the Adjacency Matrices and check if it is a
  complete graph.*/


#include<iostream>
using namespace std;
int main()
{
	int arr[10][10],n;
	
	cout<<"Enter no. of vertices:";
	cin>>n;
	
	cout<<"Enter matrix:\n";
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>arr[i][j];
	
	int count=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				if(arr[i][j]==0)
					count++;
				else
					count--;
		
			else if(i!=j)
				if(arr[i][j]==1)
					count++;
				else 
					count--;
	
	if(count==n*n)
	cout<<"\nComplete Graph";
	else
	cout<<"\nNot a complete graph";		
	return 0;	
}
