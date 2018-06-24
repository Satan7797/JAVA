//Create a structure Student containing fields for Roll No., Name, Class, Year and Total Marks. 
//Create 10 students and store them in a file.

//Not sure for this one.

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
	char ch;
	ifstream fin("myfile.txt");
	for(int i=0;i<10;i++)
	{
		fin>>s[i].name>>s[i].roll>>s[i].marks;
		cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].marks<<endl;
	}
	fin.close();
	return 0;
}
