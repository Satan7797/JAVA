#include<iostream>
using namespace std;

template<class T>
class node{
	public:
		T info;
		node<T> *next;
		node(T i,node<T> *n){
			info=i;
			next=n;
		}
};

template<class T>
class stack{
	node<T> *top;
	
	public:
		stack(){
			top=NULL;
		}
		
		bool isEmpty(){
			return top==NULL;
		}
		
		void push(char x){
			top=new node<T>(x,top);
		}
		
		int pop(){
			if(isEmpty())
			return 0;
			int d=top->info;
			top=top->next;
			return d;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"\nStack Empty!";
				return;
			}
			
			node<T> *temp=top;
			while(temp!=NULL){
				cout<<temp->info;
				temp=temp->next;
			}
		}
};

int main()
{
	string exp;
	double a,b;
	stack<double> s;
	cout<<"\nEnter the expression: ";
	cin>>exp;
	
	for(int i=0;i<exp.length();i++)
		if(isdigit(exp[i]))
			s.push(exp[i]-'0');
		else if(exp[i]>=42 && exp[i]<=47){
			a=s.pop();
			b=s.pop();

			switch(exp[i]){
				case '+': s.push(a+b);
						  break;
				case '-': s.push(b-a);
						  break;
				case '*': s.push(a*b);
						  break;
				case '/': s.push(b/a);
						  break;
				default:  cout<<"\nInvalid character";
			}
		}
		else
			cout<<"\nInvalid character "<<exp[i];
	
	cout<<"\nAnswer is: "<<s.pop();
	return 0;
}
