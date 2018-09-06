#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		node(int x,node *n)
		{
			info = x;
			next = n;
		}
};

class stack
{
	node *top;
	public:
		stack()
		{
			top = NULL;
		}
		void push(int);
		void pop();
		void display();
		void clearStack();
};

void stack::push(int x)
{
	node *temp = new node(x,top);
	top = temp;
	temp = NULL;
}

void stack::pop()
{
	if(top != NULL)
	{
	   node *temp = top->next;
	   int d = top->info;
	   delete top;
	   top = temp;
	   cout<<"\nElement poped "<<d;
    }
    else
    cout<<"\nStack is empty";
}

void stack::display()
{
	node *temp = top;
	while (temp != NULL)
	{
		cout<<"\n  "<<temp->info;
		temp = temp->next;
	}
}

void stack::clearStack()
{
	while(top != NULL)
	pop();
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
		
		if (ch == 'a')
		{
			int x;
			cout<<"\nEnter element to be inserted: ";
			cin>>x;
			s.push(x);
		}
		else if (ch == 'b')
		s.pop();
		else if (ch == 'c')
		{
			char c;
	    	cout<<"\nDo you really want to clear the stack?(y/n): ";
			cin>>c;
			if(c == 'y')
			s.clearStack();
		}
		else if (ch == 'd')
		s.display();
	}while(ch != 'e');
	return 0;
}
