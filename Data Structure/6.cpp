#include<iostream>
using namespace std;

template<class T=int>
class queue
{
	int n,size,front,rear;
	T *d;
	public:
		queue(int n1)
		{
			size=n1;
			d = new T[size];
			front=rear=-1;
			n=0;
		}
		
		void enqueue();
		void dequeue();
		void display();
		
		bool isEmpty()
		{
			if(front==-1)
			return true;
			else
			return false;
		}
};

template<class T>
void queue<T>::enqueue()
{
	T x;
	if(rear==front-1 || (front==0 && rear==size-1))
	{
		cout<<"\nQueue if full";
		return;
	}
	cout<<"\nEnter element: ";
	cin>>x;	
	cout<<"\nAdding "<<x<<"...\n";
	if(front==-1)
	{
		front=rear=0;
		d[rear]=x;
	}
	else if(front!=0 && rear==size-1)
	{
		rear=0;
		d[rear]=x;
	}
	else
		d[++rear]=x;
}

template<class T>
void queue<T>::dequeue()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return;
	}
	cout<<"\nRemoving "<<d[front]<<"...\n";
	d[front] = -1;
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==size-1)
		front=0;
	else
		front++;
}

template<class T>
void queue<T>::display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty.";
		return;
	}
	cout<<"\nQueue: ";	
	if(rear>=front)
	for(int i=front;i<=rear;i++)
	cout<<d[i]<<" ";
	else
	{
		for(int i=front;i<size;i++)
		cout<<d[i]<<" ";
		for(int i=0;i<=rear;i++)
		cout<<d[i]<<" ";
	}
}

int main()
{
	char c;
	int size;
	cout<<"\nEnter maximum size of queue: ";
	cin>>size;
	
	queue<> q(size);

	do
	{
		cout<<"\na) Enqueue";
		cout<<"\nb) Dequeue";
		cout<<"\nc) Display";
		cout<<"\nd) Exit";
		cout<<"\nEnter your choice: ";
		cin>>c;
		
		if(c=='a')
		q.enqueue();
		else if(c=='b')
		q.dequeue();
		else if(c=='c')
		q.display();
		else if(c=='d')
		break;
	}while(true);
	return 0;
}
