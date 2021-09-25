#include<stdio.h>

int main()
{
    int A[]={6,7,8,9,10,11,13,14,15,16,17};
    int diff,l=A[0],n=11,i;
    diff=l-0;
    for(i=0;i<n;i++)   
    {
        if(A[i]-i!=diff)
        {
            printf("Missing element is %d\n",i+diff);
            break;
        }
    }
    return 0;
}