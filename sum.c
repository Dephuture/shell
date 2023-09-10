#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	int sum = 0;
	printf("ac : %d", ac);
	printf("av[] values\n:");

	for(i = 1; i < ac; i++)
	{
		printf("av[%d] = %s\n", i , av[i]);
		sum += atio(av[1]);
	}
	return(sum);
}
