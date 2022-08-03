#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
    char name[100];
    DIR *dptr;
    struct dirent *dirp;
    printf("enter the name of the directory\n");
    scanf("%s",name);
    if((dptr=opendir(name))==NULL)
    {
        printf("directory enter the exist\n");exit(0);
    }
    while(dirp=opendir(dptr))
    {
        printf("\n%s ",dirp->d_name);
    }
    closedir(dptr);
    return 0;
}