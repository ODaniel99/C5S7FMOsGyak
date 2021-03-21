#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid, pid1, pid2;

	pid = fork();
	if (pid == 0){
		sleep(5);
		printf("child1 -> pid %d and ppid = %d\n", getpid(), getppid());
	}
	else{
		pid1 = fork();
		if (pid1 == 0){
			sleep(3);
			printf("child2 -> pid %d and ppid = %d\n", getpid(), getppid());
		}
		else{
			pid2 = fork();
			if (pid2 == 0){
				printf("child3 -> pid %d and ppid = %d\n", getpid(), getppid());
			}
			else{
				sleep(5);
				printf("parent -> pid = %d\n", getpid());
			}
		}
	}

	return 0;
}