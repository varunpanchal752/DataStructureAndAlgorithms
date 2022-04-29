#include<stdio.h>

//Max heap
void insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];

    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int delete(int A[],int n)
{
    int i=1,j=2*i,val=A[1];
    A[1]=A[n];

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            ++j;
        if(A[i]<A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j;
            j=2*j;
        }
        else
            break;
    }
    A[n]=val;
    return val;
}

int main()
{
    int A[]={0,10,20,30,25,5,40,35};
    int i;

    for(i=2;i<=7;i++)
        insert(A,i);
    for(i=1;i<=7;i++)
        printf("%d ",A[i]);

    printf("\nDeleting elements and Heap Sort : ");
    for(i=7;i>1;i--)
    {
        delete(A,i);
    }
    printf("\n");
    
    for(i=1;i<=7;i++)
        printf("%d ",A[i]);

    return 0;
}