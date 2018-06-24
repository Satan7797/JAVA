//WAP that prints a table indicating the number of occurrences of each 
//alphabet in the text entered as command line arguments.

#include<iostream>
#include<string.h>
using namespace std;

int main(int argc,char *argv[])
{
	int i;
	int count=0;

	cout<<"\nParameters are\n";
	for(i=1;i<argc;i++)

	cout<<argv[i]<<" ";

	for(char k='a';k<='z';k++)
	{
	  for(i=1;i<argc;i++)
    	{
			for(int j=0;argv[i][j]!='\0';j++)
			{
				if(isupper(argv[i][j]))
				argv[i][j]=tolower(argv[i][j]);
				if(argv[i][j]==k)
				count++;
			}
		}
		if(count>0)
		cout<<"\n"<<k<<" occurs "<<count<<" times.";
		count=0;
	}
	cout<<"\nEnd";

	return 0; 
}

