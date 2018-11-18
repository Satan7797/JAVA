#include<sys/sysinfo.h>
#include<sys/utsname.h>
#include<stdio.h>

int main()
{
	const double megabyte=1024*1024;
	struct sysinfo info;
	struct utsname us;
	sysinfo(&info);
	int n=uname(&us);

	printf("Free memory %5.1f",info.freeram/megabyte);
	printf("\nTotal ram: %5.1f",info.totalram/megabyte);
	printf("\nProcess: %d",info.procs);
	printf("\nKernel version: %s",us.version);
	printf("\nCPU type: %s",us.sysname);
	printf("\nModel: %s",us.release);
	return 0;
}
