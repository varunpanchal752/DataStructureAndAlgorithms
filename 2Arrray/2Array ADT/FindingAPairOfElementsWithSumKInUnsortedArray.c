#include<stdio.h>

int main()
{
    int A[10]={6,3,8,10,16,7,5,2,9,14};
    int i,k=10,j;
    int max=17,n=10;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]+A[j]==k)
                printf("%d + %d = %d\n",A[i],A[j],k);
        }
    }
    return 0;
}