#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<sys/sem.h>

union semun
{
    int val;
};

void sem_init();//初始化信号量的值为1

void sem_p();

void sem_v();

void sem_destroy();//销毁信号量
