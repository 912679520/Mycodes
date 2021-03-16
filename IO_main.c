#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include<sys/select.h>
#include<sys/time.h>

//select的使用
int main()
{
    int fd = 0;//stdin键盘输入
    while(1)
    {
        fd_set fdset;//声明文件描述符集合
        FD_ZERO(&fdset);//清空
        FD_SET(fd, &fdset);//在文件描述符集合中增加一个新的文件描述符
        
        struct timeval tv = {5, 0};

        int n = select(fd+1, &fdset,NULL,NULL,&tv);
        if (n == -1) break;
        else if(n == 0) 
        {
            printf("time out\n");
        }
        else
        {
            char buff[128] = {0};
            if( FD_ISSET(fd,&fdset))
            {
                read(fd,buff,127);
                printf("buff = %s\n",buff);
            }

        }
}
}

