#include<iostream>
using namespace std;

template<class T=int>
class stack
{
	int n;
	T *d;
	int top;
	
	public:
		stack(int n1)
		{
			n=n1;
			d=new T[n];
			top=-1;
		}
		
		bool isEmpty()
		{
			if(top==-1)
			{
				cout<<"\nStack is empty";
				return true;
			}
			return false;
		}
		bool isFull()
		{
			if(top==n-1)
			{
				cout<<"\nStack is Full!";
				return true;
			}
			return false;
		}
		void push(T);
		void pop();
		void clearStack();
		void display();
};

template<class T>
void stack<T>::push(T x)
{
	cout<<"\nPushing element "<<x<<"...";
	d[++top]=x;
	cout<<"\nDone!\n";
}

template<class T>
void stack<T>::pop()
{
	cout<<"\nPopping...";
	cout<<"\nElement poped is "<<d[top--]<<endl;
}

template<class T>
void stack<T>::display()
{	
	cout<<"\nStack is: ";
	for(int i=0;i<=top;i++)
	  cout<<d[i]<<" ";
}

template<class T> 
void stack<T>::clearStack()
{
	top=-1;
}

int main()
{
	int n;
	cout<<"Enter maximum size of stack: ";
	cin>>n;
	stack<> s(n);
	do
	{
		cout<<"\na) Push";
		cout<<"\nb) Pop";
		cout<<"\nc) Clear Stack";
		cout<<"\nd) Display";
		cout<<"\ne) Exit";
		cout<<"\nEnter your choice: ";
		char c;
		cin>>c;
		
		if(c=='a'&& !s.isFull())
		{
			int x;
			cout<<"\nElement to be pushed: ";
			cin>>x;
			s.push(x);
		}
		else if(!s.isEmpty())
		{
			if(c=='b')
			s.pop();
			else if(c=='c')
			s.clearStack();
			else if(c=='d')
			s.display();
		}
		else if(c=='e')
		break;
	}while(true);
	return 0;
}
