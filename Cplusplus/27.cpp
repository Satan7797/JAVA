//Copy the contents of one text file to another file, after removing all whitespaces.
//Make one text file named as "1st_File.txt" with some content in it (in the directory of the CPP)

#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
	ifstream fin("1st_File.txt");
	ofstream fout("2nd_File.txt");
	if(!fin)
	{
		char c;
		cout<<"\nNo File Found";
		fin>>c;
	}
	else
	{
		char ch;
			while(fin.eof()==0)
			{
				fin>>ch;
				if(isalnum(ch) != 0 || isalpha(ch) != 0 )
				fout<<ch;
			}
	}
	fin.close();
	fout.close();
	return 0;
}
