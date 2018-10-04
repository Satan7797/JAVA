#include<iostream>
#include<stack>
using namespace std;

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
	else if(exp[i]>=42 && exp[i]<=47)
	{
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		switch(exp[i])
		{
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
	cout<<"\nAnswer is: "<<s.top();
	s.pop();
	return 0;
}
