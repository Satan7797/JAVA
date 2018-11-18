#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
	int value=5;
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		value+=15;
		printf("Print value=%d",value);
	}
	else if(pid>0)
	{
		wait(NULL);
		printf("Print value=%d",value);
	}
	return 0;
}
