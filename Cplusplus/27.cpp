//Copy the contents of one text file to another file, after removing all whitespaces.

//Not sure for this one.

#include<iostream>
#include<fstream>
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

