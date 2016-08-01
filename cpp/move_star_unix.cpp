#include <stdio.h>
#include <unistd.h>

int main()
{
	while(1)
	{
		printf("\b *");
		fflush(stdout);
		usleep(100000);
	}
	return 0;
}