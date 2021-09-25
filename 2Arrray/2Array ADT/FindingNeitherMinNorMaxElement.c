#include<stdio.h>

int main()
{
    int A[7]={5,2,8,7,12,1,17};
    int i,max,min;
    max=A[0];
    min=A[0];

    for(i=0;i<3;i++)
    {
        if(min>A[i])
            min=A[i];
        else if(max<A[i])
            max=A[i];
    }

    for(i=0;i<3;i++)
    {
        if(A[i]!=min && A[i]!=max)
            printf("Element which is neither minimum nor maximum is: %d",A[i]);
    }
    return 0;
}