#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void incr_anonymous(int loop, const char* sem_name) {
	int i;
	int *ptr;
	sem_t *mutex;

	/*MAP_ANON->anonymous, not need fd(descriptor of file)*/

	ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON,
			-1, 0);
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
