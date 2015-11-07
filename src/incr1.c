#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

void incr1(int* count,int loop,const char* c)
{
	int i;
	sem_t *mutex;
	mutex = sem_open(c,O_CREAT|O_EXCL,S_IRUSR,1);
	sem_unlink(c);
	setbuf(stdout,NULL);

	if(fork()==0)
	{
		for(i=0;i<loop;i++)
		{
			sem_wait(mutex);
			printf("child: %d\n",(*count)++);
			sem_post(mutex);
		}
		exit(0);
	}

	for(i=0;i<loop;i++)
	{
		sem_wait(mutex);
		printf("parent: %d\n",(*count)++);
		sem_post(mutex);
	}
	exit(0);
}
