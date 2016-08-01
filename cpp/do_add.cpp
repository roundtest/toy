#include <stdio.h>

int sub1(int a)
{
	return a-1;
}

int add1(int a)
{
	return a+1;
}

int add(int a,int b)
{
	if(b==0)
		return a;
	return add1(add(a,sub1(b)));
}

int sub(int a,int b)
{
	if(b==0)
		return a;
	return sub1(sub(a,sub1(b)));
}

int mul(int a,int b)
{
	if(b==0)
		return 0;
	return add(a,mul(a,sub1(b)));
}

int main()
{
	printf("%d\n",add(5,6));
	printf("%d\n",sub(8,3));
	printf("%d\n",mul(5,3));
	return 0;
}