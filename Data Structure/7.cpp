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
			next=next;
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
    if(!isEmpty())
    {
	  node *temp=new node(x);
	  rear->next=temp;
	  rear=temp;
	}
	else
	front=rear=new node(x);
}

void queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return;
	}
	
	int d=front->info;
	node *temp=front;
	delete front;
	front=temp->next;
	cout<<"\nElement removed: "<<d;
}

void queue::display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
		return;
	}
	
	cout<<"\nQueue: ";
	node *temp=front;
	while(temp!=NULL)
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}
}

int main()
{
    queue q;
    char ch;
    do
    {
    	cout<<"\na) Enqueue";
    	cout<<"\nb) Dequeue";
   		cout<<"\nc) Display";
    	cout<<"\nd) Exit";
    	cout<<"\nEnter your choice: ";
    	cin>>ch;   
    	if(ch=='a')
    	{
    		int x;
    		cout<<"\nEnter x:";
    		cin>>x;
    		q.enqueue(x);
    	}
    	else if(ch=='b')
    		q.dequeue();
    	else if(ch=='c')
    		q.display();
    	else if(ch=='d')
    		break;
    }while(true);
    
	return 0;
}
