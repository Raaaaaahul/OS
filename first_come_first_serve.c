#include<stdio.h>
#include<unistd.h>
int main()
{
int p[5],waiting_time[5],tt[5],swt=0,stt=0,avgwt,avgtat;
int buzz_time[]={10,15,12,17,29};
int i;
waiting_time[0]=0;
for(i=1;i<5;i++)
{
waiting_time[i]=waiting_time[i-1]+buzz_time[i-1];
printf("WAITING TIME OF PROCESS %d is %d\n",i,waiting_time[i]);
swt+=waiting_time[i];
}
for(i=0;i<5;i++)
{
tt[i]=waiting_time[i]+buzz_time[i];
printf("TURN AROUND TIME OF PROCESS %d is %d\n",i,tt[i]);
stt+=tt[i];
}
printf("AVERAGE WAITING TIME IS = %d\n",swt/5);
printf("AVERAGE TURN AROUND TIME IS = %d\n",stt/5);
return 0;
}