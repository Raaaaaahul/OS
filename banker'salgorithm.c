#include<stdio.h>
int m,n,i,j,al[10][10],max[10][10],av[10],need[10][10],temp,z,y,p,k;
void main()
{
    printf("enter the number of process : ");
    scanf("%d",&m);
    printf("enter the number of resources : ");
    scanf("%d",&n);
    //getting input for allocation matrix
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n enter instances for al[%d][%d] = ",i,j);
            scanf("%d",&al[i][j]);//allocation matrix
        }
    }
    //getting input for max matrix
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n enter instances for max[%d][%d] = ",i,j);
            scanf("%d",&max[i][j]);//max  matrix
        }
    }
    //getting input for available array
    for(i=0;i<n;i++)
    {
        printf("\n Available resource for av[%d] = ",i);
        scanf("%d",&av[i]);
    }
        //availabe array
    //printing allocation values
    printf("allocation matrix : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            
            printf("  %d",al[i][j]);//allocation matrix
        }
        printf("\n");
    }
    printf("\n\n");
    
    printf("max matrix : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("  %d",max[i][j]);//allocation matrix
        }
        printf("\n");
    }
    printf("\n\n");
    
    //need values
    printf("NEED VALUES : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            need[i][j] = max[i][j] - al[i][j];
            printf("\t %d",need[i][j]);
        }
        printf("\n");
    }
    //for terminating the processṇ
    p=1;
    y=0;
    while(p!=0)
    {
        for(i=0;i<m;i++)
        {
            z=0;
            for(j=0;j<n;j++)
            {
                if(need[i][j]<=av[j] && (need[i][0]!=-1))
                  {
                    z++;
                  }  
            }
            if(z==n)
            {
                for(k=0;k<n;k++)
                {
                    av[k]+=al[i][j];
                }
                printf("\n SS process %d",i);
                need[i][0]=-1;
                y++;
            }
        }
        if(y==m){
            p=0;
        }
        
    }
}

//enter the allocation matrix
//enter  the max matrix
// enter the available array
//calculate the need matrix using max[i][j] -  al[i][j]
//terminate the process using the extra variable p,k,z,y