#include<stdio.h>

int main()
{
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int H[9]={0},i;
    int max=9,n=10;
    for(i=0;i<n;i++)
    {
        H[A[i]]++;
        
    }
    for(i=0;i<max;i++)
    {
        if(H[i]>1)
            printf("%d is %d times\n",i,H[i]);
    }
    return 0;
}