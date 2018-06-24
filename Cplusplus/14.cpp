//Write a program which takes the radius of a circle as input from the user, passes 
//it to another function that computes the area and the circumference of the circle 
//and displays the value of area and circumference from the main() function.

#include<iostream>
using namespace std;

double calculate(int r)
{
	return (2*3.14*r*3.14*r*r);
}

int main()
{
	int radius;
	cout<<"\nEnter radius:";
	cin>>radius;
	
	double areaAndCircumfrence=calculate(radius);
	cout<<"\nArea is: "<<areaAndCircumfrence/(2*3.14*radius);
	cout<<"\nCircumfrence is: "<<areaAndCircumfrence/(3.14*radius*radius);
	return 0;
}
