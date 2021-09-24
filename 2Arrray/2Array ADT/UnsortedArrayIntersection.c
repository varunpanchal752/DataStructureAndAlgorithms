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

struct Array* UnsortedIntersection(struct Array *arr1,struct Array *arr2)
{   
    int k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    int flag;
    for(int i=0;i<arr1->length;i++)
    {
        flag=0;
        for(int j=0;j<arr2->length;j++)
        {
            if(arr1->A[i]==arr2->A[j])
                flag=1;
        }
        if(flag==1)
            arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    return arr3;
}

int main(){
    struct Array arr1={{3,5,10,4,6},5,10}, arr2={{12,4,7,2,5},5,10};
    struct Array *arr3;
    arr3=UnsortedIntersection(&arr1,&arr2);
    display(*arr3);
    return 0;
}