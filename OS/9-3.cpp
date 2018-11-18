#include<iostream>
#include<algorithm>
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
	for(int i=0;i<n;allocate[i]=-1,cin>>blocks[i],flag[i]=false,i++);
	
	sort(blocks,blocks+n,greater<int>());
	
	int m;
	cout<<"\nEnter number of proecesses: ";
	cin>>m;
	int process[m];
	cout<<"\nEnter memory required for process: ";
	for(int i=0;i<m;cin>>process[i],i++);
	
	//Allocation loop
	for(int i=0;i<m;i++)
  		for(int j=0;j<n;j++)
   			if(process[i]<=blocks[j] && flag[j]==false)
    		{
     			allocate[j]=i;
     			flag[j]=true;
     			break;
    		}

	cout<<"\nBlock Size\tProcess No.\tProcess Size";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<blocks[i]<<"\t\t";
		if(flag[i]==true)
			cout<<allocate[i]+1<<"\t\t"<<process[allocate[i]];
		else
			cout<<"Not Allocated";
	}
	cout<<"\n";
	return 0;
}
