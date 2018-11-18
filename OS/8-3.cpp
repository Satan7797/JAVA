#include<iostream>
using namespace std;
int main()
{

	int n;
	cout<<"Enter number of processes : ";
	cin>>n;
	int A[n][4];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter process number : ";
		cin>>A[i][0];
		cout<<"Enter burst time for process "<<A[i][0]<<" : ";
		cin>>A[i][1];
		cout<<"Enter priority of process "<<A[i][0]<<" with burst time "<<A[i][1]<<" : ";
		cin>>A[i][2];
		cout<<"Enter arrival time for process "<<A[i][0]<<" : ";
		cin>>A[i][3];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(A[j][2]>A[j+1][2])
			{

				int temp[1][4];

				temp[1][0]=A[j][0];
				A[j][0]=A[j+1][0];
				A[j+1][0]=temp[1][0];

				temp[1][1]=A[j][1];
				A[j][1]=A[j+1][1];
				A[j+1][1]=temp[1][1];

				temp[1][2]=A[j][2];
				A[j][2]=A[j+1][2];
				A[j+1][2]=temp[1][2];

				temp[1][3]=A[j][3];
				A[j][3] = A[j+1][3];
				A[j+1][3] = temp[1][3];
			}
		}
	}

	int ct[n],tat[n],wt[n];
	ct[-1]=0;
	for(int i=0;i<n;i++)
	{
		ct[i]=ct[i-1]+A[i][1];
		tat[i]=ct[i];
		wt[i]=tat[i]-A[i][1];
	}

	cout<<"  Process NO.  Burst Time  Priority  Completion Time  TurnAround time  Waiting time\n";
	for(int i=0;i<n;i++)
	cout<<"\t"<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;


	return 0;
}
