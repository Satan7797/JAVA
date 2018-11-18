#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>

int main()
{
	const int size=1;
	char *name="OS";

	int fd;
	char *ptr;
	fd=shm_open(name,O_CREAT | O_RDWR,0665);
	ptr = (char*)mmap(0,size,PROT_WRITE,MAP_SHARED,fd,0);
	printf("%s",(char *)ptr);
	shm_unlink(name);
	return 0;
}
