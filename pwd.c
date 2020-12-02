#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>

int main()
{
    char dir_buff[512] = {0};
    getcwd(dir_buff,512);
    printf("%s\n",dir_buff);
    exit(0);
}
