
#include"sem.h"

int semid = -1;

void sem_init()
{
    semid = semget((key_t)1234,2,IPC_CREAT|IPC_EXCL|0600);
    if(semid == -1)
    {
        semid = semget((key_t)1234,2,0600);
        if(semid == -1)
        {
            perror("semget err");
            return;
        }
        else
        {
            int arr[2] = {1,0};
            union semun a;
            for(int i = 0; i < 2; i++)
            {
                a.val = arr[i];
                if(semctl(semid, i,SETVAL, a) == -1)
                {
                    perror("semctl setval err");
                }
            }
        }
    }

}

void sem_p(int num)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    if(semop(semid,&buf,1) == -1)
    {
        perror("semop err p");
        return;
    }
}

void sem_v(int num)
{
    struct sembuf buf;
    buf.sem_num = num;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;

    if(semop(semid,&buf,1) == -1)
    {
        perror("semop err v");
        return;
    }
}

void sem_destroy()
{
    if (semctl(semid,0,IPC_RMID) == -1)
    {
        perror("semctl error");
        return;
    }
}

