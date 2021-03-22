#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<poll.h>

#define MAXFD 100

int create_socket();

void fds_init(struct pollfd fds[])
{
    int i = 0;
    for(; i < MAXFD; i++)
    {
        fds[i].fd = -1;
        fds[i].events = 0;//读事件
        fds[i].revents = 0;
    }
}

void fds_add(struct pollfd fds[],int fd)
{
    if (fd < 0 || fd >= MAXFD)
    {
        printf("fd error");
        return;
    }

    fds[fd].fd = fd;
    fds[fd].events = POLLIN;//设置读事件
    fds[fd].revents = 0;
}

void fds_del(struct pollfd fds[], int fd)
{
    if(fd < 0 || fd >= MAXFD)
    {
        printf("fd error");
        return;
    }
    fds[fd].fd = -1;
    fds[fd].events = 0;
    fds[fd].revents = 0;
}

int do_accept(int sockfd)
{
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    int c = accept(sockfd,(struct sockaddr*)&caddr,&len);
    printf("accept c = %d\n",c);
    return c;
}

void do_work(struct pollfd fds[], int sockfd)
{
    int i = 0;
    for(; i < MAXFD; i++)
    {
        if(fds[i].fd == -1)
        {
            continue;
        }

        if( fds[i].revents & POLLIN)
        {
            if(fds[i].fd == sockfd)
            {
                int c = do_accept(sockfd);
                if( c >= 0)
                {
                    fds_add(fds,c);
                }
            }
            else
            {
                char buff[128] = {0};
                int n = recv(fds[i].fd,buff,127,0);
                if(n <= 0)
                {
                    close(fds[i].fd);
                    fds_del(fds,fds[i].fd);
                    printf("one clinet over\n");
                }
                else
                {
                    printf("recv(%d):%s\n",fds[i].fd,buff);
                    send(fds[i].fd,"ok",2,0);
                }
                
            }
            
        }
    }
}

int main()
{
    int sockfd = create_socket();
    assert(sockfd != -1);

    struct pollfd fds[MAXFD];
    fds_init(fds);
    fds_add(fds,sockfd);

    while(1)
    {
        int n = poll(fds, MAXFD, 5000);
        if(n < 0)
        {
            perror("poll error");
            continue;
        }
        else if(n == 0)
        {
            printf("time out\n");
            continue;
        }
        else
        {
            do_work(fds,sockfd);
        }
        
    }
}

int create_socket()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        return -1;
    }

    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(res == -1) return -1;

    res = listen(sockfd,5);
    if(res == -1) return -1;

    return sockfd;
}