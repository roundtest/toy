#include <stdio.h>

template<class T>
T add(T a,T b)
{
	return a+b;
}

int main()
{
	printf("%d\n",add<int>(1,2));
	printf("%f\n",add<double>(1.5,2.2));
	return 0;
}