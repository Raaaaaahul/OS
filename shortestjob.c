#include<stdio.h>
int main()
{
    int n,temp,flag;
    printf("enter the number of process\n");
    scanf("%d",&n);
    int process[n],turn_around[n],waiting[n],bt[n],avgtt=0,avgwt=0;
    waiting[0] =0;
     for(int i=0;i<n;i++)
    {
        printf("enter burst_time for the #%d process \n",i+1);
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++)
    {
        process[i] = i+1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            flag = process[i];
            process[i] = process[j];
            process[j] = flag;
            }
            
        }
    }
      for(int i=1;i<n;i++)
    {
        waiting[i] = waiting[i-1] + bt[i-1];
        printf("waiting time for the %d process = %d\n",process[i],waiting[i]);
        avgwt+=waiting[i];
    }
    for(int i=0;i<n;i++)
    {
        turn_around[i] = waiting[i] + bt[i];
        printf("turn_around time for the %d process = %d\n",process[i+1],turn_around[i]);
        avgtt+=turn_around[i];
    }
    printf("average turn around time : %d\n",avgtt/n);
    printf("average waiting time : %d\n",avgwt/n);
  
    return 0;
}