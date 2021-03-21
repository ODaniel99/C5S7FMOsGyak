#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void ChildProcess();
void ParentProcess();

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		ChildProcess();
	else
		ParentProcess();

	return 0;
}

void ChildProcess(){
	int i;

	for (i=1; i<=20; i++){
		printf("This is from the child, value = %d\n", i);
	}
	printf("End of the child process\n");
}

void ParentProcess(){
	int i;

	for (i=1; i<=20; i++){
		printf("This is from the parent, value = %d\n", i);
	}
	printf("End of the parent process\n");
}