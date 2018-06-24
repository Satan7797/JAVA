//WAP to perform following actions on an array entered by the user:
//i) Print the even-valued elements
//ii) Print the odd-valued elements
//iii) Calculate and print the sum and average of the elements of array
//iv) Print the maximum and minimum element of array
//v) Remove the duplicates from the array
//vi) Print the array in reverse order
//The program should present a menu to the user and ask for one of the options. 
//The menu should also include options to re-enter array and to quit the program.

#include<iostream>
using namespace std;

int main()
{
	int ar[200],n,y,a=0;
	char c='y';
	do										//do-while loop for menu driven program
	{
		if(a>0)
		{
			cout<<"\nDo you want to renter the array?(y/n):";
			cin>>c;
		}
		
		if(c=='y')
		{
			cout<<"Enter number of elements:";
			cin>>y;
			cout<<"Enter elements of array:";
			for(int i=0;i<y;i++)
			cin>>ar[i];
		}
		
		
		cout<<"\n1) Print the even-valued elements\n2) Print the odd-valued elements\n";
		cout<<"3) Calculate and print the sum and average of the elements of array\n4) Print maximum and minimum value of array\n5) Remove the duplicates from the array";
		cout<<"\n6) Print the array in reverse order\n7) To exit";
		cout<<"\nEnter your choice:";
		cin>>n;
				
		a++;
	
		if(n==1)		
		{
			cout<<"\nList of even-valued elements:";
			for(int i=0;i<y;i++)		//loop for printing even valued elements
			if(ar[i]%2==0)
			cout<<ar[i]<<" ";
		}
	
		else if(n==2)
		{
			cout<<"\nList of odd-valued elements:";
			for(int i=0;i<y;i++)			//loop for printing odd valued elements
			if(ar[i]%2!=0)
			cout<<ar[i]<<" ";
		}
	
		else if(n==3)
		{
			int sum=0;
			float avg;
			for(int i=0;i<y;i++)		//loop for calculatin the sum of elements
			sum+=ar[i];
			avg=sum/y;
			cout<<"\nSum of elements:"<<sum;
			cout<<"\nAverage of elements:"<<avg;
		}
	
		else if(n==4)
		{
			int max=ar[0],min=ar[0];
			for(int i=1;i<y;i++)		//loop to find maximum and minimum elements in the string
			if(ar[i]>max)
			max=ar[i];
			else 
			min=ar[i];
			
			cout<<"Maximum value is "<<max;
			cout<<"Minimum value is "<<min;
		}
	
		else if(n==5)
		{
			int f=y;
	 		for(int i=0;i<f;i++)		//loop to remove duplicate values from the array
			{
				int temp=ar[i];
				for(int j=0;j<f;j++)
					if(temp==ar[j]&&i!=j)
					{
						for(int k=j;k<f;k++)
						ar[k]=ar[k+1];
						f--;
					}
			}
			cout<<"\nNew array:";
			for(int i=0;i<f;i++)
			cout<<ar[i]<<" ";
	    }
	
		else if(n==6)
		{
			cout<<"Array in reverse order:\n";
			for(int i=y-1;i>=0;i--)		//loop to print array in reverse order
			cout<<ar[i]<<" ";
		}		
		
	}while(n!=7);
	
	return 0;
}

