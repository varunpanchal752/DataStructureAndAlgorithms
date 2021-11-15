#include<stdio.h>
#include<stdlib.h>
struct ArrayADT
{
    int *A;
    int size;
    int length;
};
int display(struct ArrayADT arr)
{
    int i;
    printf("\nElements are: ");
    for(i =0 ;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    return 0;
}
int main()
{
    struct ArrayADT arr;
    int i,n;
    printf("Enter the size of an array: ");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));

    printf("\nEnter the number of numbers: ");
    scanf("%d",&n);
    arr.length=n;
    printf("\nEnter all Elements:\n");
    for(i=0;i<n;i++)
    {   
        scanf("%d",&arr.A[i]);        
    }
    display(arr);
    return 0;
}