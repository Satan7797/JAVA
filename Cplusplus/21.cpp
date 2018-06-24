//Create Matrix class using templates. Write a menu-driven program to perform following Matrix
//operations (2-D array implementation):
//a) Sum b) Difference c) Product d) Transpose

#include<iostream>
using namespace std;

int main()
{
	int arr[10][10];
	int r,c;
	cout<<"Enter row and columns:";
	cin>>r>>c;
	cout<<"Enter array:";
	
	for(int i=0;i<r;++i)
	for(int j=0;j<c;++j)
	cin>>arr[i][j];
	
	int ar1[10][10];
	char ch,co='y';
	while(co=='y')
	{
		cout<<"\na.sum of arrays\nb.difference of arrays\nc.product of arrays\nd.transpose of array\nEnter your choice:";
		cin>>ch;
		if(ch=='a')
		{
			cout<<"\nEnter second array:";
			for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
			  cin>>ar1[i][j];

			int ar2[10][10];
			for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
			  ar2[i][j]=arr[i][j]+ar1[i][j];
			
			cout<<"\nSum of arrays:\n";
			for(int i=0;i<r;++i)
			{
				for(int j=0;j<c;++j)
				cout<<ar2[i][j]<<"\t";
				cout<<"\n";
			}
		}
		else if(ch=='b')
		{
			cout<<"\nEnter second array:";
			for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			  cin>>ar1[i][j];
			
			cout<<"\nDifference of arrays:\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<ar1[i][j]-arr[i][j]<<"\t";
				cout<<"\n";
			}
		}
		else if(ch=='c')
		{
			cout<<"\nEnter second array:";
			for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			  cin>>ar1[i][j];
		
			int mult[10][10];	
        	 	for(int i=0;i<r;++i)
                	for(int j=0;j<c;++j)
                	mult[i][j]=0;
	
       		  	for(int i=0;i<r;++i)
        	        for(int j=0;j<c;++j)
        	    	for(int k=0;k<c;++k)
        	         mult[i][j]+=arr[i][k]*ar1[k][j];
						
			cout<<"\nProduct of arrays:\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<mult[i][j]<<"\t";
				cout<<"\n";
			}
		}
		else if(ch=='d')
		{
			cout<<"\nTranspose of array:\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<arr[j][i]<<"\t";
				cout<<"\n";
			}
		}
		cout<<"\nDo you want to continue?(y/n):";
		cin>>co;
	}
	return 0;
}

