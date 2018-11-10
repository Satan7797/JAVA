//Create a structure Student containing fields for Roll No., Name, Class, Year and Total Marks.
//Create 10 students and store them in a file.


#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
	char name[30];
	int roll;
	int marks;
	void input()
	{
		cout<<"\nEnter the Name of Student: ";
		cin.getline(name, 30);
		cin.ignore();
		cout<<"Enter the Roll No: ";
		cin>>roll;
		cout<<"\nEnter the Marks: ";
		cin>>marks;
		cin.get();
	}
	void output()
	{
		cout<<"\nRoll No: "<<roll;
   	cout<<"\nName: "<<name;
   	cout<<"\nMarks: "<<marks;
	}
};

int main()
{
	Student s[3];
	ofstream fout("myfile.txt");
	int i;
	for(i=0;i<3;i++)
	{
		cout<<"\nDetails of Student "<<i+1<<" : ";
		s[i].input();
		fout.write((char *)&s[i], sizeof(s[i]));
	}
	fout.close();
	return 0;
}
