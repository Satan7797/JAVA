//Write a menu driven program to perform following operations on strings:
//a) Show address of each character in string
//b) Concatenate two strings without using strcat function.
//c) Concatenate two strings using strcat function.
//d) Compare two strings
//e) Calculate length of the string (use pointers)
//f) Convert all lowercase characters to uppercase
//g) Convert all uppercase characters to lowercase
//h) Calculate number of vowels
//i) Reverse the string

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[200],c='y';
	char a;

	cout<<"Enter a string:";
	gets(s);

	char s1[200];

	cout<<"Enter second string:";
	gets(s1); 		

	while(c=='y')		//while-loop for menu driven program
	{
		cout<<"a) Show address of each character in string\nb) Concatenate two strings without using strcat function.\n";
		cout<<"c) Concatenate two strings using strcat function.\nd) Compare two strings\n";
		cout<<"e) Calculate length of the string (use pointers)\nf) Convert all lowercase characters to uppercase\n";
		cout<<"g) Convert all uppercase characters to lowercase\nh) Calculate number of vowels\ni) Reverse the string\n";
		cout<<"Enter your choice:";
		cin>>a;

		if(a=='a')
		{
			int i=0;

			while(s[i]!='\0')		//loop to show address of each Character
			 {
				cout<<"\nAddress of "<<s[i]<<" is "<<(void*)&s[i];
		 	 	i++;
			 }
		}
		else if(a=='b')
		{
			int l=strlen(s);
			for(int j=0;s1[j]!='\0';l++,j++)		//loop to concatenate string
			s[l]=s1[j];
			s[l]='\0';
			cout<<"\nNew string is "<<s;
	 	}
	 	else if(a=='c')
	 	{
	 		strcat(s,s1);					//function call to concatenate two strings
	 		cout<<"New string:"<<s;
		}
		else if(a=='d')						//to compare two strings
		{
			if(strcmp(s,s1)==0)
			cout<<"\nEntered strings are equal";
			else
			cout<<"\nNot equal.";
		}
		else if(a=='e')					//to calculate string length using pointer
		{
			int count=0;
			char* p=s;
			while(*p!='\0')
			{
				count++;
				p++;
			}
			cout<<"\nLength of string is "<<count;
		}
		else if(a=='f')
		{
			int i=0;
			while(s[i]!='\0')			//loop to convert all lower case alphabet into upper case alphabets
			{
				if(islower(s[i]))
				s[i]=toupper(s[i]);
				i++;
			}
			cout<<s;
		}
		else if(a=='g')
		{
			int j=0;
			while(s[j]!='\0')			//loop to convert all upper case alphabets into lower case alphabets 
			{
				if(isupper(s[j]))
				s[j]=tolower(s[j]);
				j++;
			}
			cout<<s;
		}
		else if(a=='h')
		{
			int count=0;
			for(int i=0;s[i]!='\0';i++)			//loop to count the number of vowels in the string
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			count++;
			cout<<"\nNumber of vowels:"<<count;
		}
		else if(a=='i')
		{
			char rev[200];
			int l=strlen(s);
			int i;
			for(i=0;l>=0;i++,l--)		//loop to store the reverse of string in second string
			rev[i]=s[l-1];
			rev[i]='\0';
			cout<<"\nNew string is "<<rev;			
		}
		cout<<"\nDo you want to continue?(y/n):";
		cin>>c;
	}
	
	return 0;
}

