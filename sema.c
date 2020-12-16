#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include<sys/shm.h>
#include"sem.h"

int main()
{
    int shmid = shmget((key_t)1234,256,IPC_CREAT|0600);//创建 获取共享内存
    assert( shmid != -1);

    char *s = (char*)shmat(shmid,NULL,0);
    assert( s != (char*)-1);
    
    sem_init();
    while(1)
    {
        printf("input:\n");
        char buff[128] = {0};
        fgets(buff,128,stdin);
        //p(a)
        sem_p(SEM_A);
        strcpy(s,buff);
        //v(b)
        sem_v(SEM_B);
        if(strncmp(buff,"end",3)==0) break;
    }

    shmdt(s);
}

