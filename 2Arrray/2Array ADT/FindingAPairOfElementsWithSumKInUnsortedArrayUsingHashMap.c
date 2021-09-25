#include<stdio.h>

int main()
{
    int A[10]={6,3,8,10,16,7,5,2,9,14};
    int H[17]={0};
    int n=10,i,k=10;
    
    for(i=0;i<n;i++)
    {k
        if(k-A[i]>0)
        {
            if(H[k-A[i]]>0)
                printf("%d + %d = %d\n",A[i],k-A[i],k);
            H[A[i]]++;
        }
    }
    return 0;
}