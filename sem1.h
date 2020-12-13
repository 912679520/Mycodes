#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<sys/sem.h>

#define SEM_A  0
#define SEM_B  1

union semun
{
    int val;
};

void sem_init();

void sem_p(int num);

void sem_v(int num);

void sem_destroy();
