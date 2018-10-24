#include<iostream>
using namespace std;

template<class T>
class node
{
	public:
		T info;
		node<T> *next;
		node(T i,node<T> *n=NULL)
		{
			info=i;
			next=n;
		}	
};

template<class T>
class cll
{
	node<T> *head,*tail;
	public:
		cll()
		{
		    head=tail=NULL;
		}
		bool isEmpty()
		{
		    return head==NULL;
		}
		
		void insertAtTail();
		void insertAtHead();
		void deleteHead();
		void deleteTail();
		void deleteNode();
		void display();
		void search(T);
		void reverse();
};

template<class T>
void cll<T>::insertAtHead()
{
	T i;
	cout<<"\nEnter value to be inserted: ";
	cin>>i;
	if(!isEmpty())
	{
		node<T> *temp=new node<T>(i);
		temp->next=head;
		tail->next=temp;
		head=temp;
	}
	else
	{
		head=new node<T>(i);
		tail=head;
		tail->next=head;
	}
}

template<class T>
void cll<T>::insertAtTail()
{
	T i;
	cout<<"\nEnter value to be inserted: ";
	cin>>i;
	if(!isEmpty())
	{
		node<T> *temp=new node<T>(i);
		temp->next=head;
		tail->next=temp;
		tail=temp;
	}
	else
	{
		head = new node<T>(i);
		tail = head;
		tail-> next = head;
	}
}

template<class T>
void cll<T>::deleteNode()
{
	if(!isEmpty())
	{
		display();
		T i;
		cout<<"\nEnter value to be deleted: ";
		cin>>i;

		if(head==tail && head->info==i)
		 deleteHead();
		else
		{
			node<T> *temp=head->next;
			node<T> *prev=head;
			while(temp!=head && temp->info!=i)
			{
				temp=temp->next;
				prev=prev->next;
			}
			if(temp==tail)
			deleteTail();
			else
			{
				prev->next=temp->next;
				cout<<"\nElement deleted "<<temp->info;
				delete temp;
			}
		}
	}
	else
	{
		cout<<"\nList is empty";
	}
}

template<class T>
void cll<T>::deleteTail()
{
	if(!isEmpty())
	{
		T d=tail->info;
		if(head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else
		{
			node<T> *temp=head->next;
			node<T> *prev=head;
			while(temp!=tail)
			{
				temp=temp->next;
				prev=prev->next;
			}
			prev->next=head;
			tail=prev;
			delete temp;
		}
		cout<<"\n"<<d<<" deleted";
	}
}

template<class T>
void cll<T>::deleteHead()
{
	if(!isEmpty())
	{
		T d = head->info;
		if(head==tail)
		{
			delete head;
			head=tail=NULL;
		}
		else
		{
		    tail->next = head->next;
		    head=head->next;
		}
		cout<<"\n"<<d<<" deleted";
	}
}

template<class T>
void cll<T>::search(T x)
{
	node<T> *temp=new node<T>(x);
	temp=head;
	int i=0,pass=0;
	do
	{
		if(temp->info==x)
		{
			pass=1;
			break;
		}
		temp=temp->next;
		i++;
	}while(temp!=head);
	if(pass==1)
		cout<<"\n"<<x<<" found at "<<i<<"th position in list";
	else
		cout<<"\n"<<x<<" not found";
}

template<class T>
void cll<T>::reverse()
{
	if(isEmpty())
	{
		cout<<"\nEmpty\n";
		return;
	}
	
 	node<T> *prev=tail,*current=head,*next,*temp=head; 
    do 
	{ 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } while (current!=(head)); 
  
  	tail=temp;
    head->next=prev; 
    head=prev; 	
	cout<<"\nAfter reversing the list: ";
	display();
}

template<class T>
void cll<T>::display()
{
	if(!isEmpty())
	{
		node<T> *temp=head;
      	do
	  	{
			cout<<temp->info<<" ";
			temp=temp->next;
	  	}while(temp!=head);
	}
	else
	cout<<"empty";
}

int main()
{
	cll<int> cir;
	char a;
	do
	{
		cout<<"\na) Insertion";
		cout<<"\nb) Deletion";
		cout<<"\nc) Search";
		cout<<"\nd) Display";
		cout<<"\ne) Reverse";
		cout<<"\nf) Exit";
		cout<<"\nEnter your choice: ";
		cin>>a;
		
		if(a=='a')
		{
			int n;
			cout<<"\n1. Insert at head";
			cout<<"\n2. Insert at tail";
			cout<<"\nEnter your choice: ";
			cin>>n;			
	
			if(n==1)
			cir.insertAtHead();
			else if(n==2)
			cir.insertAtTail();
		}
		else if(a=='b')
		{
			int n,x;
			cout<<"\n1. Deletion at head";
			cout<<"\n2. Deletion at Tail";
			cout<<"\n3. Delete a particular value";
			cout<<"\nEnter your choice: ";
			cin>>n;
			
			if(n==1)
			cir.deleteHead();
			else if(n==2)
			cir.deleteTail();
			else if(n==3)
			{
				cir.display();
				cout<<"\nEnter value to be deleted: ";
				cin>>x;
				cir.deleteNode();
			}
		}
		else if(a=='c')
		{
			int x;
			cout<<"\nEnter element to be searched: ";
			cin>>x;
			cir.search(x);
		}
		else if(a=='d')
		{
			cout<<"\nList is ";
			cir.display();
		}
		else if(a=='e')
		cir.reverse();
	}while(a!='f');

	return 0;
}
