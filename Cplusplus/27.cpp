//Copy the contents of one text file to another file, after removing all whitespaces.

#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;

	char ch;

	fin.open("myfile.txt");
	fout.open("temp.txt");

	if(!fin)
	cout<<"file not exist \n";

	while(!fin.eof())
	{
		fin>>ch;
		if(isalnum(ch) != 0 || isalpha(ch) != 0 )
		fout<<ch;
	}

	fin.close();
	fout.close();

	fin.open("temp.txt");

	while(!fin.eof())
    {
		fin.get(ch);
	  cout<<ch;
    }

	fin.close();

 return 0;
}
