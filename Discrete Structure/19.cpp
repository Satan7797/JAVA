/*Given an adjacency matrix of a graph, write a program to check whether a given set of
  vertices {v1,v2,v3.....,vk} forms an Euler path / Euler Circuit (for circuit assume vk=v1).*/

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n,sum=0;
	cout<<"Enter number of vertices:";
	cin>>n;
	
	int ar[n][n];
	cout<<"\nEnter matrix:\n";
	
	
	//nested for loop to enter data in array
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	   cin>>ar[i][j];
	
	char s[100];
	cout<<"\nEnter set of vertices(a,b,c....):";
	cin>>s;
	
	int l=strlen(s);
	
	for(int i=0;i<l-1;i+=2)
	{
		int x=s[i]-97,y=s[i+2]-97;
		
		if((x<n&&y<n))	
			if(ar[x][y]>0&&ar[y][x]>0)
			{
				--ar[x][y];
				--ar[y][x];
			}
	}
		
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	sum+=ar[i][j];
	
	if(s[0]==s[l-1]&&sum==0)
		cout<<"\nGiven set forms an Euler circuit.";
	else if(s[0]!=s[l-1]&&sum==0)
		cout<<"\nGiven set forms an Euler path.";
	else
		cout<<"\nGiven set is neither for Euler path nor for Euler circuit.";
	
	return 0;
}
