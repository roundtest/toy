#include <stdio.h>

int f(int n,int b)
{
	if(n<=1)
		return 1;
	if(b)
		return n+f(n-1,b);
	else
		return n*f(n-1,b);
}

int main()
{
	printf("%d\n",f(10,1));
	printf("%d\n",f(10,0));
	return 0;
}