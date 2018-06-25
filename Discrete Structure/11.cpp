/*Write a Program to calculate Permutation and Combination for an input value n and r using
  recursive formula of nCr and nPr .*/

#include<iostream>
using namespace std;

int R;

//function for combination
int nCr(int n,int r)
{
	if (r == 0 || r == n)
		return 1;
	return nCr(n-1, r-1) + nCr(n-1, r);
}

//function for permutation
int nPr(int n)
{
	if(R==0)
		return 1;
	else
	{
		R--;
		return (n*nPr(n-1));
	}
}

int main()
{
	int n,r;
	cout<<"\nEnter n and r:";
	cin>>n>>r;
	
	R=r;
	cout<<"\nCombinations:"<<nCr(n,r);
	cout<<"\nPermutations:"<<nPr(n);
	return 0;
}
