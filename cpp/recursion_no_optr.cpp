#include <stdio.h>

int add(int a,int b)
{
	__asm__ volatile("addl %%ebx,%%eax":"=a"(a):"a"(a),"b"(b));
	return a;
}

int sub(int a,int b)
{
	__asm__ volatile("subl %%ebx,%%eax":"=a"(a):"a"(a),"b"(b));
	return a;
}

int less_equ(int a,int b)
{
	__asm__ volatile("cmpl %%ebx,%%eax;movl $0,%%eax;setle %%al":"=a"(a):"a"(a),"b"(b));
	return a;
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
	printf("%d\n",add(555,99));
	printf("%d\n",sub(555,99));
	printf("%d\n",less_equ(555,99));
	printf("%d\n",less_equ(98,99));
	printf("%d\n",less_equ(99,99));
	printf("%d\n",f(10));
	return 0;
}