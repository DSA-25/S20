#include<stdio.h>
void quicksort(int x[],int lb,int ub);
int partition(int x[],int lb,int ub);

void main()
{
    int i,n,lb,ub;
    printf("enter no of values");
    scanf("%d",&n);
    int x[n];
    printf("enter the values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    lb=0;
    ub=n-1;
    quicksort(x,lb,ub);

    printf("The sortred array is:");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",x[i]);
    }  
}

void quicksort(int x[],int lb,int ub)
{
    int j;
    if (lb<ub)
    {
        j=partition(x,lb,ub);
        quicksort(x,lb,j-1);
        quicksort(x,j+1,ub);
    }
    
}

int partition(int x[],int lb,int ub)
{
    int pivot ,i,j,temp;
    i=lb+1;
    j=ub;
    pivot=x[lb];

    do
    {
        if (x[i]<=pivot && i<=ub)
        {
            i++;
        }
        if (x[j]>pivot && j>lb)
        {
            j--;
        }
        if (i<j)
        {
            temp=x[i];
            x[i]=x[j];
            x[j]=temp;
        }
    } while (i<j);
    x[lb]=x[j];
    x[j]=pivot;
    return j;
}