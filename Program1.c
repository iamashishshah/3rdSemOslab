#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t parent = getpid();
	pid_t pid = fork();
	
	if(pid == -1)
		printf("Fork failed\n");
		
	else if(pid>0)
	{	
		int status;
		printf("Parent with id %d\n is waiting for child to complete\n", getpid());
		waitpid(pid, &status, 0);
	}
	
	else
	{
		printf("Child process with ID %d", (int)pid);
		printf("Parent process ID %d", getppid());
		execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", NULL);
		_exit(EXIT_FAILURE);
	}
}
