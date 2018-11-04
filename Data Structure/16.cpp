#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
	int temp;
	for(int i=0;i<n-1;i++)		//outer loop for pass
		for(int j=0;j<n-1-i;j++)
			if(a[j]>a[j+1]){			//if element at j is greater than element at j+1 then swap the values
   			    temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}		
}

void insertionSort(int a[],int n){
	int j,x;
	for(int i=1;i<n;i++){
		j=i-1;
		x = a[i];
		while(j>=0 && a[j]>x){
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = x;
	}	
}

void selectionSort(int a[],int n){
	int min=0,j,temp;
	for(int i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++)
			if(a[min]>a[j])
				min=j;
		
		if(min!=i){
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
}

void merge(int arr[],int l,int m,int r) { 
    int i,j,k; 
    int n1=m-l+1,n2=r-m; 
  
    int L[n1],R[n2]; 
  
    for (i=0;i<n1;i++) 
    L[i]=arr[l+i]; 
    for (j=0;j<n2;j++) 
    R[j]=arr[m+1+j]; 
  
    i=0,j=0,k=l; 
    while (i<n1 && j<n2) { 
        if (L[i]<=R[j]) 
        arr[k]=L[i++];  
        else
        arr[k]=R[j++];  
        k++; 
    } 
  
    while (i<n1) { 
        arr[k]=L[i++]; 
        k++; 
    } 
  
    while (j<n2) { 
        arr[k]=R[j++]; 
        k++; 
    } 
} 
  
void mergeSort(int arr[],int l,int r) { 
    if (l<r) { 
        int m=l+(r-l)/2; 
  
        mergeSort(arr,l,m); 
        mergeSort(arr,m+1,r); 
  
        merge(arr,l,m,r); 
    } 
} 

int partition(int arr[],int l,int r) { 
    int pivot=arr[r];  
    int i=(l-1),temp;   
  
    for (int j=l;j<=r-1;j++) { 
        if (arr[j]<=pivot) { 
            i++;    
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp; 
        } 
    } 
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp; 
    return i+1; 
} 
  
void quickSort(int arr[],int l,int r) { 
    if (l<r){ 
        int pi=partition(arr,l,r); 
  
        quickSort(arr,l,pi-1); 
        quickSort(arr,pi+1,r); 
    } 
}

int linearSearch(int a[],int x){
	int size=sizeof(a)/sizeof(a[0]);
	int pass=0,i;
	
	for(i=0;i<size;i++)
	if(a[i]==x){
		pass=1;
		break;
	}
	
	if(pass==1)
		return i;
	return -1;
}

int binarySearch(int a[],int first,int last,int x){
	if(first<=last){
		int mid=(first+last)/2;

		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			return binarySearch(a,first,mid-1,x);
		else if(a[mid]<x)
			return binarySearch(a,mid+1,last,x);
	}
	return -1;
}

void array(int a[],int size)
{
	cout<<"\nArray is: ";
	for(int i=0;i<size;cout<<a[i++]<<" ");
}

int main(){
	int n,x;
	cout<<"Enter size of array: ";
	cin>>n;
	
	int a[n];
	cout<<"\nEnter array: ";
	for(int i=0;i<n;cin>>a[i],i++);
	
	char choice;
	do{
		cout<<"\na) Bubble Sort";
		cout<<"\nb) Insertion Sort";
		cout<<"\nc) Selection";
		cout<<"\nd) Merge Sort";
		cout<<"\ne) Quick Sort";
		cout<<"\nf) Linear Sort";
		cout<<"\ng) Binary Search";
		cout<<"\nh) Re-enter array";
		cout<<"\ni) Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		if(choice=='h'){
			cout<<"\nEnter array: ";
			for(int i=0;i<n;cin>>a[i],i++);
		}
		
		if(choice=='a'){
			bubbleSort(a,n);
			array(a,n);
		}else if(choice=='b'){
			insertionSort(a,n);
			array(a,n);
		}else if(choice=='c'){
			selectionSort(a,n);
			array(a,n);
		}else if(choice=='d'){
			mergeSort(a,0,n-1);
			array(a,n);
		}else if(choice=='e'){
			quickSort(a,0,n-1);
			array(a,n);
		}else if(choice=='f')
			cout<<"\nEnter the number you want to search: ";
			cin>>x;
			x=linearSearch(a,x);
			if(x==-1)
			cout<<"\nNot found in array";
			else
			cout<<"\nFound at: "<<x;
		}else if(choice=='g'){
			cout<<"\nEnter the number you want to search: ";
			cin>>x;
			x=binarySearch(a,0,n,x);
			if(x==-1)
			cout<<"\nNot found in array";
			else
			cout<<"\nFound at: "<<x;			
		}
	}while(choice!='i');
	
	return 0;
}
