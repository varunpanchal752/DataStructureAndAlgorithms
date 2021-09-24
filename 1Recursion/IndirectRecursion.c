//In this one function is calling another function and then that called function is also calling another function. 
//So here a cycle is made and thus recursion is happening
#include<stdio.h>
void funB(int n);

void funA(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funB(n-1);
    }
}

void funB(int n)
{
    if(n>1)
    {
        printf("%d ",n);
        funA(n/2);
    }
}

int main()
{
    funA(20);
    return 0;
}