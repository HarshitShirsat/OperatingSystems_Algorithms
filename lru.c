#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n,f,frame[30],count[30],ref[30],time=0,free,found,pf=0,pos=0,min,index;

    printf("Enter the number of pages - ");
    scanf("%d",&n);
    printf("Enter the number of frames - ");
    scanf("%d",&f);
    free=f;
    printf("Enter the reference string - ");
    for(i=0;i<n;i++)
        scanf("%d",&ref[i]);
    printf("\nLRU\n");
    printf("The reference string is - \n");
    for(i=0;i<n;i++)
        printf("%d ",ref[i]);
    printf("\n");
    for(i=0;i<f;i++)
    {
        count[i]=0;
        frame[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        found=0;
        for(j=0;j<f;j++)
        {
            if(ref[i]==frame[j])
            {
                found=1;
                count[j]=time;
                break;
            }
        }
        if(found==0)
        {
            if(free)
            {
                frame[pos]=ref[i];
                pf++;
                free--;
                count[pos]=time;
                pos++;
            }
            else
            {
                min=count[0];
                index=0;
                for(j=1;j<f;j++)
                {
                    if(min>count[j])
                    {
                        index=j;
                        min=count[index];
                    }
                }
                count[index]=time;
                frame[index]=ref[i];
                pf++;
            }
        }
        time++;
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
