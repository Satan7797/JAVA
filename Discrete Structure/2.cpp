//Create a class SET and take two sets as input from user to perform following SET
//Operations:
//a) Subset: Check whether one set is a subset of other or not.
//b) Union and Intersection of two Sets.
//c) Complement: Assume Universal Set as per the input elements from the user.
//d) Set Difference and Symmetric Difference between two SETS
//e) Cartesian Product of Sets.

#include<iostream>
using namespace std;

class set
{
  int A[20],B[20],a[20],b[20],U[20],C[20],D[20],AUB[40];
  int m,n,c,d,u,a1;

  public:
   void input()
    {
	cout<<"\nEnter m:";
	cin>>m;
	cout<<"\nEnter A:";
	for(int i=0; i<m; i++)
	 cin>>A[i];
	cout<<"\nEnter n:";
         cin>>n;
	cout<<"\nEnter B:";
	for(int i=0; i<n; i++)
	 cin>>B[i];
	cout<<"\nEnter size of universal set:";
         cin>>u;
	cout<<"\nEnter universal set:";
	for(int i=0; i<u; i++)
	 cin>>U[i];
    }

   void subset()
    {
	int j=0,count=0,m1,n1;
	if(m>n)
	{
	  m1=m;
	  n1=n;
	}
	else if(m<n)
	{
	  m1=n;
	  n1=m;
	}

	for(int i=0; i<n1; i++)
         for(j=0; j<m1; j++)
	  if(A[j]==B[i] && m1==m)
	   {
		count++;
		break;
	   }
	  else if(A[i]==B[j] && m1==n)
	   {
		count++;
		break;
	   }

        if(count==n)
	  cout<<"\n\nB is a subset of A";
	else if(count==m)
	  cout<<"\n\nA is a subset of B";
    }

   void Union()
    {
	int l=m,f=m+n;

	for(int i=0; i<m; i++)
	AUB[i]=A[i];

	for(int i=0; i<n; i++)
	AUB[l++]=B[i];

	for(int i=0; i<f; i++)		
         {
	   int temp=AUB[i];
	   for(int j=0; j<f; j++)
	    if(temp==AUB[j]&&i!=j)
	     {
		for(int k=j; k<f; k++)
		AUB[k]=AUB[k+1];
		f--;
	     }
	 }
	cout<<"\n\nUnion of Set A and B:{";
	for(int i=0; i<f; i++)
	cout<<AUB[i]<<" ";

	cout<<"\b}";
    }

   void Inter()
    {
	a1=0;

	cout<<"\n\nIntersection of A and B:{ ";
	for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
	  if(A[i]==B[j])
	   a[a1++]=A[i];

	cout<<"\b}";
    }

   void complement()
    {
	int complA[]= {0},complB[]= {0};
	int coA=0,coB=0;

	cout<<"\n\nComplement of set A:";
	for(int i=0; i<u; i++)
         {
	   int temp=U[i],count=0;
	   for(int j=0; j<m; j++)
	    if(temp==A[j])
	     count++;

           if(count==0)
	     cout<<temp<<" ";
         }

	cout<<"\nComplement of set B:";
	for(int i=0; i<u; i++)
         {
	   int temp=U[i],count=0;
	   for(int j=0; j<m; j++)
	    if(temp==B[j])
	     count++;

           if(count==0)
	    cout<<temp<<" ";
         }

    }

   void setdiff()
    {
	c=0,d=0;
	for(int i=0; i<m; i++)
	{
	  int temp=A[i],count=0;
	  for(int j=0; j<n; j++)
	  if(temp==B[j])
	   count++;

          if(count==0)
	    C[c++]=temp;
	}

	cout<<"\n\nA-B:{ ";
   	for(int i=0; i<c; i++)
          cout<<C[i]<<" ";

	cout<<"\b}";
	for(int i=0; i<n; i++)
          {
	    int temp=B[i],count=0;
	    for(int j=0; j<m; j++)
	    if(temp==A[j])
	     count++;

           if(count==0)
	     D[d++]=temp;
         }

       cout<<"\n\nB-A:{ ";
       for(int i=0; i<d; i++)
	cout<<D[i]<<" ";

       cout<<"\b}";
    }

   void symm()
    {
	int f=c+d,l=c;

	for(int i=0; i<c; i++)
	b[i]=C[i];

	for(int i=0; i<d; i++)
	b[l++]=D[i];

	for(int i=0; i<f; i++)
	{
	  int temp=b[i];
	  for(int j=0; j<f; j++)
	  if(temp==b[j]&&i!=j)
	  {
	    for(int k=j; k<f; k++)
	    b[k]=b[k+1];
	    f--;
	  }
	}
	cout<<"\n\nSymmetric Difference:{";
	for(int i=0; i<f; i++)
	  cout<<b[i]<<" ";

	cout<<"\b}";
    }

   void Cart()
    {
	cout<<"\n\nAxB:{";
	for(int i=0; i<m; i++)
	{
	   for(int j=0; j<n; j++)
	     cout<<"("<<A[i]<<","<<B[j]<<") ";
	}
	cout<<"\b}";

	cout<<"\n\nBxA:{";
	for(int i=0; i<n; i++)
	{
          for(int j=0; j<m; j++)
	   cout<<"("<<B[i]<<","<<A[j]<<") ";
	}
	cout<<"\b}";
    }

   void output()
    {
	subset();
	Union();
	complement();
	Inter();
	setdiff();
	symm();
	Cart();
    }
};

int main()
{
	set s;
	s.input();
	s.output();
	return 0;
}
