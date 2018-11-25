#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TOT_FRAMES 500
#define FRAMES_SEND 10

using namespace std;

class gobkn
{
	int fr_send_at_instance;
	int arr[TOT_FRAMES];
	int arr1[FRAMES_SEND];
	int sw;
	int rw; 
	public:
		gobkn(){
			sw=rw=0;
		}
		void input();
		void sender(int);
		void receiver(int);		
};

void gobkn :: input()
{
	int n;
	int m; 
	
	cout<<"Enter the number of bits for the sequence no";
	cin>>n;
	
	m=pow(2,n);
	int t=0;
	
	fr_send_at_instance=m-1;
	for(int i=0;i<TOT_FRAMES;i++)
	{
		arr[i]=t;
		t=(t+1)%m;
	}
	sender(m);
}
void gobkn :: sender(int m)
{
	int j=0;
	
	for(int i=sw;i<sw+fr_send_at_instance;i++)
	{
		arr1[j]=arr[i];
		j++;
	}
	
	for(int i=0;i<j;i++)
	cout<<"Sender  : Frame "<<arr1[i]<<" is sent \n";
	receiver(m);
}
void gobkn :: receiver(int m)
{
	
	int f;
	int f1;
	int a1;
	char ch;
	
	srand(time(0));
	f=rand()%10;
		
	if(f!=5)
	{
		for(int i=0;i<fr_send_at_instance;i++)
		{
			if(rw==arr1[i])
			{
				cout<<"Receiver : Frame "<<arr1[i]<<"  received correctly\n";
				rw=(rw+1)%m;
			}
			else
			cout<<"Receiver : Duplicate frame "<<arr1[i]<<" discarded\n";
		}
		a1=rand()%15;
				
		if(a1>=0 && a1<=3)
		{
			cout<<"(Acknowledgement "<< arr1[a1]<< " & all after this lost)\n";
			sw=arr1[a1];
		}
		else
		sw=(sw+fr_send_at_instance)%m;
	}
	else
	{
		f1=rand()%fr_send_at_instance;
		
		int ld=rand()%2;
		if(ld==0)
		cout<<"Receiver : Frame "<<arr1[f1]<<"damaged \n";
		else
		cout<<" (Frame "<< arr1[f1]<<"lost) \n";
						
		for(int i=f1+1;i<fr_send_at_instance;i++)
		cout<<"(Frame discarded --> Resend the frame )\n";
		sw=arr1[f1];
	}
	cout<<"Want to continue......";
	cin>>ch;
	
	if(ch=='y')
	sender(m);
	else
	exit(0);
}

int main()
{
	gobkn gb;
	gb.input();
	return 0;
}
