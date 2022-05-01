#include<stdio.h>

void bubbleSort(int A[],int n)
{
    int i,j,temp,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    bubbleSort(A,n);

    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}