#include<iostream>
using namespace std;

template<class T=int>
class node
{
	public:
		T info;
		node *next,*prev;
		node(T i,node *n,node *p)
		{
			info=i;
			next=n;
			prev=p;
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
};

template<class T>
void SLL<T>::addToHead(T x)
{
	if(head==NULL)
	tail=head=new node<T>(x,NULL,NULL);
	else
	head=new node<T>(x,head,NULL);
}

template<class T>
void SLL<T>::addToTail(T x)
{
	if(head==NULL)
	tail=head=new node<T>(x,NULL,NULL);
	else
	tail=(tail->next=new node<T>(x,NULL,tail));
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
	head->prev=NULL;
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
			node<T> *temp=head;
			for(;temp->info!=x;temp=temp->next);
			node<T> *pred=temp->prev;
			node<T> *desc=temp->next;
			desc->prev=pred;
			pred->next=desc;
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
	
	node<T> *first=head,*end=tail;
	int temp;
	for(;first!=end;first=first->next,end=end->prev)
	{
		temp=first->info;
		first->info=end->info;
		end->info=temp;
	}
	cout<<"\nAfter reversing the list: ";
	display();
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
	s1.addToTail(4);
	s1.addToTail(5);
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
