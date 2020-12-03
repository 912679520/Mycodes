#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include<dirent.h>

int main()
{
    char dir_buff[512] = {0};
    getcwd(dir_buff,512);//获取当前目录

    DIR *p = opendir(dir_buff);//打开目录流
    if(p == NULL)
    {
        perror("opendir err");
        exit(1);
    }
    
    struct dirent *s = NULL;
    while((s = readdir(p)) != NULL)//读取目录流中的信息，每条信息(struct dirent)对应一个文件
    {
        if(strncmp(s->d_name,".",1)!= 0)
             printf("%s   ",s->d_name);//打印文件名
    }
    printf("\n");

    closedir(p);//关闭目录流
    exit(0);
}
