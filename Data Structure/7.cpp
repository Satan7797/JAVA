#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		node(int i,node *n=NULL)
		{
			info=i;
			next=n;
		}
};

class queue
{
	node *front,*rear;
	public:
		queue()
		{
			front=rear=NULL;
		}
		
		bool isEmpty()
		{
			return front==NULL;
		}
		
		void enqueue(int);
		void dequeue();
		void display();
};

void queue::enqueue(int x)
{
	if(isEmpty())
	{
		front=rear=new node(x);
		return;
	}
	node *temp=new node(x);
	rear->next=temp;
	rear=temp;
}

void queue::dequeue()
{
	if(!isEmpty())
	{
		cout<<"\nRemoving "<<front->info<<endl;
		node *temp=front->next;
		delete front;
		front=temp;
	}
	else
	cout<<"\nQueue is Empty";
}
void queue::display()
{
	if(!isEmpty())
	{
		node *temp=front;
		while(temp!=NULL)
		{
			cout<<temp->info<<" ";
			temp=temp->next;
		}
	}
	else
	cout<<"\nQueue is empty";
}

int main()
{
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.display();
//	q.dequeue();
	q.dequeue();
	q.display();
	return 0;
}
