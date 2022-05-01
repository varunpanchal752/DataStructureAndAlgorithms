#include<stdio.h>

void insertionSort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=A[i];
        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

    insertionSort(A,n);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}