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

void iMergeSort(int A[],int n)
{
    int p,i,low,mid,high;
    for(p=2;p<=n;p*=2)
    {
        for(i=0;i+p-1<n;i+=p)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            merge(A,low,mid,high);
        }
        if(n-i>p/2)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            merge(A,low,mid,n-1);
        }
    }
    //Merge last 2 remaining sorted lists
    if(p/2<n)
        merge(A,0,p/2-1,n-1);
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3,11,2,22,4},n=14,i;

    iMergeSort(A,n);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

