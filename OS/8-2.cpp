#include<iostream>
using namespace std;

int main()
{

	int n;
	cout<<"Enter number of process : ";
	cin>>n;
	int P[n][2],wt[n],tat[n],awt=0,atat=0;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter process number : ";
		cin>>P[i][0];
		cout<<"Enter burst-time of process "<<P[i][0]<<" : ";
		cin>>P[i][1];
	}

	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n-1;j++)
		{	
			if(P[j][1]>P[j+1][1])
			{
				int temp[1][2];
				temp[0][0] = P[j][0];
				P[j][0] = P[j+1][0];
				P[j+1][0] = temp[0][0];
			
				temp[0][1] = P[j][1];
				P[j][1] = P[j+1][1];
				P[j+1][1] = temp[0][1];
				}	
			}
		}

	for(int i=0;i<n;i++)
	{
	wt[i]=0;
	for(int j=0;j<i;j++)
	wt[i]+=P[j][1];
	}

	cout<<"Process NO.\t"<<"Burst Time\tWaiting time\tTurnaround Time\n";
	for(int i=0;i<n;i++)
	{
		tat[i]=P[i][1]+wt[i];
		awt+=wt[i];
		atat+=tat[i];
		cout<<P[i][0]<<"\t\t"<<P[i][1]<<"\t\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;

	}

	cout<<"Average waiting time is : "<<awt/n<<"\nAverage turn around time : "<<atat/n<<"\n";
	return 0;
}
