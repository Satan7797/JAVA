#include<iostream>
using namespace std;

class node{
	public:
		int coeff,pow;
		node* next;
		node(int c,int p,node* n=NULL){
			coeff=c;
			pow=p;
			next=n;
		}
};

class polynomial{
	node *head,*tail;
	public:
		polynomial(){
			head=tail=NULL;
		}
		
		bool isEmpty(){
			return head==NULL;
		}
		void insert(int x,int pow);
		void display();
		node* getHead(){
			return head;
		}
		bool powInList(int);
		polynomial addPolynomial(polynomial);
		void bubbleSort();
};

bool polynomial::powInList(int x){
	node *temp=head;
	for(;temp!=NULL && temp->pow!=x;temp=temp->next);
	
	if(temp!=NULL && temp->pow==x){
		return true;
	}else
	return false;
}

void polynomial::insert(int x,int pow){
	if(isEmpty()){
		head=tail=new node(x,pow);
	}else if(powInList(pow)){
		node *temp=head;
		for(;temp!=NULL && temp->pow!=pow ;temp=temp->next);
		temp->coeff+=x;
	}else{
		if(pow>head->pow){
			head=new node(x,pow,head);
		}else if(pow<tail->pow){
			node *temp=new node(x,pow);
			tail->next=temp;
			tail=temp;
		}else{
			node *curr=head;
			node *prev=NULL;
			while(curr!=NULL && curr->pow > pow){
				prev=curr;
				curr=curr->next;
			}
			prev->next=new node(x,pow,curr);
		}
	}
}

polynomial polynomial::addPolynomial(polynomial p){
	if(head==NULL && p.getHead()==NULL){
		cout<<"\nBoth are empty";
		return p;
	}
	node *temp=head;
	node *temp1=p.getHead();
	polynomial p1;
	cout<<"\nAnswer is: ";
	while(temp && temp1){
		if(temp->pow == temp1->pow){
			p1.insert(temp->coeff+temp1->coeff,temp->pow);
			temp=temp->next;
			temp1=temp1->next;
		}
		else if(temp->pow > temp1->pow){
			p1.insert(temp->coeff,temp->pow);
			temp=temp->next;
		}
		else if(temp->pow < temp1->pow){
			p1.insert(temp1->coeff,temp1->pow);	
			temp1=temp1->next;
		}
	}
	
	while(temp || temp1){
		if(temp){
			p1.insert(temp->coeff,temp->pow);
			temp=temp->next;
		}
		if(temp1){
			p1.insert(temp1->coeff,temp1->pow);
			temp1=temp1->next;
		}
	}
	return p1;
}

void polynomial::display(){
	if(isEmpty()){
		cout<<"\nEmpty";
		return;
	}else{
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->coeff<<"x^"<<temp->pow;
			temp=temp->next;
			if(temp)
			cout<<"+ ";
		}
	}
}

polynomial enterValue(){
	int coeff,pow;
	polynomial p;
	char choice;
	do{
		cout<<"\na) Insert value";
		cout<<"\nb) Display";
		cout<<"\nc) Stop entering values";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 'a': 
				cout<<"\nEnter coefficient and power: ";
				cin>>coeff>>pow;
				p.insert(coeff,pow);
				break;
			case 'b':
				cout<<"\nPolynomial is: ";
				p.display();
				break;
		}
		
		if(choice=='c')
		break;
	}while(true);
	return p;
}

int main(){
	polynomial p1,p2,p;
	cout<<"\nAdding two polynomials using linked list:-";
	cout<<"\nEnter values for first polynomial: ";
	p1=enterValue();
	
	cout<<"\nEnter values for second polynomial: ";
	p2=enterValue();
	
	cout<<"\nFirst polynomial: ";
	p1.display();
	cout<<"\nSecond polynomial: ";
	p2.display();
	p=p1.addPolynomial(p2);
	cout<<"\nSum of the polynomials is: ";
	p.display();
	return 0;
}
