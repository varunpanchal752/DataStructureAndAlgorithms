//In Tree Recursion there are more then one recursive calls in one function
#include <stdio.h>
void fun(int n)
{
	if(n>0)
 	{
 		printf("%d ",n);
 		fun(n-1);//First this call will be executed completely , and then next fun(n-1) is will execute
 		fun(n-1);
 	}
}

int main() 
{
	fun(3);
	return 0;
}