#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

#define MAX_BUF 1024

int main()
{
	int fd;
	char buf[MAX_BUF];
	char *myfifo = "/tmp/myfifo.txt";
	
	fd = open(myfifo, O_RDONLY);
	read(fd, buf, MAX_BUF);
	
	printf("Writer : %s\n", buf);
	
	close(fd);
	
	return 0;
}
