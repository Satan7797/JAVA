#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter number of memory blocks: ";
	cin>>n;

	bool flag[n];
	int blocks[n];
	int allocate[n];

	cout<<"\nEnter value of memory blocks: ";	
	for(int i=0;i<n;allocate[i]=-1,flag[i]=false,cin>>blocks[i],i++);

	int m;
	cout<<"\nEnter number of proecesses: ";
	cin>>m;
	
	int process[n];
	cout<<"\nEnter memory required for process: ";
	for(int i=0;i<n;cin>>process[i],i++);

	for(int i=0;i<m;i++)
	{
  		for(int j=0;j<n;j++)
   		if(process[i]<=blocks[j] && flag[j]==false)
    	{
     		allocate[j]=i;
     		flag[j]=true;
     		break;
    	}
	}

	cout<<"\nBlock No.\tBlock Size\tProcess No.\tProcess Size\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<"\t\t"<<blocks[i]<<"\t\t";
		if(flag[i]==true)
		cout<<allocate[i]+1<<"\t\t"<<process[allocate[i]];
		else
		cout<<"Not Allocated";
	}
	cout<<"\n";
	return 0;
}
