#include <stdio.h>
int fun(int n)
{
    //Only one x in whole program 
    static int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;//x is added on returning time and adding is started when last fun(0) is executed completely
    }
    return 0;
}

int main() 
{
    int r;
    // Both fun(5) calls uses same variable x 
    r=fun(5);
    printf("%d\n",r);
 
    r=fun(5);
    printf("%d\n",r);

    return 0;
}