#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include<sys/shm.h>
#include"sem.h"

int main()
{
    int shmid = shmget((key_t)1234,256,IPC_CREAT|0600);
    assert(shmid != -1);

    char *p = (char*)shmat(shmid,NULL,0);
    assert( p != (char*)-1);
   
    sem_init(); 
    while(1)
    {
        //p(b)
        sem_p(SEM_B);

        if(strncmp(p,"end",3) == 0) break;

        printf("p = %s\n",p);

        //p(a)
        sem_v(SEM_A);
    }
    
    shmdt(p);
    shmctl(shmid,IPC_RMID,NULL);

    sem_destroy();
}



