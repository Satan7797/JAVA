#include<iostream>
#include<math.h>
using namespace std;

bool posCheck(int i,int r)
{
	for(int j=0;j<=r;j++)
	if(i==pow(2,j))
	return false;
	return true;
}

int main()
{
	int m,r;
	cout<<"\nEnter m: ";
	cin>>m;
	
	int data[m];
	cout<<"\nEnter data: ";
	for(int i=0;i<m;cin>>data[i],i++);
	
	for(r=1;;r++)
	if((pow(2,r))>=(m+r+1))
	break;

	int sd=m+r,k=0,dataSent[sd],temp=r;
	for(int i=sd-1;i>=0;i--)
	{
		if(posCheck(i+1,r))
			dataSent[i]=data[k++];
		else
			dataSent[i]=temp--;
	}
	
	for(int i=0;i<sd;i++)
    if(!posCheck(i+1,r))
	{
		int sum=0,s=i+1;
		for(int j=s;j<=sd;j++)
		if((j&s)> 0 && j!=s)
		  sum+=dataSent[j-1];
		
		///even parity check
		if(sum%2==0)
		  dataSent[i]=0;
		else
		  dataSent[i]=1;
	}

	cout<<"\nData Sent: ";
	for(int i=sd-1;i>=0;i--)
	cout<<dataSent[i];

	cout<<"\nRedundant bits: ";
	for(int i=0;i<sd;i++)
    if(!posCheck(i+1,r))
	cout<<dataSent[i];
	
	return 0;
}
