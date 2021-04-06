#include <stdio.h>
#include <signal.h>

void handler();

int main(){
	signal(SIGALRM, (void (*)()) handler);
	printf("\n Várakozni kezdek ... \n");
	pause( );
	
	printf(" Kibillentem a várakozásból, exitálok. \n");
	exit(0);
}

void handler(){
	return;
}