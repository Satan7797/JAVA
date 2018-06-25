/*Write a Program to accept a directed graph G and compute the in-degree and out-degree of
  each vertex.*/

#include<iostream>
using namespace std;
int main()
{
	int n,arr[10][10];
	
	cout<<"Enter number of vertices:";
	cin>>n;
	
	cout<<"Enter matrix:\n";
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>arr[i][j];
	
	char a='a';
	
	for(int i=0;i<n;i++)		//nested loop to calculate the sum of Rows and columns
	{
		int sum=0,sum1=0;
		for(int j=0;j<n;j++)
		{
			sum+=arr[i][j];
			sum1+=arr[j][i];
		}
		cout<<"\nIn-degree of vertex "<<a<<" is "<<sum1<<endl;
		cout<<"Out-degree of vertex "<<a++<<" is "<<sum<<endl;
	}
	
	return 0;
}
