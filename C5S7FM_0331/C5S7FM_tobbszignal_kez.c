#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSignals(int sig);

int main()
{
	if (signal(SIGINT, handleSignals) == SIG_ERR){
		printf("\ncan't catch SIGINT\n");
	}

	while(1){
		sleep(1);
	}
	return 0;
}

void handleSignals(int sig){
	if (sig == SIGINT){
		printf("Received SIGINT\n");
	}

	if (sig = SIGQUIT){
		printf("Received SIGNQUIT\n");
		return sig;
	}
}