#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

void reverse(char s[],int start,int end)
{
	if(end>start)
	{
		char temp=s[start];
		s[start]=s[end];
		s[end]=temp;
		reverse(s,start+1,end-1);
	}
	return;
}
int main()
{
	string s;
	cout<<"\nEnter the string: ";
	getline(cin,s);	
	char str[s.length()+1];
	strcpy(str,s.c_str());
	reverse(str,0,strlen(str)-1);
	cout<<"\nReverse of entered string is=";
	puts(str);
	return 0;
}
