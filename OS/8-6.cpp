#include<iostream> 
using namespace std;
 
int main()
{
    int bt[20],tq,rt[20],p[20],tat[20],at[20],rn,i,j,n,flag=0;
    float wt=0,tt=0;
    cout<<"Enter Total Number of Process:";
    cin>>n;
    rn=n;
 
    cout<<"\nEnter Burst Time and arrival time\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"arrival time:";
        cin>>at[i];   
        rt[i]=bt[i];
    }
    cout<<"enter time quantum ";
    cin>>tq;
 
    cout<<"\nProcess\t    turnaround Time    \tWaiting Time\n\n";
    for(i=0,j=0;rn!=0;)
    {
        if(rt[i]<=tq&&rt[i]>0)
        {
            j+=rt[i];
            rt[i]=0;
            flag=1;                  
        }
        else if(rt[i]>0)
        {
             rt[i]-=tq;
             j+=tq;
        }if(rt[i]==0 && flag==1)
        {
              rn--;
              cout<<"\nP["<<i+1<<"]"<<"\t\t"<<j-at[i]<<"\t\t"<<j-at[i]-bt[i];
              wt+=j-at[i]-bt[i];
              tt+=j-at[i];
              flag=0;
        }
        if(i==n-1)
              i=0;
        else if(at[i+1]<=j)
              i++;
              else
                  i=0;
    }              
    cout<<"\n\nAverage Waiting Time="<<(int)wt/n;
    cout<<"\nAverage Turnaround Time="<<(int)tt/n;
    cout<<endl;
 
    return 0;
}	

