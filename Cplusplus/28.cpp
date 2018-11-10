//Reversing an array using pointers

#include<iostream>
using namespace std;

int ar[100];
int SIZE;

void reverse(int *f);

int main()
{
	cout<<"enter size:";
	cin>>SIZE;
	cout<<"Enter array:";
	for(int i=0;i<SIZE;i++)
	cin>>ar[i];
	reverse(ar);			//function call to reverse the array
	cout<<"\nReversed array:";
	for(int i=0;i<SIZE;i++)
	cout<<ar[i]<<" ";
	return 0;
}

void reverse(int *f)		//function to reverse array
{
	int l=SIZE-1;
	for(int i=0;i<SIZE/2;i++,l--)		//loop to interchange the elements of array
	{
		int temp=f[i];
		f[i]=f[l];
		f[l]=temp;
	}
}
