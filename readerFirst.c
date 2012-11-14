#include <sys/types.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int semid, rc = 0;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
}arg;

struct sembuf mrc, mdb;

void reader(int i){  

	mrc.sem_op = 1;   //add rc
    semop(semid, &mrc, 1);

    printf("no.%d reader come, current rc: %d \n", i, semctl(semid, 0, GETVAL));
    if(semctl(semid, 0, GETVAL) == 1){
		printf("r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
		mdb.sem_op = -1;
        semop(semid, &mdb, 1);       //reader get db
        printf("r %d catch db\n", i);
        printf("r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
    }

    printf("%d reading db\n", i);
    sleep(4);

    mrc.sem_op = -1;
    semop(semid, &mrc, 1);    //minus rc
	printf("after reading db, (%d) gone, current rc: %d\n", i, semctl(semid, 0, GETVAL));
    if(semctl(semid, 0, GETVAL) == 0){
        mdb.sem_op = 1;
		printf("before release, r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
        if(semop(semid, &mdb, 1) == -1)    //release db mutex
			printf("semop error!\n");
        else printf("%d release db\n", i);
		printf("after release, r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
    }

	//printf("no.%d reader go, current rc:%d \n", i, semctl(semid, 0, GETVAL));

    exit(0);
}

void writer(int i){
    mdb.sem_op = -1;

	printf("w test db mutex: %d\n", semctl(semid, 1, GETVAL));
    semop(semid, &mdb, 1);
    printf("writer catch db\n");
    printf("w test db mutex: %d\n", semctl(semid, 1, GETVAL));
    sleep(2);
    mdb.sem_op = 1;
    semop(semid, &mdb, 1);
    printf("writer release db\n");
    printf("db mutex: %d\n", semctl(semid, 1, GETVAL));

    exit(0);
}

int main()
{
    semid = semget(150, 2, IPC_CREAT | 0660);
	arg.val = 0;
    semctl(semid, 0, SETVAL, arg);   //reader counter
	arg.val = 1;
    semctl(semid, 1, SETVAL, arg);   //db mutex

	mrc.sem_num = 0;   //operate rc
	mdb.sem_num = 1;   //operate db

	//mrc.sem_flg = SEM_UNDO;
	//mdb.sem_flg = SEM_UNDO;

    pid_t pid;
    if((pid = fork()) == 0){   //child
		sleep(2);
		printf("writer %d fork success\n", (int)getpid());
        writer((int)getpid());
	}
    int j;
    for(j = 0; j < 3; j ++)
	    if((pid = fork()) == 0){
		    printf("reader %d fork success\n", (int)getpid());
            reader((int)getpid());
	    }

    exit(0);
}
