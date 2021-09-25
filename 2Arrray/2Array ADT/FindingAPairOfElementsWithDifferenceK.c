#include<stdio.h>

int main()
{
    int A[4]={1,2,3,4};
    int i,j,n=4,diff=3;
    i=0;
    j=1;

    while(j<n)
    {
        if(A[j]-A[i]<diff)
            j++;
        else if(A[j]-A[i]==diff)
        {
            printf("%d - %d = %d",A[j],A[i],diff);
            break;
        }    
        else 
            i++;
    }
    return 0;
}