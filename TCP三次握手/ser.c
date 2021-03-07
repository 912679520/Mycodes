#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    assert(sockfd != -1);

    struct sockaddr_in saddr,caddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;     //地址族
    saddr.sin_port = htons(6000);   //端口号
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //bind将sockfd与一个socket地址绑定，成功返回0，失败-1
    int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    assert(res != -1);

    //5:backlog linux系统下指未完成的握手队列，Unix下指未完成+已完成
    //创建一个监听队列接受一个链接
    listen(sockfd,5);

    while(1)
    {
        int len = sizeof(caddr);
        //从listen中接受一个链接，成功返回一个新连接
        int c = accept(sockfd,(struct sockaddr*)&caddr,&len);
        if(c < 0)
        {
            continue;
        }
        printf("accept c = %d\n",c);

        while(1)
        {
            char buff[128] = {0};
            //num为实际读到的字节数， num = -1, 错误 ， num = 0 ，对方关闭
            //读取sockfd的数据，buff和127参数分别指缓冲区的位置和大小
            int num = recv(c,buff,127,0);
            if(num == 0)
            {
                break;
            }
        }
        close(c);
    }

}