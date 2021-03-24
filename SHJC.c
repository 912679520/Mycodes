#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<sys/stat.h>

/*
守护进程编程流程：
1、fork，退出父进程
2、setsid（） 创建新会话
3、fork，退出父进程
4、chdir（）改变工作路径
5、umask（0） 掩码
6、close（）
*/

int main()
{
    pid_t pid = fork(); //1
    if(pid != 0) exit(0);//结束父进程

    setsid();//2

    pid = fork();//3
    if(pid != 0) exit(0);

    chdir("/");//4
    umask(0);//5

    int maxfd = getdtablesize();//6
    int i = 0;
    for(; i < maxfd; i++)
    {
        close(i);
    }

    //测试
    while(1)
    {
        FILE* fp = fopen("/tmp/mytestd.log","a");
        if(fp == NULL) break;
        //写入当前时间
        time_t tv;
        time(&tv);

        fprintf(fp,"thim is:%s",asctime(localtime(&tv)));
        fclose(fp);
        sleep(5);   
    }
}