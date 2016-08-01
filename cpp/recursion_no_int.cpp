#include <stdio.h>

struct A
{
	float m;
	
	A(float a)
	{
		m=a;
	}
	
	A(const A& a)
	{
		m=a.m;
	}
	
	friend A operator+(A a,A b)
	{
		return a.m+b.m;
	}
	
	friend A operator-(A a,A b)
	{
		return a.m-b.m;
	}
	
	friend A operator<=(A a,A b)
	{
		return a.m<=b.m;
	}
};

A f(A n)
{
	//the return value of n<=1 also can be bool, so don't need ".m"
	if((n<=1).m)
	{
		return 1;
	}
	return n+f(n-1);
}

//only the return value of main is int, this is the defined by g++
int main()
{
	printf("%.0f\n",f(10).m);
	return 0;
}