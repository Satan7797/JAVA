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
		void addToHead(){
			T x;
			cout<<"\nEnter value: ";
			cin>>x;
			addToHead(x);
		}
		void addToTail(T);
		void addToTail(){
			T x;
			cout<<"\nEnter value: ";
			cin>>x;
			addToTail(x);
		}
		void deleteFromHead();
		void deleteFromTail();
		void deleteNode(T);
		void deleteNode(){
			T x;
			cout<<"\nEnter value to be deleted: ";
			cin>>x;
			deleteNode(x);
		}
		void display();
		void reverse();
		bool isInList(T);
		void isInList(){
			T x;
			cout<<"\nEnter value be searched: ";
			cin>>x;
			if(isInList(x))
			cout<<"\nElement is in list";
			else
			cout<<"\nnot in the list";
		}
		SLL concat(SLL);
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
SLL<T> SLL<T>::concat(SLL s)
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
	SLL<char> s1;
	char choice;
	do{
		cout<<"\na) Add to head";
		cout<<"\nb) Add to tail";
		cout<<"\nc) Delete from tail";
		cout<<"\nd) Delete from head";
		cout<<"\ne) Delete node";
		cout<<"\nf) Search for value in list";
		cout<<"\ng) Reverse the list";
		cout<<"\nh) Concatenation using concat";
		cout<<"\ni) Concatenation by overloaded + operator";
		cout<<"\nj) Display";
		cout<<"\nk) Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		if(choice=='a')
		s1.addToHead();
		else if(choice=='b')
		s1.addToTail();
		else if(choice=='c')
		s1.deleteFromTail();
		else if(choice=='d')
		s1.deleteFromHead();
		else if(choice=='e')
		s1.deleteNode();
		else if(choice=='f')
		s1.isInList();
		else if(choice=='g')
		s1.reverse();
		else if(choice=='h'){
			SLL<char> s=s1.concat(s1);
			cout<<"\nContents of s: ";
			s.display();
		}else if(choice=='i'){
			SLL<char> s=s1.operator +(s1);
			cout<<"\nContents of s: ";
			s.display();
		}else if(choice=='j')
		s1.display();
		else if(choice=='k')
		break;
	}while(true);
	return 0;
}
