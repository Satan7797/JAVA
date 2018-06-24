//Write a function that checks whether a given string is Palindrome or not. Use this
//function to find whether the string entered by user is Palindrome or not.

#include<iostream>
#include<string.h>
using namespace std;

void palindrome(char s[]);

int main()
{
	char str[10];
	
	cout<<"Enter string:";
	gets(str);
	
	palindrome(str);		//calling the function to check the string
	
	return 0;
}

void palindrome(char s[10])
{

	int l=0,n=0;
	
	for(int i=0;s[i]!='\0';i++)		//for length of string
	l++;
	
	for(int j=0;j<l/2;j++,l--)		//to check whether string is palindrome or not
	{
		if(s[j]==s[l-1])
		  n=0;
		else
		  n++;
    }
    
	if(n==0)
    cout<<"Palindrome";
    else
    cout<<"Not palindrome";

}

