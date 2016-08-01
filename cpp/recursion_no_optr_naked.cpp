#include <stdio.h>

int add(int a,int b) __attribute__((naked))
{
	__asm__(
		"movl 4(%esp),%eax;"
		"addl 8(%esp),%eax;"
		"ret;"
	);
}

int sub(int a,int b) __attribute__((naked))
{
	__asm__(
		"movl 4(%esp),%eax;"
		"subl 8(%esp),%eax;"
		"ret;"
	);
}

int less_equ(int a,int b) __attribute__((naked))
{
	__asm__(
		"movl 4(%esp),%eax;"
		"cmpl 8(%esp),%eax;"
		"movl $0,%eax;"
		"setle %al;"
		"ret;"
	);
}

int f(int n)
{
	if(less_equ(n,1))
	{
		return 1;
	}
	return add(n,f(sub(n,1)));
}

int main()
{
	printf("%d\n",f(10));
	return 0;
}