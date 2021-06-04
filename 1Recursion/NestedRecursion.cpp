//Recursive call as parameter inside another recurisive call.
#include<stdio.h>
int fun(int n)
{
    if(n>100)
        return n-10; 
    return fun(fun(n+11));//First inner recursive call will run completely then outer recursive call will run, 
                          //having parameter value as inner call output.
}

int main()
{
    int r;
    r=fun(95);
    printf("%d",r);
    return 0;
}