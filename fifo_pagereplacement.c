#include<stdio.h>
int main()
{
    int i,j=0,n,a[50],frame[10],no,k,avail,count=0;
    printf("enter the number of refernces for pages\n");
    scanf("%d",&n);
    printf("enter the order\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);//refrence string or order
    }
    printf("\n number of frames\n");
    
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        frame[i] = -1;
    }
    for(i=1;i<=n;i++)
    {
        avail = 0;
        for(k=0;k<no;k++)
        {
            if(frame[k]==a[i])
            {
                avail = 1;
            }
        }
            if(avail==0)
            {
                frame[j] = a[i];
                j=(j+1)%no;
                count++;
                for(k=0;k<no;k++)
                printf("%d ",frame[k]);
            }
        
        printf("\n");
    }
    printf("total page fault : %d",count);


    return 0;
}