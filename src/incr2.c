#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void incr2(int loop, const char* pathname, const char* sem_name) {
	int fd;/*descriptor of file*/
	int i;
	int zero = 0;
	int *ptr;
	sem_t *mutex;
	fd = open(pathname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, &zero, sizeof(int));
	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	mutex = sem_open(sem_name, O_CREAT | O_EXCL, S_IRUSR, 1);
	sem_unlink(sem_name);
	setbuf(stdout, NULL);

	if (fork() == 0) {
		for (i = 0; i < loop; i++) {
			sem_wait(mutex);
			printf("child: %d\n", (*ptr)++);
			sem_post(mutex);
		}
		exit(0);
	}

	for (i = 0; i < loop; i++) {
		sem_wait(mutex);
		printf("parent: %d\n", (*ptr)++);
		sem_post(mutex);
	}
	exit(0);
}
