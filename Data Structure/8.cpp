#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		node(int i,node *n)
		{
			info=i;
			next=n;
		}
};

class stack{
	node *top;
	public:
		stack()
		{
			top=NULL;
		}
		
		bool isEmpty()
		{
			return top==NULL;
		}
		
		void push(char x)
		{
			top=new node(x,top);
		}
		
		int pop()
		{
			if(isEmpty())
			return 0;
			int d=top->info;
			top=top->next;
			return d;
		}
		
		void display()
		{
			if(isEmpty())
			{
				cout<<"\nStack Empty!";
				return;
			}
			
			node *temp=top;
			while(temp!=NULL)
			{
				cout<<temp->info;
				temp=temp->next;
			}
		}
};

int main()
{
	stack s1,s2,s3;
	
	string numberA,numberB;
	cout<<"\nEnter 1st number: ";
	cin>>numberA;
	cout<<"\nEnter 2nd number: ";
	cin>>numberB;
	
	for(int i=0;i<numberA.length();i++)
	s1.push((int)numberA[i]-'0');
	for(int i=0;i<numberB.length();i++)
	s2.push((int)numberB[i]-'0');
	
	int carry=0;
	if(!s1.isEmpty() && !s2.isEmpty())
	while(!s1.isEmpty() || !s2.isEmpty())
	{
		carry += s1.pop() + s2.pop();
		s3.push(carry%10);
		carry/=10;
	}
	
	if(carry!=0)
	s3.push(carry);
	cout<<"\nSum: ";
	s3.display();
	return 0;
}
