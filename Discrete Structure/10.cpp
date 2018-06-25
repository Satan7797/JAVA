/*Write a Program that generates all the permutations of a given set of digits, with or without
  repetition.*/
#include<iostream>
#include <string.h>
using namespace std;
 
// Function to swap values at two pointers 
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
//function to permutate string without repitation
void permute(char a[], int l, int r)
{
   int i;
   if (l == r)
     cout<<"\n"<<a;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); 
       }
   }
}

int main()
{
    char str[10];
    cout<<"Enter the set(1,2,3...):";
	cin>>str;
	
	//loop to remove ',' from string str
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]==',')
		{
			for(int j=i;str[j]!='\0';j++)
			str[j]=str[j+1];
		}
	}
	    
	int n = strlen(str);
    
    cout<<"\nPermutations are:\n";
    permute(str, 0, n-1);
    return 0;
}
