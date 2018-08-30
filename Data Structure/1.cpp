#include<iostream>
using namespace std;

class matrix
{
	int n;
	int *d;
	char choice;
	public:
		matrix(int size, char ch)
		{
			choice= ch;
			n= size;
			d= new int[n];
		}
		~matrix()
		{
		    cout<<"\nDestructor called\n";
		}
		
		void di_set(const int&, int, int);
		int di_get(int, int) const;
		void low_set(const int&, int, int);
		int low_get(int, int) const;
		void up_set(const int&, int, int);
		int up_get(int, int) const;
		void sym_set(const int&, int, int);
		int sym_get(int, int) const;
		void set(const int&, int, int);
		int get(int, int) const;
};


int main()
{
	char ch;
	
	do
	{
		cout<<"a) Diagonal"<<endl;
		cout<< "b) Lower triangle\n";
		cout<<"c) Upper triangle\n";
		cout<<"d) Symmetric matrix\n";
		cout<<"e) Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
	
		
		if(ch >= 'a' && ch <= 'd')
		{
			repeat:
		    int m, n, size;
			cout<<"\nEnter number of rows and columns: ";
		    cin>>m>>n;
			
			if(ch>'a' && ch<='d' && m!=n)
			{
				cout<<"\nNumber of Rows and columns should be equal";
				goto repeat;
			}
			
			if(ch == 'a')
			size = m;
			else
			size = m*(m+1)/2;
			
			matrix mat(size,ch);
			
			int x;
			cout<<"\nEnter matrix:\n";
			for(int i= 0; i<m; i++)
			for(int j= 0; j<n; j++)
			{
				cin>>x;
				mat.set( x, i, j);
			}
		
			cout<<"\nMatrix is:\n";
			for(int i=0;i< m;i++)
			{
				for(int j=0;j<n;j++)
				cout<<mat.get(i,j)<<" ";
				cout<<"\n";
			}
		}
	}while(ch!='e');
	return 0;
}
void matrix::set(const int &x,int i,int j)
{
	if(choice=='a')
	di_set(x,i,j);
	else if(choice=='b')
	low_set(x,i,j);
	else if(choice=='c')
	up_set(x,i,j);
	else 
	sym_set(x,i,j);
}

int matrix::get(int i,int j) const
{
	if(choice=='a')
	return di_get(i,j);
	else if(choice=='b')
	return low_get(i,j);
	else if(choice=='c')
	return up_get(i,j);
	else 
	return sym_get(i,j);
}

void matrix::di_set(const int &x,int i,int j)
{
	if(i==j)
	d[i]=x;
}

int matrix::di_get(int i,int j) const
{
	if(i==j)
	return d[i];
	else
	return 0;
}

void matrix::low_set(const int &x,int i,int j)
{
	if(i>=j)
	d[i*(i+1)/2+j]=x;
}

int matrix::low_get(int i,int j) const
{
	if(i>=j)
	return d[i*(i+1)/2+j];
	return 0;
}

void matrix::up_set(const int &x,int i,int j)
{
	if(i<=j)
	d[j*(j+1)/2+i]=x;	
}

int matrix::up_get(int i,int j) const
{
	if(i<=j)
	return d[j*(j+1)/2+i];
	else
	return 0;	
}

void matrix::sym_set(const int &x,int i,int j)
{
	if(i<=j)
	d[j*(j+1)/2+i]=x;		
}

int matrix::sym_get(int i,int j) const
{
	if(i<=j)
	return d[j*(j+1)/2+i];
	return d[i*(i+1)/2+j];
}
