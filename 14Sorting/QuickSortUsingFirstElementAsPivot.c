#include<stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[],int low,int high)
{
    int i=low+1,j=high,pivot;
    pivot=A[low];
    do
    {
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
            swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[low],&A[j]);
    return j;
}

void quickSort(int A[],int low,int high)
{
    int partitionIndex;
    if(low<high)
    {
        partitionIndex=partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

    quickSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}


// #include<stdio.h>

// void swap(int *x,int *y)
// {
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }

// int partition(int A[],int low,int high)
// {
//     int i=low,j=high,pivot;
//     pivot=A[low];
//     do
//     {
//         do
//         {
//             i++;
//         }while(A[i]<=pivot);
//         do
//         {
//             j--;
//         }while(A[j]>pivot);
//         if(i<j)
//             swap(&A[i],&A[j]);
//     }while(i<j);

//     swap(&A[low],&A[j]);
//     return j;
// }

// void quickSort(int A[],int low,int high)
// {
//     int partitionIndex;
//     if(low<high)
//     {
//         partitionIndex=partition(A,low,high);
//         quickSort(A,low,partitionIndex);
//         quickSort(A,partitionIndex+1,high);
//     }
// }

// int main()
// {
//     int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

//     quickSort(A,0,n);
//     for(i=0;i<n;i++)
//         printf("%d ",A[i]);
//     printf("\n");
//     return 0;
// }