#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int seq=0,rnd=1,ack=0,num;
	cout<<"\nEnter number of packets to be sent: ";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		if(rnd==0)
		{
			cout<<"\n======Sender side======\n";
			cout<<"\n-->Sending frame "<<i+1;
			cout<<"\n-->Frame lost ";
			seq=(seq+1)%2;
			rnd=rand()%10;
			i--;
			continue;
		}
		cout<<"\n======Sender side======\n";
		cout<<"\n-->Sending frame "<<i+1;
		seq=(seq+1)%2;
		cout<<"\n\n=======Receiver side=======\n";
		cout<<"\nReceived frame "<<i+1;
		cout<<"\nNow we are checking the data";
		if((seq+1)%2==ack)
		cout<<"\nBit matched";
		else
		{
			cout<<"\nIncorrect bit sequence";
			ack=(ack+1)%2;
			goto label;
		}
		
		if(rnd==2)
		{
			cout<<"\n-->Sending ack "<<ack;
			cout<<"\n-->Ack lost ";
			ack=(ack+1)%2;
			rnd=rand()%10;
			i--;
			continue;
		}
		label:
			ack=(ack+1)%2;
			cout<<"\nSending ack "<<ack;
			rnd=rand()%10;
	}
	
	cout<<"\nData transmission finished";
	return 0;
}
