#include<stdio.h>

int main()
{
    char A[]="finding";
    int H[26]={0},i=0;
    
    while(A[i]!='\0')
    {
        H[A[i]-97]++;
        i++;
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
            printf("%c is appearing %d times\n",i+97,H[i]);
    }
    
    return 0;
}