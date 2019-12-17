#include<stdlib.h>
#include<stdio.h>

struct process
{
    int bt,tt,wt;
};

int main()
{
    struct process p[20];
    int i,n,tq,time=0,rembt[20],totwt=0,tottt=0,flag=0;
    float avgwt,avgtt;
    printf("Enter the number of processes - ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d - ",i+1);
        scanf("%d",&p[i].bt);
        rembt[i]=p[i].bt;
    }
    printf("\n");
    printf("Enter the time quantum - ");
    scanf("%d",&tq);
    while(flag==0)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            if(rembt[i]>0)
            {
                flag=0;
                if(rembt[i]>tq)
                {
                    time+=tq;
                    rembt[i]-=tq;
                }
                else
                {
                    time=time+rembt[i];
                    rembt[i]=0;
                    p[i].tt=time;
                    p[i].wt=p[i].tt-p[i].bt;
                }
            }
        }
    }
    printf("\nROUND ROBIN\n");
    printf("Process\tBT\tTT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t%d\t%d\t%d",i+1,p[i].bt,p[i].tt,p[i].wt);
        tottt+=p[i].tt;
        totwt+=p[i].wt;
    }
    printf("\n\n");
    avgwt=(float)totwt/n;
    avgtt=(float)tottt/n;
    printf("Total waiting time = %d ms\n",totwt);
    printf("Average waiting time = %.2f ms\n",avgwt);
    printf("Total turnaround time = %d ms\n",tottt);
    printf("Average turnaround time = %.2f ms\n",avgtt);
    return 0;
}
