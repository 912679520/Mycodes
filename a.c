#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include"sem.h"

int main()
{
    sem_init();
    for(int i = 0; i < 5; i++)
    {
        sem_p;
        printf("a");
        fflush(stdout);
        int n =rand() % 3;
        sleep(n);
        printf("a");
        fflush(stdout);
        sem_v();

        n = rand() % 3;
        sleep(n);
    }

}
