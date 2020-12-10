
#include"sem.h"

int semid = -1;

void sem_init()
{
    semid = semget((key_t)1234,1,IPC_CREAT|IPC_EXCL|0600);//全新创建
    if(semid == -1)//全新创建失败，说明被别人创建了，就直接获取
    {
        semid =semget((key_t)1234,1,0600);
        if(semid == -1)
        {
            perror("creat sem err");
            return;
        }
    }
    else
    {
        union semun a;
        a.val = 1;
        if(semctl(semid, 0,SETVAL,a) == -1)
        {
            perror("semctl err");
        }
    }
}

void sem_p()
{
    struct sembuf buf;
    buf.sem_num=0;
    buf.sem_op=-1;
    buf.sem_flg=SEM_UNDO;

    if(semop(semid,&buf,1) == -1)
    {
        perror("semop p err");
    }
    
}

void sem_v()
{
    struct sembuf buf;
    buf.sem_num=0;
    buf.sem_op=-1;
    buf.sem_flg=SEM_UNDO;

    if(semop(semid,&buf,1) == -1)
    {
        perror("semop p err");
    }
    
}

void sem_destroy()
{
    if(semctl(semid,0,IPC_RMID) == -1)
    {
        perror("destroy err");
    }
}


