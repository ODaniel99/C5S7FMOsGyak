#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 654321L

struct msgbuf1 {
	long mtype;
	char mtext[512];
} sndbuf, *msgp;



int main()
{
	int id;
	key_t key;
	int msgflag;
	int rtn, msgsize;
	int msgid;
	int msgflg;

	key = MSGKEY;
	msgflag = 00666 | IPC_CREAT;
	msgid = msgget( key, msgflg);
 	if ( id == -1) {
 	    perror("\n Hiba az msgget hivasnal\n");
 	    exit(-1);
 	}

	printf("\n Az msgid %d, %x : ", msgid,msgid);

	msgp = &sndbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"Egyik uzenet");
	msgsize = strlen(msgp->mtext) + 1;

	rtn = msgsnd(id,(struct msgbuf *) msgp, msgsize, msgflag);
	printf("\n Az 1. msgsnd visszaadott %d-t", rtn);
	printf("\n A kikuldott uzenet: %s", msgp->mtext);

	strcpy(msgp->mtext,"Masik uzenet");
	msgsize = strlen(msgp->mtext) + 1;
	rtn = msgsnd(id,(struct msgbuf *) msgp, msgsize, msgflag);
	printf("\n A 2.msgsnd visszaadott %d-t", rtn);
	printf("\n Az uzenet: %s", msgp->mtext);
	printf("\n");

	exit (0);
}
