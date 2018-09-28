#include<iostream>
using namespace std;

template<class T=int>
class node
{
	public:
		T info;
		node *next;
		node(T i,node *n=NULL)
		{
			info=i;
			next=n;
		}
};

template<class T=int>
class SLL
{
	node<T> *head,*tail;
	public:
		SLL()
		{
			head=tail=NULL;
		}
		
		bool isEmpty()
		{
			return head==NULL;
		}
		
		node<T>* getHead()
		{
			return head;
		}
		
		node<T>* getTail()
		{
			return tail;
		}
		
		void addToHead(T);
		void addToTail(T);
		void deleteFromHead();
		void deleteFromTail();
		void deleteNode(T);
		void display();
		void reverse();
		bool isInList(T);
		void concat(SLL);
		SLL operator +(SLL);
};

template<class T>
void SLL<T>::addToHead(T x)
{
	if(head==NULL)
	tail=head=new node<T>(x);
	else
	head=new node<T>(x,head);
}

template<class T>
void SLL<T>::addToTail(T x)
{
	if(head==NULL)
	tail=head=new node<T>(x);
	else
	tail=(tail->next=new node<T>(x));
}

template<class T>
void SLL<T>::deleteFromHead()
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
	node<T> *temp=head;
	head=temp->next;
}

template<class T>
void SLL<T>::deleteFromTail()
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
	node<T> *temp=head;
	for(;temp->next!=tail;temp=temp->next);
	cout<<"\nRemoving "<<tail->info<<endl;
	tail=temp;
	tail->next=NULL;
}

template<class T>
void SLL<T>::deleteNode(T x)
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
	if(isInList(x))
	{
		if(head->info==x)
		deleteFromHead();
		else if(tail->info==x)
		deleteFromTail();
		else
		{
			node<T> *temp=head->next;
			node<T> *prev=head;
			for(;temp->info!=x;temp=temp->next,prev=prev->next);
			prev->next=temp->next;
		}
	}
	else
	cout<<"\n"<<x<<" not in list\n";
}

template<class T>
bool SLL<T>::isInList(T x)
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return false;
	}
	node<T> *temp=head;
	for(;temp!=tail && temp->info!=x;temp=temp->next);
	if(temp->info==x)
	return true;
	return false;
}

template<class T>
void SLL<T>::reverse()
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
	node<T> *first=NULL,*temp=head,*end=tail;
	do
	{
		first=head;
		while(first->next!=end)
		first=first->next;
		
		T d=temp->info;
		temp->info=end->info;
		end->info=d;
		
		end=first->next;
		temp=temp->next;
	}while(temp!=end);
	
	cout<<"\nAfter reversing the list: ";
	display();
}

template<class T>
void SLL<T>::concat(SLL s)
{
	if(isEmpty() && s.isEmpty())
	{
		cout<<"\nBoth lists are empty.";
		return;
	}
	
	if(s.head==head)
	{
		SLL<T> s1;
		s=s.operator+(s1);
	}
	
	if(isEmpty())
	{
		head=s.getHead();
		tail=s.getTail();
	}
	else
	{
		this->tail->next=s.getHead();
		tail=s.getTail();
	}
}

template<class T>
SLL<T> SLL<T>::operator +(SLL<T> s)
{
	SLL<T> s1;
	node<T> *temp;
	for(temp=this->head;temp!=NULL;temp=temp->next)
	s1.addToTail(temp->info);
	for(temp=s.getHead();temp!=NULL;temp=temp->next)
	s1.addToTail(temp->info);
	return s1;
}

template<class T>
void SLL<T>::display()
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
	node<T> *temp=head;
	do
	{
		cout<<temp->info<<" ";
		temp=temp->next;
	}while(temp!=NULL);
}

int main()
{
	SLL<> s1;
	cout<<"Add to head:\n";
	s1.addToHead(1);
	s1.addToHead(2);
	s1.addToHead(3);
	s1.display();
	cout<<"\nAdd to tail:\n";
	s1.addToTail(2);
	s1.addToTail(3);
	s1.display();
	cout<<"\nDelete from head:\n";
	s1.deleteFromHead();
	s1.display();
	cout<<"\nDelete from tail:\n";
	s1.deleteFromTail();
	s1.display();
	cout<<"\nDelete node:\n";
	s1.deleteNode(1);
	s1.display();
	cout<<"\nReversing:\n";
	s1.reverse();
	return 0;
}
