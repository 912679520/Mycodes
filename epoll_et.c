#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/epoll.h>
#include<fcntl.h>

#define MAXFD 100

void setnonblock(int fd)
{
    int oldfl = fcntl(fd, F_GETFL);
    int newfl = oldfl | O_NONBLOCK;
    if(fcntl(fd,F_SETFL,newfl) == -1)
    {
        perror("err");
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

int do_accept(int sockfd)
{
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    int c = accept(sockfd,(struct sockaddr*)&caddr,&len);
    printf("accept c = %d\n",c);
    return c;
}

void epoll_del(int epfd, int fd)
{
    if(epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL) == -1)
    {
        perror("epoll ctl del error");
    }
}

void do_work(int epfd, int c)
{
    while (1)
    {
        char buff[128] = {0};
        int res = recv(c, buff,1,0);
        if(res == -1)
        {
            break;
        }
        if(res == 0)
        {
            epoll_del(epfd,c);
            close(c);
            printf("one client over\n");
            break;
        }
        else
        {
            printf("read(%d):%s\n",c,buff);
            send(c,"ok",2,0);
        }
    }
    
 
}

void epoll_add(int epfd, int fd)
{
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = fd;

    setnonblock(fd);//设置非阻塞

    if(epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev) == -1)
    {
        perror("epoll_ctl err");
    }
}



int main()
{
    int sockfd = create_socket();
    assert(sockfd != -1);

    int epfd = epoll_create(MAXFD);
    assert(epfd != -1);

    epoll_add(epfd,sockfd);

    struct epoll_event events[MAXFD];
    while(1)
    {
        int n = epoll_wait(epfd,events,MAXFD,5000);
        if( n < 0)
        {
            perror("epoll error");
            continue;
        }
        else if(n == 0)
        {
            printf("time out\n");
        }
        else
        {
            int i = 0;
            for(; i < n; i++)
            {
                int fd = events[i].data.fd;
                if( events[i].events & EPOLLIN)
                {
                    if(fd == sockfd)
                    {
                        int c = do_accept(sockfd);
                        if(c >= 0)
                        {
                            epoll_add(epfd,c);
                        }
                    }
                    else
                    {
                        do_work(epfd,fd);
                    }
                    
                }
            }
        }
        
    }
}