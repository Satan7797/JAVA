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
		
		void insert(int x,int pow){
			if(head==NULL)
			head=tail=new node(x,pow);
			else{
				tail->next=new node(x,pow);
				tail=tail->next;
			}
		}
		void display();
		node* getHead(){
			return head;
		}
		polynomial addPolynomial(polynomial);
};

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
	
	while(temp|| temp1){
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
	if(head==NULL){
		cout<<"\nEmpty";
		return;
	}
	
	node *temp=head;
	
	while(temp!=NULL){
		cout<<temp->coeff<<"x^"<<temp->pow<<"+";
		temp=temp->next;
	}
}

int main(){
	char choice;
	int coeff,pow;
	polynomial p1,p2,p;
	cout<<"\nAdding two polynomials using linked list:-";
	cout<<"\nEnter values for first polynomial: ";
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
				p1.insert(coeff,pow);
				break;
			case 'b':
				cout<<"\nPolynomial is: ";
				p1.display();
				break;
		}
		
		if(choice=='c')
		break;
	}while(true);

	cout<<"\nEnter values for second polynomial: ";
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
				p2.insert(coeff,pow);
				break;
			case 'b':
				cout<<"\nPolynomial is: ";
				p2.display();
				break;
		}
		
		if(choice=='c')
		break;
	}while(true);
	
	p=p1.addPolynomial(p2);
	cout<<"\nSum of the polynomials is: ";
	p.display();
	return 0;
}
