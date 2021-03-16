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
#include<sys/socket.h>
#include<sys/time.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>

#define MAXFD 10

int create_socket()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1) return -1;

    struct sockaddr_in saddr,caddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(sockfd == -1) return -1;

    res =  listen(sockfd,5);
    if( res == -1) return -1;

    return sockfd;
}

void fds_init(int fds[])
{
    int i = 0;
    for( ; i < MAXFD; i++)
    {
        fds[i] = -1;
    }
}

void fds_add(int fd, int fds[])
{
    int i = 0;
    for(; i < MAXFD;i++)
    {
        if(fds[i] == -1)
        {
            fds[i] = fd;
            break;
        }
    }
}

void fds_del(int fd, int fds[])
{
    int i = 0;
    for(; i < MAXFD; i++)
    {
        if( fds[i] == fd)
        {
            fds[i] = -1;
            break;
        }
    }
}

int accept_sock(int sockfd)
{
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    int c = accept(sockfd,(struct sockaddr*)&caddr,&len);
    return c;
}

int main()
{
    int sockfd = create_socket();
    assert(sockfd != -1);

    int fds[MAXFD];
    
    fds_init(fds);
    fds_add(sockfd, fds);//将监听套接字添加到数组中

    fd_set fdset;
    
    while(1)
    {
        FD_ZERO(&fdset);
        int maxfd = -1;
        
        int i = 0;
        for(; i < MAXFD; i++)//将数组中有效的描述符添加到集合fdset中
        {
            if(fds[i] == -1)//没存放描述符
            {
                continue;
            }

            FD_SET(fds[i],&fdset);
            if(fds[i] > maxfd)//找最大值
            {
                maxfd = fds[i];
            }
        }
        struct timeval tv = {5, 0};

        int n = select(maxfd + 1,&fdset,NULL,NULL,&tv); // n代表有多少个描述符有数据就绪
        if(n == -1) break;
        else if (n == 0)
        {
            printf("time out\n");
            continue;
        }
        else
        {
            int i = 0;
            for(; i < MAXFD; i++)
            {
                if( fds[i] == -1)
                {
                    continue;
                }
                if(FD_ISSET(fds[i],&fdset))//测试fd是否被设置
                {
                    //sockfd->accept
                    //c->recv
                    if(fds[i] == sockfd)
                    {
                        int c = accept_sock(sockfd);
                        if(c != -1)
                        {
                            fds_add(c,fds);
                            printf("accept c = %d\n",c);
                        }
                    }
                    else
                    {
                        char buff[128] = {0};
                        int num = recv(fds[i],buff,127,0);
                        if(num <= 0)
                        {
                            close(fds[i]);
                            fds_del(fds[i],fds);
                            printf("one client over\n");
                         }
                         printf("recv:%s\n",buff);
                         send(fds[i],"OK",2,0);
                    }
                }
            }
        }
    }
}
