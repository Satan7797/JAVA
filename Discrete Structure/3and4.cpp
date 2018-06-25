//Question-3: Create a class RELATION, use Matrix notation to represent a relation. Include functions to
//            check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program
//            to use this class.
//Ouestion-4: Use the functions defined in Ques 3 to find check whether the given relation is:
//            a) Equivalent, or
//            b) Partial Order relation, or
//            c) None


#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter order of matrix : ";
	cin>>n;
	int m[n][n],r=1,ir=1,s=1,ans=1,tr=1;
	cout<<"Enter matrix \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>m[i][j];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(m[i][i]!=1)
			r=0;
			if(m[i][i]!=0)
			ir=0;
		}
	}
	 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(m[i][j]==1&&m[j][i]!=1)
			s=0;
			if(m[i][j]==1&&m[j][i]==1&&i!=j)
			ans=0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
		if(m[i][j]==1&&m[j][k]==1&&m[i][k]!=1)
		tr=1;
	}
	
	if(r==1)
	cout<<"\nRelation is Reflexive";
	else if(ir==1)
	cout<<"\nRelatin is Ir-reflexive";
	else
	cout<"\nRelation is neither is Reflexive nor Ir-reflexive";
	
	if(s==1)
	cout<<"\nRelation is symetric";
	else if(ans==1)
	cout<<"\nRelation is Anti-Symetric";
	else
	cout<<"\nReelation is not Symetric";
	
	if(tr==1)
	cout<<"\nRelation is transtive ";
	else
	cout<<"\nRelation is not transtive";
	
	if(r==1&&s==1&&tr==1)
	cout<<"\nRelation is Equivalence";
	else
	cout<<"\nRelation is not Equivalence";
	
	if(r==1&&ans==1&&tr==1)
	cout<<"\nRelation is Partial Ordering Relation";
	else
	cout<<"\nRelation is not Partial Ordering Relation";
	return 0;
}
