#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<fcntl.h>

void down_file(int c, char* filename, char* str)
{
    if(filename == NULL)
    {
        printf("请输入文件名：\n");
        return;
    }

    //ok#345 / err#文件不存在。。
    send(c,str,strlen(str),0); // get a.c
    char buff_file[128] = {0}; //文件信息
    int num = recv(c, buff_file, 127, 0); // ok#345
    if(num <= 0) // 服务器异常关闭
    {
        printf("ser close\n");
        close(c);
        exit(0);
    }

    if(strncmp(buff_file,"ok#",3) != 0) // 收到失败报文
    {
        printf("%s\n",buff_file+4);
        return;
    }

    int filesize = 0;
    sscanf(buff_file + 3, "%d",&filesize);

    printf("下载的文件大小为:%d\n",filesize);

    int fd = open(filename, O_WRONLY | O_CREAT,0600);
    if(fd == -1)
    {
        send(c, "err",3,0);
        return;
    }

    send(c, "ok#",3,0);

    int curr_size = 0;

    int data[1024] = {0};
    while(1)
    {
        int num = recv(c, data, 1024, 0);
        if(num <= 0)
        {
            printf("ser close --send\n");
            close(c);
            close(fd);
            exit(0);
        }
        write(fd, data,num);
        curr_size += num;
        printf("down:%.2f%%\r",curr_size * 100.0 / filesize);
        fflush(stdout);
        if(curr_size >= filesize)
        {
            break;
        }
    }
    printf("\n");
    close(fd);
}

int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    assert(res != -1);

    while(1)
    {
        printf("connect ser>> ");
        fflush(stdout);
        char buff[128] = {0};

        fgets(buff,128,stdin); //"ls\n"
        buff[strlen(buff)-1] = 0;
        
        char tmpbuff[128] = {0};
        strcpy(tmpbuff,buff);

        char * myargv[10];
        int i = 0;
        char *s = strtok(tmpbuff," ");
        while(s != NULL)
        {
            myargv[i] = s;
            i++;
            s = strtok(NULL," ");
        }
        if(myargv[0] == NULL)
        {
            continue;
        }
        if(strcmp(myargv[0],"exit") == 0)//退出
        {
            break;
        }
        else if(strcmp(myargv[0],"get") == 0)
        {
            //下载
            down_file(sockfd, myargv[1], buff);     
        }
        else if(strcmp(myargv[0],"post") == 0)
        {

        }
        else
        {
            send(sockfd,buff,strlen(buff),0); // ls  rm a.c ...
            char recv_buff[1024] = {0};
            int n = recv(sockfd,recv_buff,1023,0);
            if(n <= 0)
            {
                printf("ser close\n");
                break;
            }
            printf("%s\n",recv_buff + 3);
        }

    }
    close(sockfd);
}