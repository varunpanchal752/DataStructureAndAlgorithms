#include<stdio.h>
#include<stdlib.h>

int findMax(int A[],int n)
{
    int i,max=-32456;
    for(i=0;i<n;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    return max;
}

void countSort(int A[],int n)
{
    int max,i,j=0,*count;
    max=findMax(A,n);
    count = (int *)malloc((max+1)*sizeof(int));

    for(i=0;i<=max;i++)
        count[i]=0;

    for(i=0;i<n;i++)
        count[A[i]]++;
    
    i=0;
    while(j<max+1)
    {
        if(count[j]>0)
        {
            A[i++]=j;
            count[j]--;
        }   
        else
            j++;
    }
    free(count);
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
 
    countSort(A,n);
 
    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}