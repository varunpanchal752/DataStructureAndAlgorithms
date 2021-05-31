#include <stdio.h>
//Same output as static variable 
int x=0;
int fun(int n)
{
    if(n>0) 
    { 
        x++;
        return fun(n-1)+x;//Adding value of x on returning time
    }
    return 0;
}

int main() 
{
    int r;
    r=fun(5);
    printf("%d\n",r);
 
    r=fun(5);
    printf("%d\n",r);
 
    return 0;
}