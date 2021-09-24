#include <stdio.h>
void fun(int n)
{
    if(n>0)
    {
        //Recursive function is above all other statements
        fun(n-1);
        printf("%d ",n);
    }
}

int main() 
{    
    int x=3;
    fun(x);
    return 0;
}