//WAP to reverse a number.

#include<iostream>
using namespace std;
int main()
{
	int reversed_no=0,n,original_no;
	cout<<"Enter the number:";
	cin>>original_no;
	
    while(original_no!=0 )		//loop to reverse the number
    {
        reversed_no=reversed_no*10 +original_no%10;
        original_no/=10;
    }
	cout<<"Reversed number:"<<reversed_no;
	return 0;
}
