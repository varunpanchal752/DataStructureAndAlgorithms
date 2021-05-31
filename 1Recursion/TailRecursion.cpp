#include <stdio.h>
void fun(int n)
{
    if(n>0)
    {
        //Recursive function is at last and all other statements are above it
        printf("%d ",n);
        fun(n-1);
    }
}

int main() 
{
    int x=3;
    fun(x);
    return 0;
}