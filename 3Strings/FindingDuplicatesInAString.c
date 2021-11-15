#include<stdio.h>

int main()
{
    char A[]="finding";
    int i=0,j,count;

    while(A[i]!='\0')
    {
        count=1;
        j=i+1;
        while(A[j]!='\0')
        {
            if(A[j]=='0')
            {
                j++;
                continue;
            }
            else if(A[j]==A[i])
            {
                count++;
                A[j]='0';
            }
            j++;
        }
        if(count>1)
        {
            printf("%c is present %d times\n",A[i],count);
        }
        i++;
    }
    return 0;
}