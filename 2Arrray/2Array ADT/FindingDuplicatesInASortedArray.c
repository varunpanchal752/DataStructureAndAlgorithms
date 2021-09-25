#include<stdio.h>

int main()
{
    int A[]={3,6,8,8,10,12,15,15,15,20};
    int i,n=10,LastDuplicate=0;
    for(i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1] && A[i]!=LastDuplicate)
        {
            printf("%d\n",A[i]);
            LastDuplicate=A[i];
        }
    }
    return 0;
}