#include <stdio.h>
#include <algorithm>

int f(int n,std::function<int(int,int)> k)
{
	if(n<=1)
	{
		return 1;
	}
	return k(n,f(n-1,k));
}

int main()
{
	printf("%d\n",f(10,[](int a,int b)->int{
		return a+b;
	}));

	printf("%d\n",f(10,[](int a,int b)->int{
		return a*b;
	}));
	return 0;
}