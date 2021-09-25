#include<stdio.h>

int main()
{
    int A[10]={1,3,4,5,6,8,9,10,12,14};
    int n=10,i,j,k=10;
    i=0;
    j=n-1;

    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            printf("%d + %d = %d\n",A[i],A[j],k);
            i++;
            j--;
        }
        else if(A[i]+A[j]<k)
            i++;
        else
            j--;
    }
    return 0;
}