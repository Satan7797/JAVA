//Create a structure Student containing fields for Roll No., Name, Class, Year and Total Marks. 
//Create 10 students and store them in a file.

//Not sure for this one.

#include<iostream>
#include<fstream>
using namespace std;
struct Student
{
	char* name;
	int roll;
	int marks;
};
int main()
{
	Student s[10];
 
 	ofstream fout;
	fout.open("myfile.txt");

	cout<<"fill details of students: \n";

	for(int i=0;i<10;i++)
	{
		cout<<"\nname:";
		gets(s[i].name);
		cout<<"roll:";
		cin>>s[i].roll;
		cout<<"marks:";
		cin>>s[i].marks;
		fout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].marks<<"\n";
	}

	fout.close();

	return 0;
}

