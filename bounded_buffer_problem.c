#include <stdio.h>
#include <stdlib.h>
int empty; //counts the empty cells in the array, intially p i.e size of array
int full=0;//counts filled cells intially 0
int mutex=1;//1 = open and 0 close
int p;//size of array
int buff[100];//buffer array where data is stored

int x=-1;//for indexing
void producer()
{
    if(mutex==1&&empty!=0)//check if the buffer have empty space
    {
    --mutex;//lock acquierd
    ++full;
    --empty;
    x++;//for first item x now points to 0th index
    printf("INDEX %d INPUT ",x);
    scanf("%d",&buff[x]);
    ++mutex;//unlock
    
     
}
    else if(mutex==0){printf("WAIT!!");exit(0);}
    else if(empty==0){printf("BUFFER IS FULL");exit(0);}
}
void consumer()
{
    if(mutex==1&&full!=0)
    {
        --mutex;
        --full;
 
    ++empty;
    printf("\nConsumer consumes item %d which is %d",x, buff[x]);
    x--;
 
    ++mutex;
    }
    
    else if(mutex==0){printf("WAIT!!");exit(0);}
    else if(full==0){printf("BUFFER IS EMPTY");exit(0);}
}
int main() {
    // Write C code here
    int n, j;
    scanf("%d",&p);//p size of array
    empty=p;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
 

 
    for (j = 1; j > 0; j++) {
 
        printf("\nEnter your choice:");
        scanf("%d", &n);
 
        // Switch Cases
        switch (n) {
        case 1:
 
                producer();
           
            break;
 
        case 2:
                consumer();
            break;
 
        // Exit Condition
        case 3:
            exit(0);
            break;
        }
    }
    
    return 0;
}