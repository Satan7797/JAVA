//Write a Program to create a SET A and determine the cardinality of SET for an input array of
//elements (repetition allowed) and perform the following operations on the SET:
//a) ismember (a, A): check whether an element belongs to set or not and return value as
//   true/false.
//b) powerset(A): list all the elements of power set of A.

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int size;

bool ismember(int,int[]);
void PowerSet(int[], int);

int main()
{
	int A[20];

	cout<<"\nEnter number of elements to be entered:";
	cin>>size;
	cout<<"\nEnter Set A:";
	for(int i=0; i<size; i++)
		cin>>A[i];

	int a;

	cout<<"\nEnter value to be searched:";
	cin>>a;

	bool check=ismember(a,A);

	if(check==true)
		cout<<"\nValue found";
	else
		cout<<"\nValue not found";

	cout<<"\nPower set of A:\n";
	cout<<"{{},";
	PowerSet(A,size);
	cout<<"}";

	return 0;
}

bool ismember(int a,int A[])		
{
	bool c=false;
	for(int i=0; i<size; i++)
		if(a==A[i])
			c=true;
	return c;
}

void PowerSet(int a[],int s){
	int num=pow(2,s);
	cout<<"number of power set "<<num<<endl;
	int matrix[s][num];
	int n,j;
    for(int i=0;i<num;i++)
    {
    	j=s-1;
    	n=i;
    	do{
    		matrix[j--][i]=n%2;
    		n=n/2;
		  }
		while(j>=0);
	}
	cout<<"power set"<<endl;
	cout<<"{ ";
	for(int i=0;i<num;i++)
	{
		cout<<"{";
		for(int j=0;j<s;j++)
		{
			if(matrix[j][i]==1)
			cout<<a[j]<<",";	
		}
		cout<<"} ";
	}
	cout<<" ";
}
