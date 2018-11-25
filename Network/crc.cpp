#include<iostream>
using namespace std;

int main()
{   
   //-----------DATAWORD---------------------
	int d[100],t[100],ds,g[50],gs,r[10],k=0;
	cout<<"Enter the size of dataword :: ";
	cin>>ds;
	cout<<"Enter the dataword : ";
	for(int i=0;i<ds;i++)
	{
		cin>>d[i];
        t[i]=d[i]; 
	}	
  //------------GENERATOR------------------------
	cout<<"\nEnter the size of generator :: ";
	cin>>gs;
	cout<<"Enter the generator : ";
	for(int i=0;i<gs;i++)
	cin>>g[i];
  //-------------REMAINDER-----------------------
	for(int i=ds;i<(ds+(gs-1));i++)
	d[i]=0;                          //insert gs-1 zeroes in the dataword
	cout<<"\nAugmented Dataword :: ";
    for(int i=0;i<(ds+(gs-1));i++)
	cout<<d[i]<<" ";
	
	for(int i=0;i<ds ;i++)
	{       
		k=i;	           //XOR of 0 and 1 for d[]==1
	  	if(d[k]==1)
			for(int j=0;j<(gs) ;j++,k++)
			    if(d[k]==g[j])
			    d[k]=0;
			    else
			    d[k]=1;       
      	else
        	for(int j=0;j<(gs) ;j++,k++)
			    if(d[k]==1)
			    d[k]=1;
			    else
			    d[k]=0;          
	}
	cout<<"\nRemainder :: ";
	for(int i=ds;i<(ds+(gs-1));i++)
    {
        t[i]=d[i];
		cout<<t[i]<<" ";
	}
  //-------------TRANSMITTED CODE--------------------
    cout<<"\nTransmitted Code :: ";
    for(int i=0;i<(ds+(gs-1));i++)
    cout<<t[i]<<" ";
  //------------RECEIVED CODE--------------------------
    cout<<"\nEnter the received code :: ";
	for(int i=0;i<(ds+(gs-1));i++)
	cin>>d[i];
    cout<<"\nEntered received code :: ";
	for(int i=0;i<(ds+(gs-1));i++)
    { 
	    cout<<d[i]<<" ";
        t[i]=d[i]; 
	}
 //------------CHECKING ERROR-----------------------
	for(int i=0;i<ds ;i++)
	{       
	    k=i;
	    
		if(d[k]==1)
		for(int j=0;j<(gs) ;j++,k++)
		if(d[k]==g[j])
		d[k]=0;
		else
		d[k]=1; 
        
		else 
	   	for(int j=0;j<(gs) ;j++,k++)
		if(d[k]==1)
		d[k]=1;
		else
		d[k]=0;      
	}
	
	cout<<"\nRemainder :: ";
	for(int i=ds;i<(ds+(gs-1));i++)
    {
        t[i]=d[i];
		cout<<t[i]<<" ";
        if(t[i]==0)
        k=0;
        else 
		k=1;
    }     
    if(k==0)
    cout <<"\nReceived code is correct.";
    else
    cout <<"\nReceived code is corrupted.";
	return 0;	
}
