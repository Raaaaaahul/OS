#include<stdio.h>
#include<stdbool.h>
int main()
{
    int n;
    printf("enter the number of process\n");
    scanf("%d",&n);
    int process[n];
    for(int i=0;i<n;i++)
    {
        process[i] = i+1;
    }
    int burst_time[n] , waiting_time[n] , turnaround_time[n];
    int quant,twt=0,tat=0;
    printf("enter burst time of each process\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst_time[i]);
    }
    printf("\n enter the quant time \n");
    scanf("%d",&quant);
    int temp[n];//temporary variable 

    for(int i=0;i<n;i++)
    {
        temp[i] = burst_time[i];//copying values of burst time into temp array
    }
        int t=0;
    while (1) 
    {
        bool done = true;
        for (int i = 0 ; i < n; i++) 
      {
        if (temp[i] > 0) 
         {
            done = false;
            if (temp[i] > quant) 
            {
               t += quant;
                temp[i] -= quant;
            }
            else {
               t = t + temp[i];
               waiting_time[i] = t - burst_time[i];
               temp[i] = 0;
            }
         }
      }
      if (done == true)
         break;
   }
   printf("\nwaiting time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",waiting_time[i]);
    }
    for(int i=0;i<n;i++)
    {
        turnaround_time[i] = burst_time[i]+waiting_time[i];
    }
    printf("\n turn around time of each process \n");
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",turnaround_time[i]);
    }
    return 0;
}