//Create a class Triangle. Include overloaded functions for calculating area. Overload assignment operator 
//and equality operator.

#include<iostream> 
#include<math.h>

using namespace std;

		//Class Traingle
class triangle 
{ 
	float v1,v2,b,h; 
	double AREA; 
	public: 
		triangle() 			//Default constructor
		{  
			v1=v2=b=h=0; 
			AREA=0.0; 
		} 
		triangle(float v11,float v22,float b1)  //Parameterized Constructor for three sides
		{ 
			v1=v11; 
			v2=v22; 
			b=b1; 
			h=0; 
			AREA=area(v1,v2,b); 
		} 
		triangle(float h1,float b1)	//Parameterized constructor for Base and Height
		{ 
			h=h1; 
			b=b1; 
			v1=v2=0; 
			AREA=area(h,b); 
		} 
 
		double area(float s1,float s2,float s3)	//function for calculating area using three sides
		{ 
			double X; 
			float s=s1+s2+s3; s/=2; 
			X=sqrt((s)*(s-s1)*(s-s2)*(s-s3)); 
			return(X);  
		} 
		double area(float h1,float b1)		//fuction for calculating area using Base and Height
		{ 
			double X; 
			X=h1*b1*(0.5); 
			return(X); 
		}

		bool operator ==(triangle &t)		//Operator overloading of Equality operator
		{
			return area()==t.area(); 
		}

		void operator =(triangle &t)		//Operator overloading of Assignment operator
		{
			v1=t.v1;
			v2=t.v2;
			b=t.b;
			h=t.h;
			AREA=t.area();
		}
		double area()				//Function to return area of traingle
		{
			return AREA;
		}
		~triangle(){}		//Destructor
};

int main()
{
	int n;
	
	cout<<"1.Area using base and hieght\n2.Area using length of sides\nEnter your choice:";
	cin>>n;
	
	if(n==1)
	{
		float v1,v2,b,h;
		
		cout<<"Enter base and height:";
		cin>>b>>h;
		cout<<"Enter base and height for second object:";
		cin>>v1>>v2;	
		
		triangle t(b,h);
		triangle t1(v1,v2);
		
		cout<<"Area of first triangle:"<<t.area();
		cout<<"\nArea of second triangle:"<<t1.area();
		
		if(t1==t)
		cout<<"\n\nequal triangles";
		else
		cout<<"\n\nnot equal";
	
		triangle t2;
		t2=t;
	
		if(t2==t1)
		cout<<"\n\nEqual";
		else
		cout<<"Not equal";
	}
	else if(n==2)
	{
		float a,b,c;
		float a1,b1,c1;
	
		cout<<"Enter the three sides for first object:";
		cin>>a>>b>>c;
	
		cout<<"Enter sides for second object:";
		cin>>a1>>b1>>c1;
	
		triangle t(a,b,c);
		triangle t1(a1,b1,c1);
	
		cout<<"\nArea of first triangle:"<<t.area();
		cout<<"\nArea of second trianle:"<<t1.area();
	
		if(t1==t)
		cout<<"\n\nEqual";
		else
		cout<<"\n\nNot equal";
		
		triangle t2;
		t2=t;
	
		if(t2==t)
		cout<<"\nOk!";
		else
		cout<<"\nSorry.";
	}
	return 0;
}

