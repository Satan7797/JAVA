/*Write a Program to accept the truth values of variables x and y, and print the truth table of
  the following logical operations:
  a) Conjunction    f) Exclusive NOR
  b) Disjunction    g) Negation
  c) Exclusive OR   h) NAND
  d) Conditional    i) NOR
  e) Bi-conditional*/

#include<iostream>
using namespace std;

bool and1(int,int);
bool or1(int,int);
bool nand(int,int);
bool nor(int,int);
bool neg1(int);
bool neg2(int);
bool exor(int,int);
bool exnor(int,int);
bool condition(int,int);
bool bicond(int,int);

int main()
{
   cout<<"X"<<"\t"<<"Y"<<"\t"<<"AND"<<"\t"<<"OR"<<"\t"<<"NAND"<<"\t"<<"NOR"<<"\t"<<"~X";
   cout<<"\t"<<"~Y"<<"\t"<<"EX.OR"<<"\t"<<"EX.NOR"<<"\t"<<"CONDITIONAL"<<"\t"<<"BICONDITIONAL"<<"\n\n";
   
   for(int i=0;i<=1;i++)
     for(int j=0;j<=1;j++)
      {
	     cout<<i<<"\t"<<j<<"\t"<<and1(i,j)<<"\t"<<or1(i,j)<<"\t"<<nand(i,j)<<"\t";			
	     cout<<nor(i,j)<<"\t"<<neg1(i)<<"\t"<<neg2(j)<<"\t"<<exor(i,j)<<"\t";
	     cout<<exnor(i,j)<<"\t"<<condition(i,j)<<"\t\t"<<bicond(i,j)<<"\n\n";
      }

   return 0;
}

bool and1(int x,int y)
 {
   return x&&y;
 }

bool or1(int x,int y)
 {
   return x||y;
 }

bool nand(int x,int y)
 {
   return !(x&&y);
 }

bool nor(int x,int y)
 {
   return !(x||y);
 }

bool neg1(int x)
 {
   return !x;
 }

bool neg2(int y)
 {
   return !y;
 }

bool exor(int x,int y)
 {
   if(x==y)
    return 0;
   
   return 1;
 }

bool exnor(int x,int y)
 {
   return !exor(x,y);
 }

bool condition(int x,int y)
 {
   if(x==y)
    return 1;
   else if(y==0)
    return 0;
   return 1;
 }

bool bicond(int x,int y)
 {
    return exnor(x,y);
 }
