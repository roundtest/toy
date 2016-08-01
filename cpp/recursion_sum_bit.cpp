#include <stdio.h>

int AND(int x,int y)
{
	return x&y;
}

int XOR(int x,int y)
{
	return x^y;
}

int NOT(int x)
{
	return ~x;
}

int SHL(int x,int y)
{
	return x<<y;
}

int SHR(int x,int y)
{
	return (unsigned)x>>(unsigned)y;
}

int _not(int x)
{
	if(x)
		return 0;
	return 1;
}

int add(int x,int y)
{
	while(1)
	{
		int a=AND(x,y);
		int b=XOR(x,y);
		x=SHL(a,1);
		y=b;
		if(_not(a))
			return b;
	}
}

int neg(int x)
{
	return add(NOT(x),1);
}

int sub(int x,int y)
{
	return add(x,neg(y));
}

int _and(int x,int y)
{
	if(_not(x))
		return 0;
	if(y)
		return 1;
	return 0;
}

int _or(int x,int y)
{
	if(x)
		return 1;
	if(y)
		return 1;
	return 0;
}

int less(int x,int y)
{
	x=sub(x,y);
	return SHR(x,31);
}

int equ(int x,int y)
{
	if(XOR(x,y))
		return 0;
	return 1;
}

int less_equ(int x,int y)
{
	return _or(less(x,y),equ(x,y));
}

int mul(int x,int y)
{
	int m=1;
	int z=0;
	if(less(x,0))
	{
		x=neg(x);
		y=neg(y);
	}
	while(_and(less_equ(m,x),y))
	{
		if(AND(x,m))
			z=add(y,z);
		y=SHL(y,1);
		m=SHL(m,1);
	}
	return z;
}

int div(int x,int y)
{
	int c=0;
	int sign=0;
	if(less(x,0))
	{
		x=neg(x);
		sign=XOR(sign,1);
	}
	if(less(y,0))
	{
		y=neg(y);
		sign=XOR(sign,1);
	}
	if(y)
		while(less_equ(y,x))
		{
			x=sub(x,y);
			c=add(c,1);
		}
	if(sign)
		c=neg(c);
	return c;
}

void print(int a)
{
	printf("%d\n",a);
}

int main()
{
	print(add(3,4));
	print(add(19,29999));
	
	print(sub(-1,3));
	print(sub(19,2345));
	
	print(mul(99,98));
	print(mul(-29,235));
	
	print(div(99,98));
	print(div(9,3));
	print(div(-9,3));
	print(div(8,3));
	
	return 0;
}