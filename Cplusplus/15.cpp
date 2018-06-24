//Write a program to find sum of n elements entered by the user. To write this program, 
//allocate memory dynamically using malloc() / calloc() functions or new operator.

#include<iostream>
using namespace std;

int main()
{
	int n;
	int *arr,sum=0;
	cout<<"Enter n:";
	cin>>n;
	arr=new int[n];
	cout<<"Enter "<<n<<" elements:";
	for(int i=0;i<n;i++)	//loop to input the elements and calculate sum
	{
		cin>>*(arr+i);
		sum+=arr[i];	
	}
	cout<<"Sum of numbers:"<<sum;
	delete[] arr;
	return 0;
}
