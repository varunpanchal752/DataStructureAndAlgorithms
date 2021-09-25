#include<stdio.h>

int main()
{
    int A[]={3,7,4,9,12,6,1,11,2,10};
    int i,n=10,l=1,h=12;//l->smallest element , h->Largest element in the array
    int H[h];
    for(i=0;i<h;i++)
    {
        H[i]=0;
    }   
    for(i=0;i<n;i++)
    {
        H[A[i]]++;
    }   
    for(i=l;i<=h;i++)
    {
        if(H[i]==0)
            printf("%d\n",i);
    }
    return 0;
}