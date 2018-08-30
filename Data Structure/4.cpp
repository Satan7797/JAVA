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

class stack
{
	node *front, *rear;
	public:
		stack()
		{
			front=rear=NULL;
		}
		
		bool isEmpty()
		{
			return front==NULL;
		}
		void push(int);
		void pop();
		void display();
		void clearStack();
};

void stack::push(int x)
{
	if(front==NULL)
	{
		front=new node(x);
		rear=front;
	}
	else
	{
		node *temp=new node(x);
		rear->next=temp;
		rear=temp;
	}
}

void stack::pop()
{
	int d;
	if(front==NULL)
	{
		cout<<"\nStack is empty\n";
		return;
	}
	else if(front->next==NULL)
	{
		d=front->info;
		front=NULL;
		cout<<"\nElement poped "<<d<<endl;
	}
	else
	{
		node *temp=front->next;
		node *prev=front;
		while(temp!=NULL&&temp!=rear)
		{
			prev=prev->next;
			temp=temp->next;
		}
		if(temp==rear)
		{
			d=rear->info;
			delete rear;
			rear=prev;
			prev->next=NULL;
		}
		temp=prev=NULL;
		cout<<"\nElement poped "<<d<<endl;
	}
}

void stack::display()
{
	if(front!=NULL)
	{
		cout<<"\nStack is:= ";
		node *temp=front;
		do
		{
			cout<<temp->info<<" ";
			temp=temp->next;
		}while(temp!=NULL);
		cout<<endl;
	}
	else
	cout<<"\nStack is empty\n";
}

void stack::clearStack()
{
	if(front!=NULL)
	{
		node *temp=front;
		do
		{
			front=front->next;
			temp=temp->next;
		}while(temp!=NULL);
		delete temp;
	}
	else
	cout<<"\nStack is empty\n";
}

int main()
{
	stack s;
	char ch;
	
	do
	{
		cout<<"\na) Push";
		cout<<"\nb) Pop";
		cout<<"\nc) Clear";
		cout<<"\nd) Display";
		cout<<"\ne) Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		if(ch=='a')
		{
			int x;
			cout<<"\nEnter element to be inserted: ";
			cin>>x;
			s.push(x);
		}
		else if(ch=='b')
		s.pop();
		else if(ch=='c')
		{
			char c;
	    	cout<<"\nDo you really want to clear the stack?(y/n): ";
			cin>>c;
			if(c=='y')
			s.clearStack();
		}
		else if(ch=='d')
		s.display();
	}while(ch!='e');
	return 0;
}
