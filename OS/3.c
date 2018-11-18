#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#define BUFFERSIZE 1024
int main(int argc, char *argv[])
{
  int fd1,fd2;
  char buf[BUFFERSIZE];
  int n;
  if(argc!=3)
  { 
    fprintf(stderr,"\n Invalid Arguments");
    fprintf(stderr,"\n usage : a.out file1 file2");
  }
  if((fd1=open(argv[1],O_RDONLY))==-1)
  {
    perror(argv[1]);
    return 1;
  }

  if((fd2=open(argv[2],O_WRONLY))==-1)
  {
    perror(argv[2]);
    return 1;
  }

  while((n=read(fd1,buf,BUFFERSIZE))>0)
  {
    if((write(fd2,buf,n))!=n)
    {
      perror("write error");
      return 1;
    }
  }

  close(fd1);
  close(fd2);
  return 0;
}		
