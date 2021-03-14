#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define IPSTR "192.168.65.131"
#define PORT 80
#define PATH "/home/lx/Desktop/Study/mycode/Http/html"

int creat_socket()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1) return -1;

    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    saddr.sin_addr.s_addr = inet_addr(IPSTR);

    int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(res == -1) return -1;

    res = listen(sockfd,5);

    if( res ==-1) return -1;

    return sockfd;
}

int accept_http(int sockfd)
{
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    int c = accept(sockfd,(struct sockaddr*)&caddr,&len);

    if(c == -1) return -1;

    return c;
}

char* getfilename(char buff[])
{
    char* s = strtok(buff," ");
    if( s == NULL) return NULL;

    printf("请求方法：%s\n",s);
    char *name = strtok(NULL," ");
    if(name == NULL) return NULL;

    printf("请求的资源名字：%s\n",name);
    
    return name;
}

void set_head(char buff[],int size)
{
    //头部信息
    strcpy(buff,"HTTP/1.1 200 OK\r\n");
    strcat(buff,"Server:myhttp\r\n");
    sprintf(buff+strlen(buff),"Content-Length: %d\r\n",size);

    strcat(buff,"\r\n");
}

void send_html(int c, int fd)
{
    char data[512] = {0};
    int n = 0;
    while( ( n = read(fd,data,512)) > 0)
    {
        send(c, data, n, 0);
    }
}

int recv_http(int c)
{
    char buff[1024] = {0};
    int n = recv(c,buff,1023,0);
    if(n <= 0) return -1;

   // printf("read http : \n%s\n",buff);

    char *name = getfilename(buff);
    if( name == NULL) return -1;
    
    char filepath[256] = {PATH};
    if(strcmp(name,"/" ) == 0)
    {
        strcat(filepath,"/index.html");
    }
    else
    {
        strcat(filepath,name);
    }

    int fd = open(filepath,O_RDONLY);
    if( fd == -1)
    {
        send(c,"404",3,0);
        return -1;
    }

    int size = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);

    char http_head[256] = {0};
    set_head(http_head,size);
    
    send(c,http_head,strlen(http_head),0);
    printf("send http:\n%s\n",http_head);
    
    send_html(c, fd);
    close(fd);
    close(c);

    return 0;
}

int send_http(int c)
{
    send(c,"hello",5,0);
    return 0;
}

int main()
{
    int sockfd  = creat_socket();
    assert( sockfd != -1);

    while(1)
    {
        int c = accept_http(sockfd);

        if(c < 0) continue;

        int res = recv_http(c);//接收http报文
        if(res == -1)
        {
            close(c);
            continue;
        }

    }

    return 0;
}
