#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include<fcntl.h>
#include<errno.h>
#include<wait.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
    int sockfd =socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd != -1);

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(6000);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    assert( res != -1);
    
    while(1)
    {
        printf("input:\n");
        char buff[128] = {0};
        fgets(buff,128,stdin);

        if(strncmp(buff,"end",3) == 0)
        {
            break;
        }
        send(sockfd,buff,strlen(buff),0);

        memset(buff,0, 128);
        recv("buff=%s\n",buff,127,0);
        printf("buff= %s\n",buff);
    }
        close(sockfd);

}
