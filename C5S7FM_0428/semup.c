#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 123456L  //semget kulcs

	int semid,nsems,rtn;
	unsigned nsops;
	int semflg;
	struct sembuf sembuf, *sop;


int main()
{
	nsems = 1;	//semaphore
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror(" semget hiba"); exit(0);}
	else printf("\n semid: %d ",semid);
	printf ("\n");

	nsops = 1;		//egy operacio
	sembuf.sem_num = 0;	//0-ik semaphore
	sembuf.sem_op = 1;	//inkrementaciot kereses
	sembuf.sem_flg = 0666;	//flag beallitas
	sop = &sembuf;		//semop argumentum kérés
	rtn = semop(semid, sop, nsops);
	printf("\n up rtn: %d ",rtn);
	printf("\n");

}