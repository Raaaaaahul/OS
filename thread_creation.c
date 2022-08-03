#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* call(void *arg)
{
    pthread_detach(pthread_self());
    printf("inside the desired threadn\n");
    pthread_exit(0);
}
void fun()
{
    pthread_t x;
    pthread_create(&x,NULL,&call,NULL);
    printf("this statement maybe printed before the thread terminates\n");
    if(pthread_equal(x,pthrad_self()))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    printf("this statement may be printed after the thread terminates\n");
    pthread_join(x,NULL);
    pthread_exit(0);
    
}