#include<stdio.h>
#include<stdlib.h>

int n,f,ref[30],frame[30],optindex[30],pf=0;

int optimal(int index)
{
    int pos,max,i,j;
    int found;
    for(i=0;i<f;i++)
    {
        found=0;
        for(j=index+1;j<n;j++)
        {
            if(ref[j]==frame[i])
            {
                found=1;
                optindex[i]=j;
                break;
            }
        }
        if(found==0)
        {
            return i;
        }
    }
    max=optindex[0];
    pos=0;
    for(j=1;j<f;j++)
    {
        if(optindex[j]>max)
        {
            max=optindex[j];
            pos=j;
        }
    }
    return pos;
}

int main()
{
    int victim=-1,count=0,i,j,found;
    printf("Enter the number of pages - ");
    scanf("%d",&n);
    printf("Enter the number of frames - ");
    scanf("%d",&f);
    printf("Enter the reference string - ");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    printf("\nOPTIMAL\n");
    printf("The reference string is - \n");
    for(i=0;i<n;i++)
        printf("%d ",ref[i]);
    printf("\n");
    for(i=0;i<f;i++)
    {
        frame[i]=-1;
        optindex[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        found=0;
        for(j=0;j<f;j++)
        {
            if(ref[i]==frame[j])
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            count++;
            if(count<=f)
            {
                victim++;
            }
            else
            {
                victim=optimal(i);
            }
            pf++;
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
    printf("\nNo of page faults:%d\n",pf);
    return 0;
}
