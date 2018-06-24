//Create the Person class. Create some objects of this class (by taking information from the user). 
//Inherit the class Person to create two classes Teacher and Student class. Maintain the respective 
//information in the classes and create, display and delete objects of these two classes (Use Runtime Polymorphism).

#include<iostream>
using namespace std;

class Person		//defining Base Class Person
{
	int age,sn;
	public:
		Person(int sn1,int age1)	//parameterized constructor
		{
			sn=sn1;
			age=age1;
		}
		virtual void show()		//virtual function for runtime polymorphism
		{
		}
		int Sn()				//funtion to return Serial Number
		{
			return sn;
		}
		int Age()				//function to return Age
		{
			return age;
		}
		~Person(){}		//Destructor for class Person
};

class Teacher:public Person			//Class teacher Derived from Class Person
{
	char* name;
	int sal;
	public:
		Teacher(int sn,int age,char name1[20],int salary):Person(sn,age) //parameterized constructor
		{
			name=name1;
			sal=salary;
		}
		void show()						//function for runtime polymorphism
		{
			cout<<"\n\nThis person is a Teacher.";
			display();
		}
		void display()					//funtion to display data
		{
			cout<<"\nS.No."<<Sn();
			cout<<"\nName:"<<name;
			cout<<"\nAge:"<<Age();
			cout<<"\nSalary:"<<sal;
		}
		
		~Teacher(){}		//Destructor for class Teacher
};

class Student:public Person			//Class Student derived from Class Paerson
{
	char* name;
	int Clas;
	public:
		Student(int sn,int age,char* name1,int Class):Person(sn,age)	//parameterized Constructor
		{
			name=name1;
			Clas=Class;
		}
		void show()			//function for runtimr polymorphism
		{
			cout<<"\n\nThis person is a Student.";
			display();
		}
		void display()		//function to display data
		{
			cout<<"\nS.no.:"<<Sn();
			cout<<"\nName:"<<name;
			cout<<"\nAge:"<<Age();
			cout<<"\nClass:"<<Clas;
		}
		~Student(){}		//Destructor for class Student
};


int main()
{
	int age,sn;
	char* name;
	
	cout<<"Enter S.No.:";
	cin>>sn;
	cout<<"Enter name:";
	cin>>name;
	cout<<"Enter Age:";
	cin>>age;
	
	Person* p;
	
	if(age>25&&age<60)
	{
	int salary;
	cout<<"Enter salary:";
	cin>>salary;
	Teacher tp(sn,age,name,salary);
	p=&tp;
	}
	else
	{
	int Class;
	cout<<"Enter class:";
	cin>>Class;
	Student sp(sn,age,name,Class);
	p=&sp;
	}
	
	p->show();
	
	delete[] p;
	
	return 0;
}

