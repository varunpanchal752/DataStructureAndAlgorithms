#include<stdio.h>

int merge(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int B[100];
    while(i<=mid && j<=high){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }

    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=high;j++)
        B[k++]=A[j];
    
    for(i=low;i<=high;i++)
        A[i]=B[i];

    return j;
}

void rMergeSort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        rMergeSort(A,low,mid);
        rMergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

    rMergeSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

