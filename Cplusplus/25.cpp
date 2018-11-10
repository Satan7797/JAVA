//Create a structure Student containing fields for Roll No., Name, Class, Year and Total Marks.
//Create 10 students and store them in a file.


#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
	string name;
	int roll;
	int marks;
};

int main()
{
	Student s[10];
	int i;
	for (i=0;i<10;i++)
	{	cout<<"\nDetails of Student "<<i+1<<" : ";
		cout<<"\nEnter the Name of Student: ";
		cin>>s[i].name;
		cout<<"Enter the Roll No: ";
		cin>>s[i].roll;
		cout<<"Enter the Marks: ";
		cin>>s[i].marks;
	}
	ofstream fout("myfile.txt");
	i=0;
	while(i<10)
	{
		fout<<s[i].name<<s[i].roll<<s[i].marks;
		cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].marks<<endl;
		i++;
	}
	fout.close();
	return 0;
}
