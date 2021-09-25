#include<stdio.h>

int main()
{
    int A[]={6,7,8,9,11,12,15,16,17,18,19};
    int diff,i,n=11;
    diff=A[0]-0;
    for(i=0;i<n;i++)
    {
        if(A[i]-i!=diff)
        {
            while(diff<A[i]-i)
            {
                printf("%d\n",i+diff);
                diff++;
            }
        }
    }    
    return 0;
}