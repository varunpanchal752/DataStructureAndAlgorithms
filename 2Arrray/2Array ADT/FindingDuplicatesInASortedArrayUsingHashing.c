#include<stdio.h>

int main()
{
    int A[10]={3,6,8,8,10,12,15,15,15,20};      
    int H[21]={0};
    int i,n=10,max=21;
    for(i=0;i<n;i++)
    {
        H[A[i]]++;
    }      
    for(i=0;i<=max;i++)
    {
        if(H[i]>1)
            printf("\n%d is %d times",i,H[i]);
    }
    return 0;
}