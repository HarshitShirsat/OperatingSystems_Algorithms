#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n,f,ref[20],frame[10],found,victim=-1,pf=0;
    printf("Enter the number of pages - ");
    scanf("%d",&n);
    printf("Enter the number of frames - ");
    scanf("%d",&f);
    printf("Enter the reference string - ");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    printf("\nFIFO\n");
    printf("The reference string is - \n");
    for(i=0;i<n;i++)
        printf("%d ",ref[i]);
    printf("\n");
    for(i=0;i<f;i++)
        frame[i]=-1;
    for(i=0;i<n;i++)
    {
        found=0;
        for(j=0;j<f;j++)
        {
            if(frame[j]==ref[i])
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            pf++;
            victim=(victim+1)%f;
            frame[victim]=ref[i];
        }
        printf("%d --> ",ref[i]);
        for(j=0;j<f;j++)
            printf("%d ",frame[j]);
        if(found==0)
            printf("\tPage Miss");
        else
            printf("\tPage Hit");
        printf("\n");
    }
    printf("\nTotal page faults are - %d",pf);
    return 0;
}
