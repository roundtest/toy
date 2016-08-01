#include <stdio.h>

int f(int n)
{
	int sum=0;
	for(int i=1;i<=n;i=i+1)
	{
		sum=sum+i;
	}
	return sum;
}

int main()
{
	printf("%d",f(10));
	return 0;
}