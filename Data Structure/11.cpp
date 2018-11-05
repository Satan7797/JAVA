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
			node<T> *temp=head->next;
			node<T> *pred=head;
			while(temp->info!=x && temp!=NULL){
				temp=temp->next;
				pred=pred->next;
			}
			pred->next=temp->next;
			temp->next->prev=pred;
			delete temp;
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
	T temp;
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
	char choice;
	
	do{
		cout<<"\na) Insert at head";
		cout<<"\nb) Insert at tail";
		cout<<"\nc) Delete from head";
		cout<<"\nd) Delete from tail";
		cout<<"\ne) Delete node";
		cout<<"\nf) Search for value in list";
		cout<<"\ng) Reverse the list";
		cout<<"\nh) Display";
		cout<<"\ni) Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		if(choice=='a'){
			int x;
			cout<<"\nEnter value to be inserted: ";
			cin>>x;
			s1.addToHead(x);
		}else if(choice=='b'){
			int x;
			cout<<"\nEnter value to be inserted: ";
			cin>>x;
			s1.addToTail(x);
		}else if(choice=='c'){
			s1.deleteFromHead();
		}else if(choice=='d'){
			s1.deleteFromTail();
		}else if(choice=='e'){
			int x;
			cout<<"\nEnter value to be deleted: ";
			cin>>x;
			
			s1.deleteNode(x);
		}else if(choice=='f'){
			int x;
			cout<<"\nEnter value to be searched: ";
			cin>>x;
			
			if(s1.isInList(x))
				cout<<"\nValue is in the list.";
			else 
				cout<<"\nValue not found";
		}else if(choice=='g'){
			s1.reverse();
		}else if(choice=='h'){
			s1.display();
		}else if(choice=='i')
		break;
	}while(true);
	return 0;
}
