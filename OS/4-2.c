#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int i=0;
int main()
{
	fork();
	fork();
	fork();
	printf("\nChild %d",i++);
	printf("\nHello world");
	return 0;
}
