#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
	int pid,i;
	for(i=0;i<5;i++)
	{
		pid=fork();
		if(pid==0)
		{
			printf("PID of process %d is %d",(i+1),getpid());
			exit(0);
		}
		wait(NULL);
	}
}
