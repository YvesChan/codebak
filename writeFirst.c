#include <sys/types.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int semid;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
}arg;

struct sembuf wc, mdb;

void reader(int i){

    printf("no.%d reader come\n", i);
	printf("r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
	mdb.sem_op = -2;
    semop(semid, &mdb, 1);       //reader get db
    printf("r %d catch db\n", i);
    printf("r %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));

    printf("%d reading db\n", i);
    sleep(1);
    
	printf("after reading db, (%d) gone\n", i);
	mdb.sem_op = 2;
    semop(semid, &mdb, 1);
    printf("%d release db\n", i);
    
    exit(0);
}

void writer(int i){
    wc.sem_op = 1;
    semop(semid, &wc, 1);            //add writer counter
    
    printf("before acquire db, current wc: %d\n", semctl(semid, 0, GETVAL));
    if(semctl(semid, 0, GETVAL) == 1) mdb.sem_op = -2;     //priority control
    else mdb.sem_op = -1;
	printf("w %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
    semop(semid, &mdb, 1);                //catch db
    printf("w %d writer catch db\n", i);
    printf("w %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
    
    printf("w %d writing db\n", i);
    sleep(3);
    
    wc.sem_op = -1;
    semop(semid, &wc, 1);          //reduce writer counter
    
    printf("before release db, current wc: %d\n", semctl(semid, 0, GETVAL));
    if(semctl(semid, 0, GETVAL) == 0) mdb.sem_op = 2;
    else mdb.sem_op = 1;
    semop(semid, &mdb, 1);              //release db
    printf("writer release db\n");
    printf("w %d test db mutex: %d\n", i, semctl(semid, 1, GETVAL));
    

    exit(0);
}

int main()
{
    semid = semget(150, 2, IPC_CREAT | 0660);
	arg.val = 0;
    semctl(semid, 0, SETVAL, arg);   //writer counter
	arg.val = 2;
    semctl(semid, 1, SETVAL, arg);   //db mutex

	wc.sem_num = 0;   //operate wc
	mdb.sem_num = 1;   //operate db


    pid_t pid;
    int j;
    for(j = 0; j < 2; j ++)
        if((pid = fork()) == 0){
		    //sleep(2);
		    printf("writer %d fork success\n", (int)getpid());
            writer((int)getpid());
	    }
    for(j = 0; j < 3; j ++)
	    if((pid = fork()) == 0){
	        sleep(2);
		    printf("reader %d fork success\n", (int)getpid());
            reader((int)getpid());
	    }

    exit(0);
}
