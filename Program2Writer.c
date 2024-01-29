#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int fd;
	char buf[1024];
	char *myfifo = "/tmp/myfifo.txt";
	
	mkfifo(myfifo, 0666);
	
	printf("Run reader process to read myfifo file\n");
	
	fd = open(myfifo, O_WRONLY);
	write(fd, "Hi", sizeof("Hi"));
	
	close(fd);
	unlink(myfifo);
	
	return 0;
}
