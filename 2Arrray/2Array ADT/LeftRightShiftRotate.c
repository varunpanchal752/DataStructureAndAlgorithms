#include<stdio.h>
#include<stdlib.h>
struct Array{
    int A[10];
    int length;
    int size;
};
void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void leftshift(struct Array *arr)
{
    int temp=arr->A[0];
    for(int i=0;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
}

void leftrotate(struct Array *arr)
{
    int temp=arr->A[0];
    for(int i=0;i<arr->length-1;i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=temp;
}

void rightshift(struct Array *arr)
{
    int temp=arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=0;
}

void rightrotate(struct Array *arr)
{
    int temp=arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=temp;
}

int main(){
    struct Array arr={{2,3,4,5,6},5,10};
    display(arr);
    rightrotate(&arr);
    display(arr);
    return 0;
}