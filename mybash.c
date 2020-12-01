
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<wait.h>

int main()
{
	while(1)
	{
		printf("[stu@localhost ~]$");
		fflush(stdout);
		char buff[128] = {0};
		fgets(buff,128,stdin);
		buff[strlen(buff) - 1] = '\0';
		
		char *myargv[10] = {0};
		int i = 0;
		char *s = strtok(buff, " ");
		while( s != NULL)
		{
			myargv[i++] = s;
			s = strtok(NULL, " ");
		}
		
		if(myargv[0] == NULL) continue;
		if(strcmp(myargv[0],"exit") == 0)
			break;
		
        else if (strcmp(myargv[0], "cd") == 0)
        {
            if(myargv[1] != NULL)
            {
                chdir(myargv[1]);
                continue;
            }
        }

		pid_t pid = fork();
		if(pid == -1) continue;

		if(pid == 0)
		{
			//execlp(myargv,buff,(char*)0);
			execvp(myargv[0], myargv);
			perror("exec err");
			exit(0);
		}
		wait(NULL);
	}

	exit(0);
}
