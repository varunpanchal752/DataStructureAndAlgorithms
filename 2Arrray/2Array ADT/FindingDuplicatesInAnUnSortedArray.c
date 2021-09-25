#include<stdio.h>

int main()
{
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int i,j,count,n=10;
    for(i=0;i<n-1;i++)
    {
        count =1;
        if(A[i]!=-1)
        {
            for(j=i+1;j<n;j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j]=-1;
                }
            }
        }
        if(count>1)
            printf("%d is %d times\n",A[i],count);
    }   
    return 0;
}