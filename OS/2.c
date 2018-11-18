#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
     printf("ERROR ");
     return 1;
    }
	
	struct stat filestat;
    
    if(stat (argv[1],&filestat)<0){
	printf("\nFile not found\n");
    	return 1;
    }
    printf("information of %s file:",argv[1]);
    printf("\n\n");
    printf("\n file size %ldbytes",filestat.st_size);
    printf("file permission \n\n");
    printf((S_ISDIR(filestat.st_mode))?"d":"_");
    printf((filestat.st_mode & S_IRUSR)?"r":"_");
    printf((filestat.st_mode & S_IWUSR)?"w":"_");
    printf((filestat.st_mode & S_IXUSR)?"x":"_");
    printf((filestat.st_mode & S_IRGRP)?"r":"_");
    printf((filestat.st_mode & S_IWGRP)?"w":"_");
    printf((filestat.st_mode & S_IXGRP)?"x":"_");
    printf((filestat.st_mode & S_IROTH)?"r":"_");
    printf((filestat.st_mode & S_IWOTH)?"w":"_");
    printf((filestat.st_mode & S_IXOTH)?"x":"_");
    printf("\n\n");
    printf("\nFile last access time is %ld", filestat.st_atime/3600);
    printf("\nFile last access modification is %ld", filestat.st_mtime/3600);
    
    return 0;
}
