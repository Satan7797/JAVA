#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of processes : ";
	cin>>n;
	int bt[n],wt[n],tat[n],awt=0,atat=0;

	cout<<"Enter Burst time of processes\n";
	for(int i=0;i<n;i++)
	cin>>bt[i];

	wt[0]=0;

	for(int i=0;i<n;i++)
	{
		wt[i]=0;
		for(int j=0;j<i;j++)
		wt[i]+=bt[j];
	}
	cout<<"Burst Time\tWaiting time\tTurnaround Time\n";
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		awt+=wt[i];
		atat+=tat[i];
		cout<<"    "<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}

	awt=awt/n-1;
	atat=atat/n-1;
	cout<<"Average Waiting time = "<<awt<<"\n\t     Average Turn Around Time = "<<atat<<endl;
	return 0;
}
