#include<stdio.h>
#include<stdlib.h>

int mutex=1, full=0, empty=3, x=0, y=0;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer produces item %d\n", x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	y++;
	printf("Consumer consumes item %d\n", y);
	++mutex;
}

int main()
{
	int n,i;
	
	printf("\n1. Press 1 for producer\n2. Press 2 for consumer\n3. Press 3 for exit.\n");
	
	while(1)
	{	
		printf("\nEnter your choice:  ");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				if((mutex==1) && (empty!=0))
					producer();
				else
					printf("Buffer is full!\n");
				break;
				
			case 2:
				if((mutex==1) && (full!=0))
					consumer();
				else
					printf("Buffer is empty!\n");
				break;
				
			case 3:
				exit(0);
		}
	}
}
