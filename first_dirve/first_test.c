#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	int val=1;
	fd=open("/dev/fist_dev",O_RDWR);
	if(fd<0){
		printf("open file erro");
	}
	
}
