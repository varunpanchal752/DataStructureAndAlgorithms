#include<stdio.h>

int main()
{
    int A[10]={5,8,3,9,6,2,10,7,-1,4};
    int n=10,i;
    int max=A[0],min=A[0];

    for(i=1;i<n;i++)
    {
        if(A[i]<min)
            min=A[i];
        else if(A[i]>max)
            max=A[i];
    }
    printf("max=%d \nmin=%d",max,min);
    return 0;
}