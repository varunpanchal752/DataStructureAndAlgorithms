#include<stdio.h>

int main()
{
    int A[]={1,2,3,4,5,6,8,9,10,11,12};
    int sum=0,i,s=0,n=11;
    for(i=0;i<n-1;i++)
    {
        sum+=A[i];
    }
    s=(n*(n+1))/2;
    if (s-sum)
        printf("Missing No is %d",s-sum);
    return 0;
}