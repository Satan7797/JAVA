//Show The Data Stored in Previous Program (i.e Program 25)


#include<iostream>
#include<fstream>

using namespace std;

struct Student
{
	char name[30];
	int roll;
	int marks;
	void output()
	{
		cout<<"\nName: "<<name;
		cout<<"\nRoll No: "<<roll;
   	cout<<"\nMarks: "<<marks;
	}
};

int main()
{
	Student s[10];
	ifstream fin("myfile.txt");
	int i=0;
	while(i<3)
	{
		cout<<"\n\nDetails Of Student "<<i<<" : \n";
    fin.read((char *)&s[i], sizeof(s[i]));
		s[i].output();
		i++;
	}
	fin.close();
	return 0;
}
