#include <stdio.h>

int main()
{
	int sum=0;
	int i=1;
start:
	if(i>10)
		goto end;
	sum=sum+i;
	i=i+1;
	goto start;
end:
	printf("%d",sum);

	return 0;
}