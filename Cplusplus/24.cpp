//Create a class Box containing length, breath and height. Include following methods in it:
//a) Calculate surface Area
//b) Calculate Volume
//c) Increment, Overload ++ operator (both prefix & postfix)
//d) Decrement, Overload -- operator (both prefix & postfix)
//e) Overload operator == (to check equality of two boxes), as a friend function
//f) Overload Assignment operator
//g) Check if it is a Cube or cuboid
//Write a program which takes input from the user for length, breath and height to test the above class.

#include<iostream>
using namespace std;
class Box
{
	float l,b,h;
	public:
		Box()		//Default Constructor
		{
			l=b=h=0;
		}

		void input(float l1,float b1,float h1)	//funtion to initialize values
		{
			l=l1;
			b=b1;
			h=h1;
		}

		double sa()				//function to calculate Surface Area
		{
			return (2*(l*b+l*h+h*b));
		}
		double volume()			//Function to calculate Volume
		{
			return l*b*h;
		}
		void operator ++()		//Funtion to overload Increment Operator(Prefix)
		{
			l+=1;
			b+=1;
			h+=1;
		}
		void operator --(int)	//function to overload Decrement operator(postfix)
		{
			l--;
			b--;
			h--;
		}
		void operator --()		//function to overload Decrement operator(prefix)
		{
			l-=1;
			b-=1;
			h-=1;
		}
		void operator ++(int)	//function to overload Increment opertor(prefix)
		{
			l++;
			b++;
			h++;
		}
		void operator =(Box &t)	//function to overload Assignment operator
		{
			l=t.l;
			b=t.b;
			h=t.h;
		}
		friend bool operator ==(Box &t,Box &t1);	//Prototype Friend funtion to overload Equality operator
		
		void display()		//funtion to display data
		{
			cout<<"\nlength:"<<l;
			cout<<"\nbreadth:"<<b;
			cout<<"\nheight:"<<h<<endl;
		}
		void check()		//function to check the equality of two Boxes
		{
			if(l!=0&&b!=0&&h!=0)
			{
			if(l==b&&b==h)
			cout<<"\n\nBox is a cube";
			else
			cout<<"\nBox is a cuboid";
			}
			else
			cout<<"\nSides are 0.";
		}
		
		~Box(){}		//Destructor
};

bool operator ==(Box &t,Box &t1)		//funtion definition to overload Equality operator
{
	if((t.l==t1.l&&t.b==t1.b&&t.h==t1.h))
		return 1;
	else
		return 0;
}

int main()
{
	float l,b,h;
	cout<<"Enter length,breadth and height:";
	cin>>l>>b>>h;
	Box f;
	Box f1;
	f.input(l,b,h);
	char c='y',ch;
	
	while(c=='y')				//while-loop for menu driven program
	{
		cout<<"\na) Calculate surface Area";
		cout<<"\nb) Calculate Volume";
		cout<<"\nc) Increment, Overload ++ operator (both prefix & postfix)";
		cout<<"\nd) Decrement, Overload -- operator (both prefix & postfix)";
		cout<<"\ne) to check equality of two boxes";
		cout<<"\nf) Assign values";
		cout<<"\ng) Check if it is a Cube or cuboid";
		cout<<"\nEnter your choice:";
		cin>>ch;
		
		if(ch=='a')
			cout<<"\nSurface area is "<<f.sa();
		else if(ch=='b')
			cout<<"\nVolume is "<<f.volume();
		else if(ch=='c')
			{	
				++f;
				f.display();
				f++;
				f.display();
			}	
		else if(ch=='d')
		{
			--f;
			f.display();
			f--;
			f.display();
		}	
		else if(ch=='e')
		{
			cout<<"\nEnter l,b,h:";
			cin>>l>>b>>h;
			f1.input(l,b,h);
			if(f==f1)
			cout<<"\n\nEqual!!!";
			else
			cout<<"\n\nNot Equal!!";
		}
		else if(ch=='f')
		{
			Box f2;
			f2=f;
			cout<<"\nShowing contents of f2...";
			f2.display();
		}
		else if(ch=='g')
		{
			cout<<"\nchecking f...";
			f.check();
			cout<<"\nchecking f1...";
			f1.check();
		}
		cout<<"\nDo you want to continue?(y/n):";
		cin>>c;
	}
return 0;
}
