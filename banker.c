#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,p,r,alloc[10][10],max[10][10],need[10][10],avail[10],finish[10],count=0,found,safeseq[10];
    printf("Enter the number of processes ");
    scanf("%d",&p);
    printf("Enter the number of resources ");
    scanf("%d",&r);
    printf("Enter the allocation matrix - \n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("\nEnter the max matrix - \n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("\nEnter the available matrix - \n");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);
    printf("\nThe need matrix is - \n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<p;i++)
        finish[i]=0;
    while(count<p)
    {
        found=0;
        for(i=0;i<p;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>avail[j])
                        break;
                }
                if(j==r)
                {
                    for(k=0;k<r;k++)
                        avail[k]+=alloc[i][k];
                    found=1;
                    safeseq[count++]=i;
                    finish[i]=1;
                }
            }
        }
        if(found==0)
        {
            printf("\nSystem is Not safe");
            return 0;
        }
    }
    printf("\nSystem is in safe state");
    printf("\nSafe sequence is - ");
    for(i=0;i<p;i++)
        printf("P%d ",safeseq[i]+1);
    return 0;
}
